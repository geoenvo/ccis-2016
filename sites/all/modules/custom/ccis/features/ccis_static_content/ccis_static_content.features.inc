<?php
/**
 * @file
 * ccis_static_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ccis_static_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ccis_static_content_image_default_styles() {
  $styles = array();

  // Exported image style: panorama.
  $styles['panorama'] = array(
    'name' => 'panorama',
    'label' => 'Panorama',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 245,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function ccis_static_content_node_info() {
  $items = array(
    'article_climatechange' => array(
      'name' => t('Climate Change Article'),
      'base' => 'node_content',
      'description' => t('Special page type feeding the slide show'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
