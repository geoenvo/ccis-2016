<?php
/**
 * @file
 * ccis_ct_weather_station.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ccis_ct_weather_station_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-weather_station-field_address_data'
  $field_instances['node-weather_station-field_address_data'] = array(
    'bundle' => 'weather_station',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_address_data',
    'label' => 'Address Data',
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
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-weather_station-field_csv_files'
  $field_instances['node-weather_station-field_csv_files'] = array(
    'bundle' => 'weather_station',
    'deleted' => 0,
    'description' => 'The filename must be in this pattern <em>stationname_(daily|monthly|yearly).csv</em>. Note: It is not possible at the moment to replace a file here.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_csv_files',
    'label' => 'CSV-Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'csv_incoming',
      'file_extensions' => 'csv',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-weather_station-field_mongodb_list_name'
  $field_instances['node-weather_station-field_mongodb_list_name'] = array(
    'bundle' => 'weather_station',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'In case the station title is not equal with csv file name suffix, enter here the right suffix. Example: Station title is <em>München</em>, File name is <em>munich_yearly.csv</em> then enter <em>munich</em>.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_mongodb_list_name',
    'label' => 'MongoDB List Suffix',
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

  // Exported field_instance: 'node-weather_station-field_station_alias'
  $field_instances['node-weather_station-field_station_alias'] = array(
    'bundle' => 'weather_station',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_station_alias',
    'label' => 'Station Alias',
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
      'weight' => -4,
    ),
  );

  // Exported field_instance: 'node-weather_station-field_station_geodata'
  $field_instances['node-weather_station-field_station_geodata'] = array(
    'bundle' => 'weather_station',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'geofield',
        'settings' => array(
          'data' => 'full',
          'map_preset' => 'geofield_formatter_map',
        ),
        'type' => 'geofield_openlayers',
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
    'field_name' => 'field_station_geodata',
    'label' => 'Current Position',
    'required' => 0,
    'settings' => array(
      'local_solr' => array(
        'enabled' => FALSE,
        'lat_field' => 'lat',
        'lng_field' => 'lng',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'geofield',
      'settings' => array(),
      'type' => 'geofield_latlon',
      'weight' => -1,
    ),
  );

  // Exported field_instance: 'node-weather_station-field_station_number'
  $field_instances['node-weather_station-field_station_number'] = array(
    'bundle' => 'weather_station',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '5-digit code',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_station_number',
    'label' => ' WMO Code or station number',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 5,
      ),
      'type' => 'text_textfield',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'node-weather_station-field_station_type'
  $field_instances['node-weather_station-field_station_type'] = array(
    'bundle' => 'weather_station',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'field_name' => 'field_station_type',
    'label' => 'Type of station',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => -2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t(' WMO Code or station number');
  t('5-digit code');
  t('Address Data');
  t('CSV-Files');
  t('Current Position');
  t('In case the station title is not equal with csv file name suffix, enter here the right suffix. Example: Station title is <em>München</em>, File name is <em>munich_yearly.csv</em> then enter <em>munich</em>.');
  t('MongoDB List Suffix');
  t('Station Alias');
  t('The filename must be in this pattern <em>stationname_(daily|monthly|yearly).csv</em>. Note: It is not possible at the moment to replace a file here.');
  t('Type of station');

  return $field_instances;
}
