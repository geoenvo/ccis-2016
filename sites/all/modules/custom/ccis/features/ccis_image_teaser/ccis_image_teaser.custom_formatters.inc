<?php
/**
 * @file
 * ccis_image_teaser.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function ccis_image_teaser_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'image_teaser';
  $formatter->label = 'Image teaser';
  $formatter->description = '';
  $formatter->mode = 'token';
  $formatter->field_types = 'image';
  $formatter->code = '<a href="[bean:field_internal_link_url]">[bean:field_teaser_image:large:render]</a>';
  $formatter->fapi = '';
  $export['image_teaser'] = $formatter;

  return $export;
}
