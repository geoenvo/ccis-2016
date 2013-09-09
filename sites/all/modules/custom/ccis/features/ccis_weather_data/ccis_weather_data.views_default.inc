<?php
/**
 * @file
 * ccis_weather_data.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ccis_weather_data_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'weather_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Weather Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Daily mean temperature */
  $handler->display->display_options['fields']['field_daily_mean_temperature']['id'] = 'field_daily_mean_temperature';
  $handler->display->display_options['fields']['field_daily_mean_temperature']['table'] = 'field_data_field_daily_mean_temperature';
  $handler->display->display_options['fields']['field_daily_mean_temperature']['field'] = 'field_daily_mean_temperature';
  $handler->display->display_options['fields']['field_daily_mean_temperature']['label'] = 'mean_temp';
  $handler->display->display_options['fields']['field_daily_mean_temperature']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_daily_mean_temperature']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Daily minimum temperature */
  $handler->display->display_options['fields']['field_daily_minimum_temperature']['id'] = 'field_daily_minimum_temperature';
  $handler->display->display_options['fields']['field_daily_minimum_temperature']['table'] = 'field_data_field_daily_minimum_temperature';
  $handler->display->display_options['fields']['field_daily_minimum_temperature']['field'] = 'field_daily_minimum_temperature';
  $handler->display->display_options['fields']['field_daily_minimum_temperature']['label'] = 'min_temp';
  $handler->display->display_options['fields']['field_daily_minimum_temperature']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_daily_minimum_temperature']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Daily maximum temperature */
  $handler->display->display_options['fields']['field_daily_maximum_temperature']['id'] = 'field_daily_maximum_temperature';
  $handler->display->display_options['fields']['field_daily_maximum_temperature']['table'] = 'field_data_field_daily_maximum_temperature';
  $handler->display->display_options['fields']['field_daily_maximum_temperature']['field'] = 'field_daily_maximum_temperature';
  $handler->display->display_options['fields']['field_daily_maximum_temperature']['label'] = 'max_temp';
  $handler->display->display_options['fields']['field_daily_maximum_temperature']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_daily_maximum_temperature']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'weather_data' => 'weather_data',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'weather/export';
  $export['weather_export'] = $view;

  return $export;
}
