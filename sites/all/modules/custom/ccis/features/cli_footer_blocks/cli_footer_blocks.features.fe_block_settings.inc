<?php
/**
 * @file
 * cli_footer_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function cli_footer_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-block_contactinfo'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'block_contactinfo',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'footer_secondcolumn',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => -15,
      ),
      'ccizen' => array(
        'region' => 'footer_secondcolumn',
        'status' => 1,
        'theme' => 'ccizen',
        'weight' => -15,
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

  $export['simplenews-6'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 6,
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
        'region' => 'footer_thirdcolumn',
        'status' => 1,
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
