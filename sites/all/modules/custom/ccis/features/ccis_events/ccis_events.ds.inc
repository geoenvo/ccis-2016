<?php
/**
 * @file
 * ccis_events.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ccis_events_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'body',
      ),
      'right' => array(
        1 => 'field_image_event_logo',
        2 => 'field_date_event',
        3 => 'field_place_event',
        4 => 'field_country_event',
        5 => 'field_url_event',
      ),
    ),
    'fields' => array(
      'body' => 'left',
      'field_image_event_logo' => 'right',
      'field_date_event' => 'right',
      'field_place_event' => 'right',
      'field_country_event' => 'right',
      'field_url_event' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|event|default'] = $ds_layout;

  return $export;
}
