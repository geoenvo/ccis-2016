<?php
/**
 * @file
 * ccis_ct_weather_station.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ccis_ct_weather_station_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "cer" && $api == "default_cer_presets") {
    return array("version" => "1");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ccis_ct_weather_station_node_info() {
  $items = array(
    'weather_station' => array(
      'name' => t('Weather Station'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Station name'),
      'help' => '',
    ),
  );
  return $items;
}
