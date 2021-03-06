<?php

/**
 * Page callback to upload and import CSV files.
 */
function ccis_import_files_form($form, $form_state) {
  $form['upload'] = array(
    '#type' => 'plupload',
    '#title' => t('Upload files'),
    '#autoupload' => TRUE,
    '#autosubmit' => TRUE,
    '#submit_element' => '#edit-submit',
    '#upload_validators' => array(
      'file_validate_extensions' => array('csv'),
      'ccis_csv_file_header_validate' => array(),
      'ccis_csv_file_name_validate' => array('yearly monthly daily 10_days'),
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
  try{
    $row = $round = 1;
    $header = $end_data = array();
    $header_count = 0;
//     debug('Start: ' . format_size(memory_get_usage()));
    if (($handle = fopen($file->uri, "r")) !== FALSE) {
      $col = mongodb_collection($file->name);
      $col->drop();
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
            $context['message'] .= '<br>' . t('Skipping row %row.', array('%row' => $row));
            continue;
          }
          $data = array_combine($header, $data);
          array_walk($data, '_ccis_round');
          array_walk($data, '_ccis_fix_interger');
          $end_data[] = $data;
        }
        /**
         * 45.000 rows/2000 each '338.53 KB'/'23: 59.47 MB'
         */
        if ($count = count($end_data) >= 3000) {
          $col->batchInsert($end_data);
//           debug($round . ': ' . format_size(memory_get_usage()));
//           debug( format_size(mb_strlen(serialize($end_data), '8bit')));
          $end_data = array();
          $round++;
        }
        $row++;
      }
      fclose($handle);
      if (!empty($end_data)) {
        $col->batchInsert($end_data);
//         debug($round . ': ' . format_size(memory_get_usage()));
//         debug( format_size(mb_strlen(serialize($end_data), '8bit')));
        $end_data = array();
      }
    }
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
  $expected_fields = _ccis_get_weather_data_labels(FALSE);
  if (($handle = fopen($file->uri, "r")) !== FALSE) {
    while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
      if ($row == 1) {
        $data = array_map('drupal_strtolower', $data);
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
  $regex = '/(' . $pattern . ').csv$/i';
  if (!preg_match($regex, $file->filename)) {
    $errors[] = t('The filename must be in this pattern <em>STADTIONID_@pattern.csv. Example 41_daily.csv.', array('@pattern' => $pattern));
    return $errors;
  }
  return $errors;
}

/**
 * Page callback to upload and import XML files.
 */
function ccis_xml_import_files_form($form, &$form_state) {
  form_load_include($form_state, 'inc', 'feeds', 'feeds.pages');
  $importer_id = 'weather_station';
  $source = feeds_source($importer_id, 0);
  $form['upload'] = array(
    '#type' => 'plupload',
    '#title' => t('Upload files'),
    '#autoupload' => TRUE,
    '#autosubmit' => TRUE,
    '#submit_element' => '#edit-submit',
    '#upload_validators' => array(
      'file_validate_extensions' => array('xml'),
    ),
    '#plupload_settings' => array(
      'runtimes' => 'html5',
      'chunk_size' => '1mb',
    ),
  );
  $form['source_status'] = array(
    '#type' => 'fieldset',
    '#title' => t('Status'),
    '#tree' => TRUE,
    '#value' => feeds_source_status($source),
  );
  $form['#xmldir'] = 'private://weatherstation';
  $source_form = $source->configForm($form_state);
  if (!empty($source_form)) {
    $form['feeds'] = array(
      '#type' => 'fieldset',
      '#title' => t('Import'),
      '#tree' => TRUE,
      '#access' => FALSE,
    ) + $source_form;
    $form['feeds']['FeedsFileFetcher']['source']['#value'] = $form['#xmldir'];
  }
  file_prepare_directory($form['#xmldir'], FILE_CREATE_DIRECTORY);
  $form['#importer_id'] = $importer_id;
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
    '#submit' => array('ccis_xml_import_files_form_submit', 'feeds_import_form_submit'),
  );
  $progress = $source->progressImporting();
  if ($progress !== FEEDS_BATCH_COMPLETE) {
    $form['actions']['submit']['#disabled'] = TRUE;
    $form['actions']['submit']['#value'] =
    t('Importing (@progress %)', array('@progress' => number_format(100 * $progress, 0)));
  }
  return $form;
}

/**
 * Validation handler for ccis_xml_import_files_form().
 */
function ccis_xml_import_files_form_validate($form, $form_state) {
  feeds_source($form['#importer_id'])->configFormValidate($form_state['values']['feeds']);
}

/**
 * Submit handler for ccis_xml_import_files_form().
 */
function ccis_xml_import_files_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  if (!empty($values['upload'])) {
    $operations = array();
    foreach ($values['upload'] as $upload) {
      if ($upload['status'] == 'done') {
        $file = new stdClass();
        $file->uri = $upload['tmppath'];
        $file->filename = $upload['name'];
        $file->name = pathinfo($file->filename, PATHINFO_FILENAME);
        $destination = $form['#xmldir'] . '/' . $file->filename;
        file_unmanaged_move($file->uri, $destination, FILE_EXISTS_REPLACE);
      }
    }
  }
}
