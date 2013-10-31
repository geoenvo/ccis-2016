<?php
/**
 * @file
 * ccis_theme.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ccis_theme_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'ccizen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'ccizen',
        'weight' => 12,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
