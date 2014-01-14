<?php
/**
 * @file
 * ccis_blog.features.inc
 */

/**
 * Implements hook_aggregator_default_feeds().
 */
function ccis_blog_aggregator_default_feeds() {
  $feeds = array();

  // Exported feed: Climability blog feed
  $feeds['Climability blog feed'] = array(
    'title' => 'Climability blog feed',
    'url' => 'http://climability.org/rss/blog_feed.xml',
    'refresh' => 21600,
    'block' => 2,
  );

  return $feeds;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ccis_blog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ccis_blog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
