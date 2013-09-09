<?php
/**
 * @file
 * ccis_weather_data_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ccis_weather_data_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'weather_data';
  $feeds_importer->config = array(
    'name' => 'Weather Data',
    'description' => 'Weather Data Importer',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'date',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'date',
            'target' => 'field_date:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'avg_temp',
            'target' => 'field_avg_temp',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'avg_prec',
            'target' => 'field_avg_prec',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'avg_press',
            'target' => 'field_avg_press',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'avg_min_temp',
            'target' => 'field_avg_min_temp',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'avg_max_temp',
            'target' => 'field_avg_max_temp',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'station',
            'target' => 'field_station',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'weather_data',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['weather_data'] = $feeds_importer;

  return $export;
}
