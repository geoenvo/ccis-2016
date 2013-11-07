<?php
/**
 * @file
 * ccis_news.features.inc
 */

/**
 * Implements hook_aggregator_default_feeds().
 */
function ccis_news_aggregator_default_feeds() {
  $feeds = array();

  // Exported feed: IISD
  $feeds['IISD'] = array(
    'title' => 'IISD',
    'url' => 'http://climate-l.iisd.org/feed/',
    'refresh' => 43200,
    'block' => 0,
  );

  // Exported feed: RTCC
  $feeds['RTCC'] = array(
    'title' => 'RTCC',
    'url' => 'http://www.rtcc.org/feed/',
    'refresh' => 43200,
    'block' => 0,
  );

  // Exported feed: Service status
  $feeds['Service status'] = array(
    'title' => 'Service status',
    'url' => 'https://drupal.org/planet/rss.xml',
    'refresh' => 86400,
    'block' => 0,
  );

  // Exported feed: UN Framework Convention on Climate Change
  $feeds['UN Framework Convention on Climate Change'] = array(
    'title' => 'UN Framework Convention on Climate Change',
    'url' => 'http://unfccc.int/tools_xml/headlines_rss.xml',
    'refresh' => 43200,
    'block' => 0,
  );

  return $feeds;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ccis_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ccis_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
