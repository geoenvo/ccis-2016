<?php
/**
 * @file
 * cli_sample_positioning.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cli_sample_positioning_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
