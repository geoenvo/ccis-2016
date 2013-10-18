<?php
/**
 * @file
 * cli_sponsor_logos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cli_sponsor_logos_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
