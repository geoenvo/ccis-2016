<?php
/**
 * @file
 * ccis_news.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ccis_news_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aggregator_allowed_html_tags';
  $strongarm->value = '<a> <b> <br> <dd> <dl> <dt> <em> <i> <li> <ol> <p> <strong> <u> <ul>';
  $export['aggregator_allowed_html_tags'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aggregator_category_selector';
  $strongarm->value = 'checkboxes';
  $export['aggregator_category_selector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aggregator_clear';
  $strongarm->value = '9676800';
  $export['aggregator_clear'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aggregator_summary_items';
  $strongarm->value = '3';
  $export['aggregator_summary_items'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'aggregator_teaser_length';
  $strongarm->value = '400';
  $export['aggregator_teaser_length'] = $strongarm;

  return $export;
}
