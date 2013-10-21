<?php
/**
 * @file
 * ccis_news.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ccis_news_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-news_via_feeds-block_newsfeed'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'news_via_feeds-block_newsfeed',
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
