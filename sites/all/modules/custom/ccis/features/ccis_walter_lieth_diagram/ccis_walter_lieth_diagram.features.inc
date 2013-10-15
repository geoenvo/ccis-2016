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

/**
 * Implements hook_node_info().
 */
function ccis_walter_lieth_diagram_node_info() {
  $items = array(
    'walter_lieth_diagram' => array(
      'name' => t('Walter-Lieth-Diagram'),
      'base' => 'node_content',
      'description' => t('Use this content-type for uploading a Walter-Lieth-Diagram and reference it to a weather station. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
