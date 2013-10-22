<?php
/**
 * @file
 * ccis_content_exchanger.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ccis_content_exchanger_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_author_blog_article';
  $strongarm->value = 1;
  $export['node_export_reset_author_blog_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_author_simplenews';
  $strongarm->value = 1;
  $export['node_export_reset_author_simplenews'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_author_sponsor_logo';
  $strongarm->value = 1;
  $export['node_export_reset_author_sponsor_logo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_author_walter_lieth_diagram';
  $strongarm->value = 1;
  $export['node_export_reset_author_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_created_blog_article';
  $strongarm->value = 0;
  $export['node_export_reset_created_blog_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_created_simplenews';
  $strongarm->value = 0;
  $export['node_export_reset_created_simplenews'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_created_sponsor_logo';
  $strongarm->value = 0;
  $export['node_export_reset_created_sponsor_logo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_created_walter_lieth_diagram';
  $strongarm->value = 0;
  $export['node_export_reset_created_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_menu_blog_article';
  $strongarm->value = 0;
  $export['node_export_reset_menu_blog_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_menu_simplenews';
  $strongarm->value = 0;
  $export['node_export_reset_menu_simplenews'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_menu_sponsor_logo';
  $strongarm->value = 0;
  $export['node_export_reset_menu_sponsor_logo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_menu_walter_lieth_diagram';
  $strongarm->value = 0;
  $export['node_export_reset_menu_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_path_blog_article';
  $strongarm->value = 0;
  $export['node_export_reset_path_blog_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_path_simplenews';
  $strongarm->value = 0;
  $export['node_export_reset_path_simplenews'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_path_sponsor_logo';
  $strongarm->value = 0;
  $export['node_export_reset_path_sponsor_logo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_path_walter_lieth_diagram';
  $strongarm->value = 0;
  $export['node_export_reset_path_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_status_blog_article';
  $strongarm->value = 0;
  $export['node_export_reset_status_blog_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_status_simplenews';
  $strongarm->value = 0;
  $export['node_export_reset_status_simplenews'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_status_sponsor_logo';
  $strongarm->value = 0;
  $export['node_export_reset_status_sponsor_logo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_export_reset_status_walter_lieth_diagram';
  $strongarm->value = 0;
  $export['node_export_reset_status_walter_lieth_diagram'] = $strongarm;

  return $export;
}
