<?php
/**
 * @file
 * ccis_basic_page.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ccis_basic_page_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_pattern';
  $strongarm->value = '[node:menu-link:parent]/[node:menu-link]';
  $export['pathauto_node_pattern'] = $strongarm;

  return $export;
}
