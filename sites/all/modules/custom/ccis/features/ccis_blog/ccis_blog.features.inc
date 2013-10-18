<?php
/**
 * @file
 * ccis_blog.features.inc
 */

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

/**
 * Implements hook_node_info().
 */
function ccis_blog_node_info() {
  $items = array(
    'blog_article' => array(
      'name' => t('Blog article'),
      'base' => 'node_content',
      'description' => t('Used for ... well ... blogs.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
