<?php
/**
 * @file
 * ccis_formatters.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ccis_formatters_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
