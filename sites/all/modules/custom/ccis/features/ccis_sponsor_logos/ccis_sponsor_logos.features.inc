<?php
/**
 * @file
 * ccis_sponsor_logos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ccis_sponsor_logos_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ccis_sponsor_logos_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ccis_sponsor_logos_image_default_styles() {
  $styles = array();

  // Exported image style: sponsor_logo.
  $styles['sponsor_logo'] = array(
    'name' => 'sponsor_logo',
    'label' => 'Sponsor logo',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 68,
          'upscale' => 1,
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
function ccis_sponsor_logos_node_info() {
  $items = array(
    'sponsor_logo' => array(
      'name' => t('Sponsor logo'),
      'base' => 'node_content',
      'description' => t('Used to show sponsors/stakeholders in footer block'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Title is used for editorial purposes only. View will be sorted by title, so you might want to enumerate.'),
    ),
  );
  return $items;
}
