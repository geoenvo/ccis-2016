<?php
/**
 * @file
 * ccis_weather_station_importer.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function ccis_weather_station_importer_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'weather_station-xpathparser_70-implode';
  $feeds_tamper->importer = 'weather_station';
  $feeds_tamper->source = 'xpathparser:70';
  $feeds_tamper->plugin_id = 'implode';
  $feeds_tamper->settings = array(
    'glue' => ', ',
    'real_glue' => ', ',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Implode';
  $export['weather_station-xpathparser_70-implode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'weather_station-xpathparser_71-implode';
  $feeds_tamper->importer = 'weather_station';
  $feeds_tamper->source = 'xpathparser:71';
  $feeds_tamper->plugin_id = 'implode';
  $feeds_tamper->settings = array(
    'glue' => ', ',
    'real_glue' => ', ',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Implode';
  $export['weather_station-xpathparser_71-implode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'weather_station-xpathparser_72-implode';
  $feeds_tamper->importer = 'weather_station';
  $feeds_tamper->source = 'xpathparser:72';
  $feeds_tamper->plugin_id = 'implode';
  $feeds_tamper->settings = array(
    'glue' => ', ',
    'real_glue' => ', ',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Implode';
  $export['weather_station-xpathparser_72-implode'] = $feeds_tamper;

  return $export;
}
