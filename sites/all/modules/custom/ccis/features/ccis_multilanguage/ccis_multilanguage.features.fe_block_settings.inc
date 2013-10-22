<?php
/**
 * @file
 * ccis_multilanguage.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ccis_multilanguage_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['lang_dropdown-language'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'language',
    'module' => 'lang_dropdown',
    'node_types' => array(),
    'pages' => '',
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
        'weight' => -17,
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
