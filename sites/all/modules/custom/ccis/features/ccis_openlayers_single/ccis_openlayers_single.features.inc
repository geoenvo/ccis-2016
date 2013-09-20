<?php
/**
 * @file
 * ccis_openlayers_single.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ccis_openlayers_single_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
}
