<?php
/**
 * @file
 * ccis_ct_weather_data.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ccis_ct_weather_data_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-climate_group-field_icon'
  $field_instances['node-climate_group-field_icon'] = array(
    'bundle' => 'climate_group',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_icon',
    'label' => 'icon',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'climate_group_icons',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '100x100',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-climate_unit-field_decimal_places_for_tooltip'
  $field_instances['node-climate_unit-field_decimal_places_for_tooltip'] = array(
    'bundle' => 'climate_unit',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select the number of decimal places for the tooltips',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_decimal_places_for_tooltip',
    'label' => 'Decimal places for tooltip',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-climate_unit-field_icon_unit'
  $field_instances['node-climate_unit-field_icon_unit'] = array(
    'bundle' => 'climate_unit',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_icon_unit',
    'label' => 'Icon',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'climate_unit_icons',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '100x100',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'node-climate_unit-field_label_axis'
  $field_instances['node-climate_unit-field_label_axis'] = array(
    'bundle' => 'climate_unit',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The label for the diagram axis',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_label_axis',
    'label' => 'Label axis',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-climate_unit-field_label_tooltip'
  $field_instances['node-climate_unit-field_label_tooltip'] = array(
    'bundle' => 'climate_unit',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The label for the tooltips',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_label_tooltip',
    'label' => 'Label tooltip',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_cc'
  $field_instances['node-weather_data-field_cc'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Daily cloud cover',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 47,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cc',
    'label' => 'CC',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Other',
      'climate_unit' => 'Octas',
      'color' => '00ff00',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_cdd'
  $field_instances['node-weather_data-field_cdd'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Maximum length of dry spell with RR < 1mm',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 50,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cdd',
    'label' => 'CDD',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Other',
      'climate_unit' => 'Days',
      'color' => 996600,
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 44,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_csdi'
  $field_instances['node-weather_data-field_csdi'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Cold speel duration index',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_csdi',
    'label' => 'CSDI',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Cold Extremes',
      'climate_unit' => 'Days',
      'color' => '7fbdd4',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_cwd'
  $field_instances['node-weather_data-field_cwd'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Maximum length of wet spell (days with RR ≥ 1mm)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 33,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cwd',
    'label' => 'CWD',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Precipitation',
      'climate_unit' => 'Days',
      'color' => 'b87ede',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_date'
  $field_instances['node-weather_data-field_date'] = array(
    'bundle' => 'weather_data',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_date',
    'label' => 'Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'Y-m-d H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_dd'
  $field_instances['node-weather_data-field_dd'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Daily wind direction',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 45,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_dd',
    'label' => 'DD',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Wind',
      'climate_unit' => 'Degrees',
      'color' => '45abb0',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 39,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_dtr'
  $field_instances['node-weather_data-field_dtr'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Daily temperature range',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_dtr',
    'label' => 'DTR',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Temperature',
      'climate_unit' => 'Celsius',
      'color' => 'ff8400',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_fd'
  $field_instances['node-weather_data-field_fd'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Number of frost days',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fd',
    'label' => 'FD',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Cold Extremes',
      'climate_unit' => 'Days',
      'color' => '5100ff',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '[d]',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_fg'
  $field_instances['node-weather_data-field_fg'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Daily mean wind speed',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 43,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fg',
    'label' => 'FG',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Wind',
      'climate_unit' => 'Meter per second',
      'color' => '00bac4',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_fx'
  $field_instances['node-weather_data-field_fx'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Daily maximum wind gust',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 44,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fx',
    'label' => 'FX',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Wind',
      'climate_unit' => 'Meter per second',
      'color' => '8dc6c9',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 38,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_gsl'
  $field_instances['node-weather_data-field_gsl'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Growing season length',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 46,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gsl',
    'label' => 'GSL',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Other',
      'climate_unit' => 'Days',
      'color' => 'ff9900',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 40,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_hu'
  $field_instances['node-weather_data-field_hu'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Daily humidity',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 48,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hu',
    'label' => 'HU',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Other',
      'climate_unit' => 'Percent',
      'color' => '33ccff',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_id'
  $field_instances['node-weather_data-field_id'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Number of icing days',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_id',
    'label' => 'ID',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Cold Extremes',
      'climate_unit' => 'Days',
      'color' => '793efa',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_pp'
  $field_instances['node-weather_data-field_pp'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Daily mean sea level pressure',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 49,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pp',
    'label' => 'PP',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Other',
      'climate_unit' => 'Hektopascal',
      'color' => '009900',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 43,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_prcptot'
  $field_instances['node-weather_data-field_prcptot'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Annual total precipitation in wet days',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 34,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prcptot',
    'label' => 'PRCPTOT',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Precipitation',
      'climate_unit' => 'Millimeter',
      'color' => 'b897db',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_r10mm'
  $field_instances['node-weather_data-field_r10mm'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Annual count of days when PRCP≥ 10mm',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 38,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_r10mm',
    'label' => 'R10mm',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Extreme Precipitation',
      'climate_unit' => 'Days',
      'color' => '15b33a',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_r20mm'
  $field_instances['node-weather_data-field_r20mm'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Annual count of days when PRCP≥ 20mm',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 39,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_r20mm',
    'label' => 'R20mm',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Extreme Precipitation',
      'climate_unit' => 'Days',
      'color' => '96c98d',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_r95ptot'
  $field_instances['node-weather_data-field_r95ptot'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Annual total PRCP when RR > 95p',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 41,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_r95ptot',
    'label' => 'R95pTOT',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Extreme Precipitation',
      'climate_unit' => 'Millimeter',
      'color' => '91a86a',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_r99ptot'
  $field_instances['node-weather_data-field_r99ptot'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Annual total PRCP when RR > 99p',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 42,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_r99ptot',
    'label' => 'R99pTOT',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Extreme Precipitation',
      'climate_unit' => 'Millimeter',
      'color' => '8b9c6e',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 36,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_rnnmm'
  $field_instances['node-weather_data-field_rnnmm'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Annual count of days when PRCP≥ nnmm',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 40,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_rnnmm',
    'label' => 'Rnnmm',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Extreme Precipitation',
      'climate_unit' => 'Days',
      'color' => 'a3c482',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_rr'
  $field_instances['node-weather_data-field_rr'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Daily precipitation amount',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 32,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_rr',
    'label' => 'RR',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Precipitation',
      'climate_unit' => 'Millimeter',
      'color' => '3b516c',
      'graph_type' => 1,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 26,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_rx1day'
  $field_instances['node-weather_data-field_rx1day'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Monthly maximum 1-day precipitation',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 35,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_rx1day',
    'label' => 'Rx1day',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Extreme Precipitation',
      'climate_unit' => 'Millimeter',
      'color' => '00ffb3',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 29,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_rx5day'
  $field_instances['node-weather_data-field_rx5day'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Monthly maximum consecutive 5-day precipitation',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 36,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_rx5day',
    'label' => 'Rx5day',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Extreme Precipitation',
      'climate_unit' => 'Millimeter',
      'color' => '00ff77',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_sd'
  $field_instances['node-weather_data-field_sd'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Daily snow depth',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 51,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sd',
    'label' => 'SD',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Other',
      'climate_unit' => 'Centimeter',
      'color' => 'ad886f',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '[cm]',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 45,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_sdii'
  $field_instances['node-weather_data-field_sdii'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Simple pricipitation intensity index',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 37,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sdii',
    'label' => 'SDII',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Extreme Precipitation',
      'climate_unit' => 'Millimeter',
      'color' => '1bcf45',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_ss'
  $field_instances['node-weather_data-field_ss'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Daily sunshine duration',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 52,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ss',
    'label' => 'SS',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Other',
      'climate_unit' => 'Hours',
      'color' => 'ccbc08',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 46,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_station'
  $field_instances['node-weather_data-field_station'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_station',
    'label' => 'Station',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_su'
  $field_instances['node-weather_data-field_su'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Number of summer days',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_su',
    'label' => 'SU',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Warm Extremes',
      'climate_unit' => 'Days',
      'color' => 'fb6a4a',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_tg'
  $field_instances['node-weather_data-field_tg'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Daily mean temperature',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tg',
    'label' => 'TG',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Temperature',
      'climate_unit' => 'Celsius',
      'color' => 'ff8000',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_tn'
  $field_instances['node-weather_data-field_tn'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Daily minimum temperature',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tn',
    'label' => 'TN',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Temperature',
      'climate_unit' => 'Celsius',
      'color' => 'fcb205',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_tn10p'
  $field_instances['node-weather_data-field_tn10p'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Percentage of days when TN < 10th percentile',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 29,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tn10p',
    'label' => 'TN10p',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Cold Extremes',
      'climate_unit' => 'Percent',
      'color' => '6b91e3',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_tn90p'
  $field_instances['node-weather_data-field_tn90p'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Percentage of days when TN > 90th percentile',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tn90p',
    'label' => 'TN90p',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Warm Extremes',
      'climate_unit' => 'Percent',
      'color' => 'fc9272',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_tnn'
  $field_instances['node-weather_data-field_tnn'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Monthly minimum value of TN',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 28,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tnn',
    'label' => 'Tnn',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Cold Extremes',
      'climate_unit' => 'Celsius',
      'color' => '5c72ed',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_tnx'
  $field_instances['node-weather_data-field_tnx'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Monthly maximum value of TN',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tnx',
    'label' => 'Tnx',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Warm Extremes',
      'climate_unit' => 'Celsius',
      'color' => 'cb181e',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_tr'
  $field_instances['node-weather_data-field_tr'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Number of tropical nights',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tr',
    'label' => 'TR',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Warm Extremes',
      'climate_unit' => 'Days',
      'color' => 'ef3c2c',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_tx'
  $field_instances['node-weather_data-field_tx'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Daily maximum temperature',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tx',
    'label' => 'TX',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Temperature',
      'climate_unit' => 'Celsius',
      'color' => 'ff0000',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_tx10p'
  $field_instances['node-weather_data-field_tx10p'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Percentage of days when TX < 10th percentile',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 30,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tx10p',
    'label' => 'TX10p',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Cold Extremes',
      'climate_unit' => 'Percent',
      'color' => '6ba7e3',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_tx90p'
  $field_instances['node-weather_data-field_tx90p'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Percentage of days when TX > 90th percentile',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tx90p',
    'label' => 'TX90p',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Warm Extremes',
      'climate_unit' => 'Percent',
      'color' => 'd4b9da',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_txn'
  $field_instances['node-weather_data-field_txn'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Monthly minimum value of TX',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 27,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_txn',
    'label' => 'Txn',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Cold Extremes',
      'climate_unit' => 'Celsius',
      'color' => '5d56f0',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_txx'
  $field_instances['node-weather_data-field_txx'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Monthly maximum value of TX',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_txx',
    'label' => 'Txx',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Warm Extremes',
      'climate_unit' => 'Celsius',
      'color' => '99000d',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-weather_data-field_wsdi'
  $field_instances['node-weather_data-field_wsdi'] = array(
    'bundle' => 'weather_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Warm speel duration index',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_wsdi',
    'label' => 'WSDI',
    'required' => 0,
    'settings' => array(
      'climate_group' => 'Warm Extremes',
      'climate_unit' => 'Days',
      'color' => 'cc6699',
      'graph_type' => 0,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 18,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Annual count of days when PRCP≥ 10mm');
  t('Annual count of days when PRCP≥ 20mm');
  t('Annual count of days when PRCP≥ nnmm');
  t('Annual total PRCP when RR > 95p');
  t('Annual total PRCP when RR > 99p');
  t('Annual total precipitation in wet days');
  t('CC');
  t('CDD');
  t('CSDI');
  t('CWD');
  t('Cold speel duration index');
  t('DD');
  t('DTR');
  t('Daily cloud cover');
  t('Daily humidity');
  t('Daily maximum temperature');
  t('Daily maximum wind gust');
  t('Daily mean sea level pressure');
  t('Daily mean temperature');
  t('Daily mean wind speed');
  t('Daily minimum temperature');
  t('Daily precipitation amount');
  t('Daily snow depth');
  t('Daily sunshine duration');
  t('Daily temperature range');
  t('Daily wind direction');
  t('Date');
  t('Decimal places for tooltip');
  t('FD');
  t('FG');
  t('FX');
  t('GSL');
  t('Growing season length');
  t('HU');
  t('ID');
  t('Icon');
  t('Label axis');
  t('Label tooltip');
  t('Maximum length of dry spell with RR < 1mm');
  t('Maximum length of wet spell (days with RR ≥ 1mm)');
  t('Monthly maximum 1-day precipitation');
  t('Monthly maximum consecutive 5-day precipitation');
  t('Monthly maximum value of TN');
  t('Monthly maximum value of TX');
  t('Monthly minimum value of TN');
  t('Monthly minimum value of TX');
  t('Number of frost days');
  t('Number of icing days');
  t('Number of summer days');
  t('Number of tropical nights');
  t('PP');
  t('PRCPTOT');
  t('Percentage of days when TN < 10th percentile');
  t('Percentage of days when TN > 90th percentile');
  t('Percentage of days when TX < 10th percentile');
  t('Percentage of days when TX > 90th percentile');
  t('R10mm');
  t('R20mm');
  t('R95pTOT');
  t('R99pTOT');
  t('RR');
  t('Rnnmm');
  t('Rx1day');
  t('Rx5day');
  t('SD');
  t('SDII');
  t('SS');
  t('SU');
  t('Select the number of decimal places for the tooltips');
  t('Simple pricipitation intensity index');
  t('Station');
  t('TG');
  t('TN');
  t('TN10p');
  t('TN90p');
  t('TR');
  t('TX');
  t('TX10p');
  t('TX90p');
  t('The label for the diagram axis');
  t('The label for the tooltips');
  t('Tnn');
  t('Tnx');
  t('Txn');
  t('Txx');
  t('WSDI');
  t('Warm speel duration index');
  t('icon');

  return $field_instances;
}
