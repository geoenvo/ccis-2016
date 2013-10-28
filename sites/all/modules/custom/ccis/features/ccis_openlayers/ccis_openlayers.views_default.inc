<?php
/**
 * @file
 * ccis_openlayers.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ccis_openlayers_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'big_maps_for_weather_stations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'map page for weather stations';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_station_geodata',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => '',
    'view_mode' => 'full',
    'style_field' => '',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'dashboard?nid=[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Current Position */
  $handler->display->display_options['fields']['field_station_geodata']['id'] = 'field_station_geodata';
  $handler->display->display_options['fields']['field_station_geodata']['table'] = 'field_data_field_station_geodata';
  $handler->display->display_options['fields']['field_station_geodata']['field'] = 'field_station_geodata';
  $handler->display->display_options['fields']['field_station_geodata']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_station_geodata']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Region */
  $handler->display->display_options['fields']['field_stationprovince']['id'] = 'field_stationprovince';
  $handler->display->display_options['fields']['field_stationprovince']['table'] = 'field_data_field_stationprovince';
  $handler->display->display_options['fields']['field_stationprovince']['field'] = 'field_stationprovince';
  $handler->display->display_options['fields']['field_stationprovince']['label'] = '';
  $handler->display->display_options['fields']['field_stationprovince']['element_label_colon'] = FALSE;
  /* Field: Content: WMO Code */
  $handler->display->display_options['fields']['field_wmocode']['id'] = 'field_wmocode';
  $handler->display->display_options['fields']['field_wmocode']['table'] = 'field_data_field_wmocode';
  $handler->display->display_options['fields']['field_wmocode']['field'] = 'field_wmocode';
  $handler->display->display_options['fields']['field_wmocode']['label'] = '';
  $handler->display->display_options['fields']['field_wmocode']['element_label_colon'] = FALSE;
  /* Field: Content: Station No. */
  $handler->display->display_options['fields']['field_stationcode']['id'] = 'field_stationcode';
  $handler->display->display_options['fields']['field_stationcode']['table'] = 'field_data_field_stationcode';
  $handler->display->display_options['fields']['field_stationcode']['field'] = 'field_stationcode';
  $handler->display->display_options['fields']['field_stationcode']['label'] = '';
  $handler->display->display_options['fields']['field_stationcode']['element_label_colon'] = FALSE;
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
    'weather_station' => 'weather_station',
  );

  /* Display: OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'openlayers_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_station_geodata',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => '',
    'view_mode' => 'full',
    'style_field' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['path'] = 'dashboard?nid=[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Current Position */
  $handler->display->display_options['fields']['field_station_geodata']['id'] = 'field_station_geodata';
  $handler->display->display_options['fields']['field_station_geodata']['table'] = 'field_data_field_station_geodata';
  $handler->display->display_options['fields']['field_station_geodata']['field'] = 'field_station_geodata';
  $handler->display->display_options['fields']['field_station_geodata']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_station_geodata']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Region */
  $handler->display->display_options['fields']['field_stationprovince']['id'] = 'field_stationprovince';
  $handler->display->display_options['fields']['field_stationprovince']['table'] = 'field_data_field_stationprovince';
  $handler->display->display_options['fields']['field_stationprovince']['field'] = 'field_stationprovince';
  $handler->display->display_options['fields']['field_stationprovince']['label'] = '';
  $handler->display->display_options['fields']['field_stationprovince']['element_label_colon'] = FALSE;
  /* Field: Content: WMO Code */
  $handler->display->display_options['fields']['field_wmocode']['id'] = 'field_wmocode';
  $handler->display->display_options['fields']['field_wmocode']['table'] = 'field_data_field_wmocode';
  $handler->display->display_options['fields']['field_wmocode']['field'] = 'field_wmocode';
  $handler->display->display_options['fields']['field_wmocode']['label'] = '';
  $handler->display->display_options['fields']['field_wmocode']['element_label_colon'] = FALSE;
  /* Field: Content: Station No. */
  $handler->display->display_options['fields']['field_stationcode']['id'] = 'field_stationcode';
  $handler->display->display_options['fields']['field_stationcode']['table'] = 'field_data_field_stationcode';
  $handler->display->display_options['fields']['field_stationcode']['field'] = 'field_stationcode';
  $handler->display->display_options['fields']['field_stationcode']['label'] = '';
  $handler->display->display_options['fields']['field_stationcode']['element_label_colon'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'clone_of_clone_of_geofield_formatter_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'map';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Map';
  $handler->display->display_options['menu']['weight'] = '-30';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['big_maps_for_weather_stations'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Current Position'),
    t('OpenLayers Data Overlay'),
    t('Page'),
  );
  $export['big_maps_for_weather_stations'] = $view;

  $view = new view();
  $view->name = 'ol_stations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'OL_Stations';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_station_geodata',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => '',
    'view_mode' => 'full',
    'style_field' => '',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'dashboard?nid=[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Current Position */
  $handler->display->display_options['fields']['field_station_geodata']['id'] = 'field_station_geodata';
  $handler->display->display_options['fields']['field_station_geodata']['table'] = 'field_data_field_station_geodata';
  $handler->display->display_options['fields']['field_station_geodata']['field'] = 'field_station_geodata';
  $handler->display->display_options['fields']['field_station_geodata']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_station_geodata']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: WMO Code */
  $handler->display->display_options['fields']['field_wmocode_1']['id'] = 'field_wmocode_1';
  $handler->display->display_options['fields']['field_wmocode_1']['table'] = 'field_data_field_wmocode';
  $handler->display->display_options['fields']['field_wmocode_1']['field'] = 'field_wmocode';
  $handler->display->display_options['fields']['field_wmocode_1']['label'] = '';
  $handler->display->display_options['fields']['field_wmocode_1']['element_label_colon'] = FALSE;
  /* Field: Content: Station No. */
  $handler->display->display_options['fields']['field_stationcode']['id'] = 'field_stationcode';
  $handler->display->display_options['fields']['field_stationcode']['table'] = 'field_data_field_stationcode';
  $handler->display->display_options['fields']['field_stationcode']['field'] = 'field_stationcode';
  $handler->display->display_options['fields']['field_stationcode']['label'] = '';
  $handler->display->display_options['fields']['field_stationcode']['element_label_colon'] = FALSE;
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
    'weather_station' => 'weather_station',
  );

  /* Display: OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'openlayers_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_station_geodata',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => '',
    'view_mode' => 'full',
    'style_field' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['path'] = 'dashboard?nid=[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Current Position */
  $handler->display->display_options['fields']['field_station_geodata']['id'] = 'field_station_geodata';
  $handler->display->display_options['fields']['field_station_geodata']['table'] = 'field_data_field_station_geodata';
  $handler->display->display_options['fields']['field_station_geodata']['field'] = 'field_station_geodata';
  $handler->display->display_options['fields']['field_station_geodata']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_station_geodata']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: WMO Code */
  $handler->display->display_options['fields']['field_wmocode_1']['id'] = 'field_wmocode_1';
  $handler->display->display_options['fields']['field_wmocode_1']['table'] = 'field_data_field_wmocode';
  $handler->display->display_options['fields']['field_wmocode_1']['field'] = 'field_wmocode';
  $handler->display->display_options['fields']['field_wmocode_1']['label'] = '';
  $handler->display->display_options['fields']['field_wmocode_1']['element_label_colon'] = FALSE;
  /* Field: Content: Station No. */
  $handler->display->display_options['fields']['field_stationcode']['id'] = 'field_stationcode';
  $handler->display->display_options['fields']['field_stationcode']['table'] = 'field_data_field_stationcode';
  $handler->display->display_options['fields']['field_stationcode']['field'] = 'field_stationcode';
  $handler->display->display_options['fields']['field_stationcode']['label'] = '';
  $handler->display->display_options['fields']['field_stationcode']['element_label_colon'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'clone_of_geofield_formatter_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'OL_stations_map';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'OpenLayers map';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['ol_stations'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Current Position'),
    t('OpenLayers Data Overlay'),
    t('Page'),
  );
  $export['ol_stations'] = $view;

  return $export;
}
