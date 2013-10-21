<?php
/**
 * @file
 * ccis_ct_weather_data.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ccis_ct_weather_data_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_weather_data';
  $strongarm->value = '0';
  $export['auto_entitylabel_node_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_weather_data';
  $strongarm->value = '';
  $export['auto_entitylabel_pattern_node_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_weather_data';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_node_weather_data'] = $strongarm;

  return $export;
}
