<?php
/**
 * @file
 * cli_sample_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cli_sample_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cli_sample_content_node_info() {
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
