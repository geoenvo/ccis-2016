<?php
/**
 * @file
 * ccis_ct_weather_data.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ccis_ct_weather_data_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ccis_ct_weather_data_node_info() {
  $items = array(
    'weather_data' => array(
      'name' => t('Weather data'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
