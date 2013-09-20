<?php
/**
 * @file
 * ccis_ct_weather_station.features.inc
 */

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
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
