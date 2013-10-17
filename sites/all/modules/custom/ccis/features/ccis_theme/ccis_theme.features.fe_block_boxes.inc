<?php
/**
 * @file
 * ccis_theme.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function ccis_theme_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Social media links';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'block_socialmedia';
  $fe_block_boxes->body = '<div id="socmed"><a class="fb" href="https://www.facebook.com/pages/Climability/399667536823023" target="_blank"><span>Facebook</span></a><a class="tw" href="https://www.twitter.com/climability" target="_blank"><span>Twitter</span></a><a class="gp" href="https://plus.google.com/109431579820251565186/posts" target="_blank"><span>Google +</span></div>';

  $export['block_socialmedia'] = $fe_block_boxes;

  return $export;
}
