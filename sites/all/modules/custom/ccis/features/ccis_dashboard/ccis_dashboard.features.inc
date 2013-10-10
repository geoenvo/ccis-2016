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
    'regions' => 3,
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
      'ccis_stationinfo' => 
      array (
        'module' => 'ccis',
        'delta' => 'stationinfo',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -11,
      ),
      'ccis_stationmap' => 
      array (
        'module' => 'ccis',
        'delta' => 'stationmap',
        'region' => 3,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -11,
      ),
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
        'region' => 2,
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
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 0,
        'title' => '',
        'weight' => -11,
      ),
    ),
    'widths' => 
    array (
      1 => 25,
      2 => 75,
      3 => 100,
    ),
    'title' => 'Dashboard',
    'path' => 'dashboard',
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
