<?php
/**
 * @file
 * cli_sample_positioning.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cli_sample_positioning_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'context_block_rebuild_needed';
  $strongarm->value = TRUE;
  $export['context_block_rebuild_needed'] = $strongarm;

  return $export;
}
