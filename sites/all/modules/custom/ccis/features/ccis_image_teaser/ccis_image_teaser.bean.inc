<?php
/**
 * @file
 * ccis_image_teaser.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function ccis_image_teaser_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'image_teaser';
  $bean_type->label = 'Image teaser';
  $bean_type->options = '';
  $bean_type->description = 'Creates a block with a linked image. Title will be used for block administration only.';
  $export['image_teaser'] = $bean_type;

  return $export;
}
