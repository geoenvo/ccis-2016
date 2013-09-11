<?php
/**
 * @file
 * ccis_dashboard.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ccis_dashboard_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_homebox().
 */
function ccis_dashboard_homebox() {
  $homeboxes = array();

  $homeboxes['weather_dashboard'] = array (
    'regions' => 5,
    'cache' => 1,
    'color' => 0,
    'colors' => 
    array (
      0 => '#E4F0F8',
      1 => '#E4F0F8',
      2 => '#E4F0F8',
      3 => '#E4F0F8',
      4 => '#E4F0F8',
      5 => '#E4F0F8',
    ),
    'blocks' => 
    array (
      'ccis_d3' => 
      array (
        'module' => 'ccis',
        'delta' => 'd3',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 0,
        'title' => '',
        'weight' => -11,
      ),
      'ccis_datatables' => 
      array (
        'module' => 'ccis',
        'delta' => 'datatables',
        'region' => 5,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 0,
        'title' => '',
        'weight' => -11,
      ),
      'ccis_filter' => 
      array (
        'module' => 'ccis',
        'delta' => 'filter',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 0,
        'title' => '',
        'weight' => -11,
      ),
      'views_station_info-block' => 
      array (
        'module' => 'views',
        'delta' => 'station_info-block',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 0,
        'title' => '',
        'weight' => -9,
      ),
      'views_station_info-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'station_info-block_1',
        'region' => 4,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 0,
        'title' => '',
        'weight' => -9,
      ),
    ),
    'widths' => 
    array (
      1 => 30,
      2 => 70,
      3 => 15,
      4 => 15,
      5 => 70,
    ),
    'title' => 'Weather',
    'path' => 'start',
    'menu' => 1,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 1,
    'roles' => 
    array (
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
  );


  return $homeboxes;
}
