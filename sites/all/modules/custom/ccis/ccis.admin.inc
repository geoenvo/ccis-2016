<?php

function ccis_search_settings($form, $form_state) {
  $search_fields = array();
  $field_infos = field_info_instances('node', 'weather_station');
  foreach ($field_infos as $field_name => $info) {
    $search_fields[$field_name] = $info['label'];
  }
  $form['ccis_station_search_terms'] = array(
    '#title' => t('Fields'),
    '#type' => 'checkboxes',
    '#options' => $search_fields,
    '#default_value' => variable_get('ccis_station_search_terms', array()),
  );
  dsm($form);
  return system_settings_form($form);
}