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
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['css_class'] = 'events teaser';
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
  /* Sort criterion: Content: Date (field_date_event) */
  $handler->display->display_options['sorts']['field_date_event_value']['id'] = 'field_date_event_value';
  $handler->display->display_options['sorts']['field_date_event_value']['table'] = 'field_data_field_date_event';
  $handler->display->display_options['sorts']['field_date_event_value']['field'] = 'field_date_event_value';
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
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_events');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'events teaser teaser-page';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'clearfix';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'view_node' => 'view_node',
    'body' => 'body',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['label'] = 'Newsfeed attachment';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'news_via_feeds:attachment_newsfeed';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Event Logo */
  $handler->display->display_options['fields']['field_image_event_logo']['id'] = 'field_image_event_logo';
  $handler->display->display_options['fields']['field_image_event_logo']['table'] = 'field_data_field_image_event_logo';
  $handler->display->display_options['fields']['field_image_event_logo']['field'] = 'field_image_event_logo';
  $handler->display->display_options['fields']['field_image_event_logo']['label'] = '';
  $handler->display->display_options['fields']['field_image_event_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_event_logo']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_image_event_logo']['element_wrapper_class'] = 'evlogo';
  $handler->display->display_options['fields']['field_image_event_logo']['element_default_classes'] = FALSE;
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
  $handler->display->display_options['fields']['field_date_event']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_date_event_1']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_date_event_2']['exclude'] = TRUE;
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
  /* Field: Date combined */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Date combined';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="evdate month">[field_date_event]</div>
<div class="evdate day">[field_date_event_1]</div>
<div class="evdate year">[field_date_event_2]</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'evdatebox';
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'teasertitle';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'evtitle';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
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
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_place_event], [field_country_event]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'evplace';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = 'Read more ...';
  $handler->display->display_options['fields']['view_node']['element_type'] = 'span';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'more-link';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div class="evplace">[nothing]</div>
[body] <span class="more-link">[view_node]</span>';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<a> <div> <p>';
  $handler->display->display_options['fields']['body']['element_type'] = 'span';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'evbody';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['path'] = 'events-news';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Events & News';
  $handler->display->display_options['menu']['weight'] = '-46';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_events');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Show full list';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'clearfix';
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
  /* Field: Month (Date) */
  $handler->display->display_options['fields']['field_date_event']['id'] = 'field_date_event';
  $handler->display->display_options['fields']['field_date_event']['table'] = 'field_data_field_date_event';
  $handler->display->display_options['fields']['field_date_event']['field'] = 'field_date_event';
  $handler->display->display_options['fields']['field_date_event']['ui_name'] = 'Month (Date)';
  $handler->display->display_options['fields']['field_date_event']['label'] = '';
  $handler->display->display_options['fields']['field_date_event']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_date_event_1']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_date_event_2']['exclude'] = TRUE;
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
  /* Field: Date combined */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Date combined';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="evdate month">[field_date_event]</div>
<div class="evdate day">[field_date_event_1]</div>
<div class="evdate year">[field_date_event_2]</div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'evdatebox';
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
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
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'evplace';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $translatables['events'] = array(
    t('Master'),
    t('Upcoming Events'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('[field_place_event], [field_country_event]'),
    t('Page'),
    t('Newsfeed attachment'),
    t('<div class="evdate month">[field_date_event]</div>
<div class="evdate day">[field_date_event_1]</div>
<div class="evdate year">[field_date_event_2]</div>'),
    t('Read more ...'),
    t('<div class="evplace">[nothing]</div>
[body] <span class="more-link">[view_node]</span>'),
    t('Block'),
    t('Show full list'),
    t('[title]'),
    t(', [field_country_event]'),
    t('[field_place_event][field_country_event]'),
  );
  $export['events'] = $view;

  return $export;
}
