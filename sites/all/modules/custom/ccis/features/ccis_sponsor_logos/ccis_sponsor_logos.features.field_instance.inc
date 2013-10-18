<?php
/**
 * @file
 * ccis_sponsor_logos.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ccis_sponsor_logos_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-sponsor_logo-field_caption_bottom'
  $field_instances['node-sponsor_logo-field_caption_bottom'] = array(
    'bundle' => 'sponsor_logo',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'additional information below logo (optional)',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_caption_bottom',
    'label' => 'Bottom caption',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 40,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-sponsor_logo-field_caption_top'
  $field_instances['node-sponsor_logo-field_caption_top'] = array(
    'bundle' => 'sponsor_logo',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Label above logo, e. g. "In cooperation with:"',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_caption_top',
    'label' => 'Top caption',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 40,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-sponsor_logo-field_images_sponsorlogo'
  $field_instances['node-sponsor_logo-field_images_sponsorlogo'] = array(
    'bundle' => 'sponsor_logo',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_images_sponsorlogo',
    'label' => 'Sponsor logo image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'stakeholders',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '20x68',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Bottom caption');
  t('Label above logo, e. g. "In cooperation with:"');
  t('Sponsor logo image');
  t('Top caption');
  t('additional information below logo (optional)');

  return $field_instances;
}
