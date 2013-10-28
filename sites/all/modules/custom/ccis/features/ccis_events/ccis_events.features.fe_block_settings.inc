<?php
/**
 * @file
 * ccis_events.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ccis_events_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-events-block_events'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'events-block_events',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ccizen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'ccizen',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
