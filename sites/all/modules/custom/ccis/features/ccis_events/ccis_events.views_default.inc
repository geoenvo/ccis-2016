<?php
/**
 * @file
 * ccis_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ccis_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Upcoming events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Event Logo */
  $handler->display->display_options['fields']['field_image_event_logo']['id'] = 'field_image_event_logo';
  $handler->display->display_options['fields']['field_image_event_logo']['table'] = 'field_data_field_image_event_logo';
  $handler->display->display_options['fields']['field_image_event_logo']['field'] = 'field_image_event_logo';
  $handler->display->display_options['fields']['field_image_event_logo']['label'] = '';
  $handler->display->display_options['fields']['field_image_event_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_event_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_event_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Month (Date) */
  $handler->display->display_options['fields']['field_date_event']['id'] = 'field_date_event';
  $handler->display->display_options['fields']['field_date_event']['table'] = 'field_data_field_date_event';
  $handler->display->display_options['fields']['field_date_event']['field'] = 'field_date_event';
  $handler->display->display_options['fields']['field_date_event']['ui_name'] = 'Month (Date)';
  $handler->display->display_options['fields']['field_date_event']['label'] = '';
  $handler->display->display_options['fields']['field_date_event']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_date_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_event']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_date_event']['element_wrapper_class'] = 'evdate month';
  $handler->display->display_options['fields']['field_date_event']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_event']['settings'] = array(
    'format_type' => 'month_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Day (Date) */
  $handler->display->display_options['fields']['field_date_event_1']['id'] = 'field_date_event_1';
  $handler->display->display_options['fields']['field_date_event_1']['table'] = 'field_data_field_date_event';
  $handler->display->display_options['fields']['field_date_event_1']['field'] = 'field_date_event';
  $handler->display->display_options['fields']['field_date_event_1']['ui_name'] = 'Day (Date)';
  $handler->display->display_options['fields']['field_date_event_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_event_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_date_event_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_event_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_date_event_1']['element_wrapper_class'] = 'evdate day';
  $handler->display->display_options['fields']['field_date_event_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_event_1']['settings'] = array(
    'format_type' => 'day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Year (Date) */
  $handler->display->display_options['fields']['field_date_event_2']['id'] = 'field_date_event_2';
  $handler->display->display_options['fields']['field_date_event_2']['table'] = 'field_data_field_date_event';
  $handler->display->display_options['fields']['field_date_event_2']['field'] = 'field_date_event';
  $handler->display->display_options['fields']['field_date_event_2']['ui_name'] = 'Year (Date)';
  $handler->display->display_options['fields']['field_date_event_2']['label'] = '';
  $handler->display->display_options['fields']['field_date_event_2']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_date_event_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_event_2']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_date_event_2']['element_wrapper_class'] = 'evdate year';
  $handler->display->display_options['fields']['field_date_event_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_event_2']['settings'] = array(
    'format_type' => 'year_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Place */
  $handler->display->display_options['fields']['field_place_event']['id'] = 'field_place_event';
  $handler->display->display_options['fields']['field_place_event']['table'] = 'field_data_field_place_event';
  $handler->display->display_options['fields']['field_place_event']['field'] = 'field_place_event';
  $handler->display->display_options['fields']['field_place_event']['label'] = '';
  $handler->display->display_options['fields']['field_place_event']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_place_event']['element_label_colon'] = FALSE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_event']['id'] = 'field_country_event';
  $handler->display->display_options['fields']['field_country_event']['table'] = 'field_data_field_country_event';
  $handler->display->display_options['fields']['field_country_event']['field'] = 'field_country_event';
  $handler->display->display_options['fields']['field_country_event']['label'] = '';
  $handler->display->display_options['fields']['field_country_event']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_country_event']['element_label_colon'] = FALSE;
  /* Field: Place + Country (Custom) */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Place + Country (Custom)';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_place_event], [field_country_event]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'p';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'evplace';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_url_event']['id'] = 'field_url_event';
  $handler->display->display_options['fields']['field_url_event']['table'] = 'field_data_field_url_event';
  $handler->display->display_options['fields']['field_url_event']['field'] = 'field_url_event';
  $handler->display->display_options['fields']['field_url_event']['label'] = '';
  $handler->display->display_options['fields']['field_url_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_url_event']['click_sort_column'] = 'url';
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
    'event' => 'event',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_events');
  $handler->display->display_options['path'] = 'events';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_events');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'events teaser';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Event Logo */
  $handler->display->display_options['fields']['field_image_event_logo']['id'] = 'field_image_event_logo';
  $handler->display->display_options['fields']['field_image_event_logo']['table'] = 'field_data_field_image_event_logo';
  $handler->display->display_options['fields']['field_image_event_logo']['field'] = 'field_image_event_logo';
  $handler->display->display_options['fields']['field_image_event_logo']['label'] = '';
  $handler->display->display_options['fields']['field_image_event_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image_event_logo']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['field_image_event_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_event_logo']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_image_event_logo']['element_wrapper_class'] = 'evlogo';
  $handler->display->display_options['fields']['field_image_event_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_event_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Place */
  $handler->display->display_options['fields']['field_place_event']['id'] = 'field_place_event';
  $handler->display->display_options['fields']['field_place_event']['table'] = 'field_data_field_place_event';
  $handler->display->display_options['fields']['field_place_event']['field'] = 'field_place_event';
  $handler->display->display_options['fields']['field_place_event']['label'] = '';
  $handler->display->display_options['fields']['field_place_event']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_place_event']['element_label_colon'] = FALSE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country_event']['id'] = 'field_country_event';
  $handler->display->display_options['fields']['field_country_event']['table'] = 'field_data_field_country_event';
  $handler->display->display_options['fields']['field_country_event']['field'] = 'field_country_event';
  $handler->display->display_options['fields']['field_country_event']['label'] = '';
  $handler->display->display_options['fields']['field_country_event']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_country_event']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_country_event']['alter']['text'] = ', [field_country_event]';
  $handler->display->display_options['fields']['field_country_event']['element_label_colon'] = FALSE;
  /* Field: Place + Country (Custom) */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Place + Country (Custom)';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_place_event][field_country_event]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'p';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'evplace';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Month (Date) */
  $handler->display->display_options['fields']['field_date_event']['id'] = 'field_date_event';
  $handler->display->display_options['fields']['field_date_event']['table'] = 'field_data_field_date_event';
  $handler->display->display_options['fields']['field_date_event']['field'] = 'field_date_event';
  $handler->display->display_options['fields']['field_date_event']['ui_name'] = 'Month (Date)';
  $handler->display->display_options['fields']['field_date_event']['label'] = '';
  $handler->display->display_options['fields']['field_date_event']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_date_event']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_event']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_date_event']['element_wrapper_class'] = 'evdate month';
  $handler->display->display_options['fields']['field_date_event']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_event']['settings'] = array(
    'format_type' => 'month_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Day (Date) */
  $handler->display->display_options['fields']['field_date_event_1']['id'] = 'field_date_event_1';
  $handler->display->display_options['fields']['field_date_event_1']['table'] = 'field_data_field_date_event';
  $handler->display->display_options['fields']['field_date_event_1']['field'] = 'field_date_event';
  $handler->display->display_options['fields']['field_date_event_1']['ui_name'] = 'Day (Date)';
  $handler->display->display_options['fields']['field_date_event_1']['label'] = '';
  $handler->display->display_options['fields']['field_date_event_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_date_event_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_event_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_date_event_1']['element_wrapper_class'] = 'evdate day';
  $handler->display->display_options['fields']['field_date_event_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_event_1']['settings'] = array(
    'format_type' => 'day_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Year (Date) */
  $handler->display->display_options['fields']['field_date_event_2']['id'] = 'field_date_event_2';
  $handler->display->display_options['fields']['field_date_event_2']['table'] = 'field_data_field_date_event';
  $handler->display->display_options['fields']['field_date_event_2']['field'] = 'field_date_event';
  $handler->display->display_options['fields']['field_date_event_2']['ui_name'] = 'Year (Date)';
  $handler->display->display_options['fields']['field_date_event_2']['label'] = '';
  $handler->display->display_options['fields']['field_date_event_2']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_date_event_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_event_2']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_date_event_2']['element_wrapper_class'] = 'evdate year';
  $handler->display->display_options['fields']['field_date_event_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_event_2']['settings'] = array(
    'format_type' => 'year_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $export['events'] = $view;

  return $export;
}
