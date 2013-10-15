<?php
/**
 * @file
 * ccis_walter_lieth_diagram.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ccis_walter_lieth_diagram_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_diagram_picture'
  $field_bases['field_diagram_picture'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_diagram_picture',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'private',
      'views_base_columns' => array(),
      'views_base_table' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_statement'
  $field_bases['field_statement'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_statement',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'views_base_columns' => array(),
      'views_base_table' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_weather_station'
  $field_bases['field_weather_station'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_weather_station',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'weather_station' => 'weather_station',
        ),
      ),
      'target_type' => 'node',
      'views_base_columns' => array(),
      'views_base_table' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
