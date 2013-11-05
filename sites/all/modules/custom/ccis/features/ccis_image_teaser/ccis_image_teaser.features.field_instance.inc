<?php
/**
 * @file
 * ccis_image_teaser.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ccis_image_teaser_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-image_teaser-field_internal_link_url'
  $field_instances['bean-image_teaser-field_internal_link_url'] = array(
    'bundle' => 'image_teaser',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter an existing path to content on this website with a leading slash (e. g. "/dashboard").',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_internal_link_url',
    'label' => 'Internal link URL',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bean-image_teaser-field_teaser_image'
  $field_instances['bean-image_teaser-field_teaser_image'] = array(
    'bundle' => 'image_teaser',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'custom_formatters',
        'settings' => array(),
        'type' => 'custom_formatters_image_teaser',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_teaser_image',
    'label' => 'Teaser image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bean-image_teaser-field_title_visible'
  $field_instances['bean-image_teaser-field_title_visible'] = array(
    'bundle' => 'image_teaser',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This will be the title that is visible under the image.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_title_visible',
    'label' => 'Visible title',
    'required' => 1,
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
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Enter an existing path to content on this website with a leading slash (e. g. "/dashboard").');
  t('Internal link URL');
  t('Teaser image');
  t('This will be the title that is visible under the image.');
  t('Visible title');

  return $field_instances;
}
