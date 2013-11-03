<?php
/**
 * @file
 * ccis_formatters.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ccis_formatters_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_custom_date_formats().
 */
function ccis_formatters_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['F'] = 'F';
  $custom_date_formats['M t, Y'] = 'M t, Y';
  $custom_date_formats['Y'] = 'Y';
  $custom_date_formats['d'] = 'd';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function ccis_formatters_date_format_types() {
  $format_types = array();
  // Exported date format type: compact
  $format_types['compact'] = 'Compact';
  // Exported date format type: day_only
  $format_types['day_only'] = 'Day only';
  // Exported date format type: month_only
  $format_types['month_only'] = 'Month only';
  // Exported date format type: year_only
  $format_types['year_only'] = 'Year only';
  return $format_types;
}
