<?php
/**
 * @file
 * ccis_content_exchanger.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ccis_content_exchanger_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
