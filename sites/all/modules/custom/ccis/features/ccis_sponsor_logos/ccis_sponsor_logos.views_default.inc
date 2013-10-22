<?php
/**
 * @file
 * ccis_sponsor_logos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ccis_sponsor_logos_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'sponsor_logos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sponsor logos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'stakeholder';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Top caption */
  $handler->display->display_options['fields']['field_caption_top']['id'] = 'field_caption_top';
  $handler->display->display_options['fields']['field_caption_top']['table'] = 'field_data_field_caption_top';
  $handler->display->display_options['fields']['field_caption_top']['field'] = 'field_caption_top';
  $handler->display->display_options['fields']['field_caption_top']['label'] = '';
  $handler->display->display_options['fields']['field_caption_top']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_caption_top']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_caption_top']['element_default_classes'] = FALSE;
  /* Field: Content: Sponsor logo image */
  $handler->display->display_options['fields']['field_images_sponsorlogo']['id'] = 'field_images_sponsorlogo';
  $handler->display->display_options['fields']['field_images_sponsorlogo']['table'] = 'field_data_field_images_sponsorlogo';
  $handler->display->display_options['fields']['field_images_sponsorlogo']['field'] = 'field_images_sponsorlogo';
  $handler->display->display_options['fields']['field_images_sponsorlogo']['label'] = '';
  $handler->display->display_options['fields']['field_images_sponsorlogo']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_images_sponsorlogo']['element_class'] = 'logoimg';
  $handler->display->display_options['fields']['field_images_sponsorlogo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images_sponsorlogo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_images_sponsorlogo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images_sponsorlogo']['settings'] = array(
    'image_style' => 'sponsor_logo',
    'image_link' => '',
  );
  /* Field: Content: Bottom caption */
  $handler->display->display_options['fields']['field_caption_bottom']['id'] = 'field_caption_bottom';
  $handler->display->display_options['fields']['field_caption_bottom']['table'] = 'field_data_field_caption_bottom';
  $handler->display->display_options['fields']['field_caption_bottom']['field'] = 'field_caption_bottom';
  $handler->display->display_options['fields']['field_caption_bottom']['label'] = '';
  $handler->display->display_options['fields']['field_caption_bottom']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_caption_bottom']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor_logo' => 'sponsor_logo',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_sponsors');
  $translatables['sponsor_logos'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
  );
  $export['sponsor_logos'] = $view;

  return $export;
}
