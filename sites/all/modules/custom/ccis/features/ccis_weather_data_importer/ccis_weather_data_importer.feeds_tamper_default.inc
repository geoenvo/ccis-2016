<?php
/**
 * @file
 * ccis_weather_data_importer.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function ccis_weather_data_importer_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'weather_data-avg_max_temp-find_replace_avg_max_temp';
  $feeds_tamper->importer = 'weather_data';
  $feeds_tamper->source = 'avg_max_temp';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '-9999',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^-9999$/i',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['weather_data-avg_max_temp-find_replace_avg_max_temp'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'weather_data-avg_min_temp-find_replace_avg_min_temp';
  $feeds_tamper->importer = 'weather_data';
  $feeds_tamper->source = 'avg_min_temp';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '-9999',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^-9999$/i',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['weather_data-avg_min_temp-find_replace_avg_min_temp'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'weather_data-avg_prec-find_replace_avg_prec';
  $feeds_tamper->importer = 'weather_data';
  $feeds_tamper->source = 'avg_prec';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '-9999',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^-9999$/i',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['weather_data-avg_prec-find_replace_avg_prec'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'weather_data-avg_press-find_replace_avg_press';
  $feeds_tamper->importer = 'weather_data';
  $feeds_tamper->source = 'avg_press';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '-9999',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^-9999$/i',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['weather_data-avg_press-find_replace_avg_press'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'weather_data-avg_temp-find_replace_avg_temp';
  $feeds_tamper->importer = 'weather_data';
  $feeds_tamper->source = 'avg_temp';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => '-9999',
    'replace' => '',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^-9999$/i',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['weather_data-avg_temp-find_replace_avg_temp'] = $feeds_tamper;

  return $export;
}
