<?php
/**
 * @file
 * cli_footer_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function cli_footer_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Contact/Address';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'block_contactinfo';
  $fe_block_boxes->body = '<div class="contactblock">
<h3>Contact</h3>
<p class="contactdata mail">info@climability.org</p>
<p class="contactdata phone">0012 34567890</p>
<h3>Address</h3>
<p class="contactdata postal">Street 123, Bulding 4<br />
12345 Jakarta, Indonesia</p>
</div>';

  $export['block_contactinfo'] = $fe_block_boxes;

  return $export;
}
