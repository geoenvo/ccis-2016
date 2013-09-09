<?php
/**
 * @file
 *
 */

$plugin = array(
  'form' => 'ccis_date_to_unix_form',
  // Optional validation callback.
 # 'validate' => 'MODULE_MY_PLUGIN_validate',
  'callback' => 'ccis_date_to_unix_callback',
  'name' => 'StringToTime',
  'multi' => 'loop',
  'category' => 'Date',
);

function ccis_date_to_unix_form($importer, $element_key, $settings) {
  $form = array();
 # dsm($form);
  $form['help']['#value'] = t('Converts dates like 2013-07-29 00:00:00+02 to Unix timestamp.');
  //
  // Other formy stuff here.
  //
  return $form;
}

function MODULE_MY_PLUGIN_validate(&$settings) {
  // Validate $settings.
}

function ccis_date_to_unix_callback($source, $item_key, $element_key, &$field, $settings) {
  $field = strtotime($field);
}