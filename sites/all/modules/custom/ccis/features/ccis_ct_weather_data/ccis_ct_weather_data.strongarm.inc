<?php
/**
 * @file
 * ccis_ct_weather_data.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ccis_ct_weather_data_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_weather_data';
  $strongarm->value = '0';
  $export['auto_entitylabel_node_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_weather_data';
  $strongarm->value = '';
  $export['auto_entitylabel_pattern_node_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_weather_data';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_node_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ccis_weather_data_perms_range';
  $strongarm->value = array(
    'field_tx' => 'field_tx',
    'field_tn' => 'field_tn',
    'field_tg' => 'field_tg',
    'field_rr' => 'field_rr',
    'field_fg' => 'field_fg',
    'field_fx' => 'field_fx',
    'field_dd' => 'field_dd',
    'field_cc' => 'field_cc',
    'field_hu' => 'field_hu',
    'field_pp' => 'field_pp',
    'field_station' => 0,
    'field_date' => 0,
    'field_avg_temp' => 0,
    'field_avg_prec' => 0,
    'field_avg_press' => 0,
    'field_avg_min_temp' => 0,
    'field_avg_max_temp' => 0,
    'field_dtr' => 0,
    'field_su' => 0,
    'field_tr' => 0,
    'field_txx' => 0,
    'field_tnx' => 0,
    'field_tn90p' => 0,
    'field_tx90p' => 0,
    'field_wsdi' => 0,
    'field_fd' => 0,
    'field_id' => 0,
    'field_txn' => 0,
    'field_tnn' => 0,
    'field_tn10p' => 0,
    'field_tx10p' => 0,
    'field_csdi' => 0,
    'field_cwd' => 0,
    'field_prcptot' => 0,
    'field_rx1day' => 0,
    'field_rx5day' => 0,
    'field_sdii' => 0,
    'field_r10mm' => 0,
    'field_r20mm' => 0,
    'field_rnnmm' => 0,
    'field_r95ptot' => 0,
    'field_r99ptot' => 0,
    'field_gsl' => 0,
    'field_cdd' => 0,
    'field_sd' => 0,
    'field_ss' => 0,
  );
  $export['ccis_weather_data_perms_range'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_weather_data';
  $strongarm->value = 0;
  $export['comment_anonymous_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_weather_data';
  $strongarm->value = 1;
  $export['comment_default_mode_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_weather_data';
  $strongarm->value = '50';
  $export['comment_default_per_page_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_weather_data';
  $strongarm->value = 1;
  $export['comment_form_location_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_weather_data';
  $strongarm->value = '1';
  $export['comment_preview_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_weather_data';
  $strongarm->value = 1;
  $export['comment_subject_field_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_weather_data';
  $strongarm->value = '0';
  $export['comment_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_weather_data';
  $strongarm->value = '0';
  $export['language_content_type_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_weather_data';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_weather_data';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_weather_data';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_weather_data';
  $strongarm->value = '1';
  $export['node_preview_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_weather_data';
  $strongarm->value = 1;
  $export['node_submitted_weather_data'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_weather_station_pattern';
  $strongarm->value = '';
  $export['pathauto_node_weather_station_pattern'] = $strongarm;

  return $export;
}
