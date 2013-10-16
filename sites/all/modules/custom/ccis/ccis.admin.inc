<?php

function ccis_search_settings($form, $form_state) {
  $search_fields = array();
  $field_infos = field_info_instances('node', 'weather_station');
  $types = array('text', 'text_long');
  foreach ($field_infos as $field_name => $info) {
    $field = field_info_field($field_name);
    if (in_array($field['type'], $types)) {
      $search_fields[$field_name] = $info['label'];
    }
  }
  $form['ccis_station_search_terms'] = array(
    '#title' => t('Fields'),
    '#type' => 'checkboxes',
    '#options' => $search_fields,
    '#default_value' => variable_get('ccis_station_search_terms', array()),
  );
  return system_settings_form($form);
}