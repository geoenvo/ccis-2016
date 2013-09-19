<?php
/**
 * @file
 * ccis_openlayers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ccis_openlayers_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ccis_openlayers_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
