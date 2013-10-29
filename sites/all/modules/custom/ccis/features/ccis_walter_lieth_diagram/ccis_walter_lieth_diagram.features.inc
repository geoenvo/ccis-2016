<?php
/**
 * @file
 * ccis_walter_lieth_diagram.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ccis_walter_lieth_diagram_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "cer" && $api == "default_cer_presets") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
