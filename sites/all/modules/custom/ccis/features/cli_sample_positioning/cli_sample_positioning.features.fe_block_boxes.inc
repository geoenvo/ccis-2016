<?php
/**
 * @file
 * cli_sample_positioning.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function cli_sample_positioning_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Address';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'address';
  $fe_block_boxes->body = '<div class="contactblock">
<h3>Address</h3>
<p class="contactdata postal">Pflügerstr. 56<br />
12047 Berlin<br />
Germany</p>
</div>';

  $export['address'] = $fe_block_boxes;

  return $export;
}
