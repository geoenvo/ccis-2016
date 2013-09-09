<?php
/**
 * @file
 * ccis_weather_station_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ccis_weather_station_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'weather_station';
  $feeds_importer->config = array(
    'name' => 'Weather Station',
    'description' => 'Weather Station Importer',
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
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'weather_station',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['weather_station'] = $feeds_importer;

  return $export;
}
