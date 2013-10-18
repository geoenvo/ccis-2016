<?php

/**
 * Page callback to upload and import CSV files.
 */
function ccis_import_files_form($form, $form_state) {
  $form['upload'] = array(
    '#type' => 'plupload',
    '#title' => t('Upload files'),
    '#autoupload' => TRUE,
    '#autosubmit' => FALSE,
    '#submit_element' => '#edit-submit',
    '#upload_validators' => array(
      'file_validate_extensions' => array('csv'),
      'ccis_csv_file_header_validate' => array(),
      'ccis_csv_file_name_validate' => array('yearly monthly daily 10-day'),
    ),
    '#plupload_settings' => array(
      'runtimes' => 'html5',
      'chunk_size' => '1mb',
    ),
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );
  return $form;
}

/**
 * Submit handler for ccis_import_files_form().
 */
function ccis_import_files_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  if (!empty($values['upload'])) {
    $operations = array();
    foreach ($values['upload'] as $upload) {
      if ($upload['status'] == 'done') {
        $file = new stdClass();
        $file->uri = $upload['tmppath'];
        $file->filename = $upload['name'];
        $file->name = pathinfo($file->filename, PATHINFO_FILENAME);
        $operations[] = array('ccis_import_csv_file', array($file));
      }
    }
    $path = drupal_get_path('module', 'ccis');
    $batch = array(
      'operations' => $operations,
      'title' => 'Import files',
      'file' => $path . '/ccis.import.inc',
      'finished' => 'ccis_import_csv_file_finished',
    );
    batch_set($batch);
  }
}

/**
 * Batch api callback to import a csv file.
 *
 * @see ccis_import_files_form_submit
 */
function ccis_import_csv_file(stdClass $file, &$context) {
  $context['message'] = t('Importing @file', array('@file' => $file->filename));
//   $errors = ccis_csv_file_header_validate($file);

//   // Check for errors.
//   if (!empty($errors)) {
//     $message = t('The specified file %name could not be imported.', array('%name' => $file->filename));
//     if (count($errors) > 1) {
//       $message .= theme('item_list', array('items' => $errors));
//     }
//     else {
//       $message .= ' ' . array_pop($errors);
//     }
//     form_set_error('', $message);
//     return FALSE;
//   }
  try{
    $row = 1;
    $header = $end_data = array();
    $header_count = 0;
    $expected_fields = _ccis_get_weather_data_labels(FALSE);
    if (($handle = fopen($file->uri, "r")) !== FALSE) {
      while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
        if ($row == 1) {
          $data = array_map('drupal_strtolower', $data);
          $header = $data;
          $header_count = count($data);
        }
        else{
          // Empty data must be comma seperated.
          $data_count = count($data);
          if ($data_count !== $header_count) {
            continue;
          }
          $data = array_combine($header, $data);
          array_walk($data, '_ccis_round');
          $end_data[] = $data;
        }
        $row++;
      }
      fclose($handle);
    }
    $col = mongodb_collection($file->name);
    $col->drop();
    $col->batchInsert($end_data);
  }
  catch (Exception $e ) {
    watchdog_exception('ccis', $e);
  }
  $context['results'][] = $file;
}

/**
 * Finish callback for the csv import.
 *
 * @see ccis_import_csv_file
 * @see ccis_import_files_form_submit
 */
function ccis_import_csv_file_finished($success, $results, $operations) {
  // The 'success' parameter means no fatal PHP errors were detected. All
  // other error management should be handled using 'results'.
  if ($success) {
    $message = format_plural(count($results), 'One file imported.', '@count files imported.');
  }
  else {
    $message = t('Finished with an error.');
  }
  drupal_set_message($message);
}

/**
 * Validates a file that it contains the right header data.
 *
 * @see ccis_field_widget_file_generic_form_alter
 * @see ccis_import_csv_file
 *
 * @param object $file
 */
function ccis_csv_file_header_validate(stdClass $file) {
  $errors = array();
  $row = 1;
  $header = $end_data = array();
  $header_count = 0;
  $expected_fields = _ccis_get_weather_data_labels(FALSE);
  if (($handle = fopen($file->uri, "r")) !== FALSE) {
    while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
      if ($row == 1) {
        $data = array_map('drupal_strtolower', $data);
        $header = $data;
        $header_count = count($header);
        $expected_fields_count = count($expected_fields);
        if ($header_count !== $expected_fields_count) {
          $errors[] = t('Missing data in @file', array('@file' => $file->filename));
        }
        foreach ($data as $header_name) {
          if (!isset($expected_fields['field_' . $header_name])) {
            $errors[] = t('Unknown data %col in @file', array('@file' => $file->filename, '%col' => $header_name));
          }
        }
        break;
      }
    }
    fclose($handle);
  }
  return $errors;
}

/**
 * Validates the file name that contains a particular pattern and can not uploaded twice.
 *
 * @param object $file
 *   File object.
 *
 * @return array
 *   An array with the error messages.
 */
function ccis_csv_file_name_validate(stdClass $file, $pattern) {
  $errors = array();
  $pattern = preg_replace('/ +/', '|', preg_quote($pattern));
  preg_match_all('/(\w+)_(' . $pattern . ')\.csv/', $file->filename, $matches);
  $matches = array_filter($matches);
  if (empty($matches)) {
    $errors[] = t('The filename must be in this pattern <em>stationname_@pattern.csv', array('@pattern' => $pattern));
    return $errors;
  }
  return $errors;
}