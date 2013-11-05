<?php

/**
 * Page callback for admin/ccis/search.
 */
function ccis_search_settings($form, $form_state) {
  $options = array();
  $field_infos = field_info_instances('node', 'weather_station');
  $types = array('text', 'text_long');
  foreach ($field_infos as $field_name => $info) {
    $field = field_info_field($field_name);
    if (in_array($field['type'], $types)) {
      $options[$field_name] = $info['label'] . " ($field_name)";
    }
  }
  $form['ccis_station_search_terms'] = array(
    '#title' => t('Fields'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => variable_get('ccis_station_search_terms', array()),
  );
  return system_settings_form($form);
}

/**
 * Page callback for admin/ccis/permissions.
 */
function ccis_weather_data_permissions($form, $form_state) {
  $form['ccis_weather_data_perms_range'] = array(
    '#title' => t('Fields'),
    '#type' => 'checkboxes',
    '#options' => _ccis_get_weather_data_labels(),
    '#default_value' => variable_get('ccis_weather_data_perms_range', array()),
  );
  return system_settings_form($form);
}