<?php
/**
 * @file
 * ccis_image_teaser.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ccis_image_teaser_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ccis_image_teaser_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
