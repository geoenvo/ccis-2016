<?php
/**
 * @file
 * ccis_ct_weather_station.default_cer_presets.inc
 */

/**
 * Implements hook_default_cer().
 */
function ccis_ct_weather_station_default_cer() {
  $export = array();

  $cnr_obj = new stdClass();
  $cnr_obj->disabled = FALSE; /* Edit this to true to make a default cnr_obj disabled initially */
  $cnr_obj->api_version = 1;
  $cnr_obj->entity_types_content_fields = 'node*walter_lieth_diagram*field_weather_station*node*weather_station*field_walter_lieht_diagram';
  $cnr_obj->enabled = 0;
  $export['node*walter_lieth_diagram*field_weather_station*node*weather_station*field_walter_lieht_diagram'] = $cnr_obj;

  return $export;
}
