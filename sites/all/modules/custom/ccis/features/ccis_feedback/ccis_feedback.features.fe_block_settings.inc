<?php
/**
 * @file
 * ccis_feedback.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ccis_feedback_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['simplenews-6'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 6,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'simplenews',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'footer_thirdcolumn',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -14,
      ),
      'ccizen' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'ccizen',
        'weight' => -14,
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
