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

  $export['bean-image-teaser-dashboard'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'image-teaser-dashboard',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'bean',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
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
    'visibility' => 0,
  );

  $export['bean-image-teaser-map'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'image-teaser-map',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'bean',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
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
    'visibility' => 0,
  );

  $export['menu-menu-footer-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
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
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
