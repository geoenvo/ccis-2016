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

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Stakeholder logos in footer';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'block_stakeholders';
  $fe_block_boxes->body = '<div class="stakeholder first">Implemented by:
<img src="/sites/default/files/logos/giz.png" alt="Deutsche Gesellschaft für Internationale Zusammenarbeit (GIZ) GmbH" />
</div>
<div class="stakeholder second">In cooperation with:
<img src="/sites/default/files/logos/bmkg.png" alt="BMKG" />
</div>
<div class="stakeholder last">On behalf of:
<img src="/sites/default/files/logos/bmu_en.png" alt="Federal Ministry for the Environment, Nature Conservation and Nuclear Safety" /><br />
<span class="additional">of the Federal Republic of Germany</span>
</div>';

  $export['block_stakeholders'] = $fe_block_boxes;

  return $export;
}
