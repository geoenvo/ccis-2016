<?php
/**
 * @file
 * ccis_openlayers.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function ccis_openlayers_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'big_map_for_climate_stations';
  $openlayers_maps->title = 'Big map for climate stations';
  $openlayers_maps->description = 'Big map for climate stations';
  $openlayers_maps->data = array(
    'width' => '960px',
    'height' => '596px',
    'image_path' => 'sites/all/modules/custom/ccis/css/ol/img/',
    'css_path' => 'sites/all/modules/custom/ccis/css/ol/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '9.931640565729253, 49.28144939810833',
        'zoom' => '5',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_cluster' => array(
        'clusterlayer' => array(
          'map_page_for_climate_stations_openlayers_1' => 'map_page_for_climate_stations_openlayers_1',
          'grid_precipitation' => 0,
          'grid_temperature' => 0,
          'administrative_boundaries' => 0,
        ),
        'distance' => '20',
        'threshold' => '',
        'display_cluster_numbers' => 1,
        'middle_lower_bound' => '15',
        'middle_upper_bound' => '50',
        'low_color' => 'rgb(141, 203, 61)',
        'middle_color' => 'rgb(49, 190, 145)',
        'high_color' => 'rgb(35, 59, 177)',
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'sortBaseLayer' => '0',
        'roundedCorner' => 0,
        'roundedCornerColor' => '#222222',
        'maximizeDefault' => 0,
        'div' => '',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_plus_behavior_blocktoggle' => array(
        'enabled' => 1,
        'a_label' => 'Satellite',
        'a' => 'mapquest_openaerial',
        'b_label' => 'Map',
        'b' => 'mapquest_osm',
        'position' => 'ne',
      ),
      'openlayers_plus_behavior_legend' => array(
        'layers' => array(
          'grid_precipitation' => 'grid_precipitation',
          'grid_temperature' => 'grid_temperature',
          'administrative_boundaries' => 'administrative_boundaries',
          'map_page_for_climate_stations_openlayers_1' => 0,
        ),
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'grid_temperature' => 'grid_temperature',
          'map_page_for_climate_stations_openlayers_1' => 'map_page_for_climate_stations_openlayers_1',
          'grid_precipitation' => 0,
          'administrative_boundaries' => 0,
        ),
        'panMapIfOutOfView' => 0,
        'keepInMap' => 1,
      ),
      'openlayers_behavior_zoompanel' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => array(
          'mapquest_osm' => 0,
          'mapquest_openaerial' => 0,
          'grid_precipitation' => 0,
          'grid_temperature' => 0,
          'administrative_boundaries' => 0,
          'map_page_for_climate_stations_openlayers_1' => 0,
        ),
        'point_zoom_level' => '5',
        'zoomtolayer_scale' => '1',
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
      'grid_precipitation' => 'grid_precipitation',
      'grid_temperature' => 'grid_temperature',
      'administrative_boundaries' => 'administrative_boundaries',
      'map_page_for_climate_stations_openlayers_1' => 'map_page_for_climate_stations_openlayers_1',
    ),
    'layer_weight' => array(
      'big_map_for_climate_stations' => '0',
      'map_block_for_climate_stations_openlayers_1' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'small_map_for_climate_stations' => '0',
      'geofield_formatter' => '0',
      'grid_precipitation' => '1',
      'grid_temperature' => '2',
      'administrative_boundaries' => '6',
      'map_page_for_climate_stations_openlayers_1' => '9',
    ),
    'layer_styles' => array(
      'big_map_for_climate_stations' => 'ccis_marker_green_yellow',
      'small_map_for_climate_stations' => '0',
      'geofield_formatter' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'map_block_for_climate_stations_openlayers_1' => '0',
      'grid_precipitation' => '0',
      'grid_temperature' => '0',
      'administrative_boundaries' => 'boundaries',
      'map_page_for_climate_stations_openlayers_1' => 'ccis_marker_green_yellow',
    ),
    'layer_styles_select' => array(
      'big_map_for_climate_stations' => 'ccis_marker_green_yellow',
      'small_map_for_climate_stations' => '0',
      'geofield_formatter' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'map_block_for_climate_stations_openlayers_1' => '0',
      'grid_precipitation' => '0',
      'grid_temperature' => '0',
      'administrative_boundaries' => '0',
      'map_page_for_climate_stations_openlayers_1' => 'ccis_marker_green_yellow',
    ),
    'layer_styles_temporary' => array(
      'big_map_for_climate_stations' => 'ccis_marker_green_yellow',
      'small_map_for_climate_stations' => '0',
      'geofield_formatter' => 'ccis_marker_green_yellow_active_1',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'map_block_for_climate_stations_openlayers_1' => '0',
      'grid_precipitation' => '0',
      'grid_temperature' => '0',
      'administrative_boundaries' => '0',
      'map_page_for_climate_stations_openlayers_1' => 'ccis_marker_green_yellow',
    ),
    'layer_activated' => array(
      'administrative_boundaries' => 'administrative_boundaries',
      'map_page_for_climate_stations_openlayers_1' => 'map_page_for_climate_stations_openlayers_1',
      'grid_precipitation' => 0,
      'grid_temperature' => 0,
      'big_map_for_climate_stations' => 0,
      'small_map_for_climate_stations' => 0,
      'geofield_formatter' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'map_block_for_climate_stations_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'grid_precipitation' => 'grid_precipitation',
      'grid_temperature' => 'grid_temperature',
      'administrative_boundaries' => 'administrative_boundaries',
      'map_page_for_climate_stations_openlayers_1' => 0,
      'big_map_for_climate_stations' => 0,
      'small_map_for_climate_stations' => 0,
      'geofield_formatter' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'map_block_for_climate_stations_openlayers_1' => 0,
    ),
    'projection' => 'EPSG:3857',
    'displayProjection' => 'EPSG:4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['big_map_for_climate_stations'] = $openlayers_maps;

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'small_map_for_climate_stations';
  $openlayers_maps->title = 'Small map for climate stations';
  $openlayers_maps->description = 'Small map for climate stations';
  $openlayers_maps->data = array(
    'width' => '960px',
    'height' => '256px',
    'image_path' => 'sites/all/modules/custom/ccis/css/ol/img/',
    'css_path' => 'sites/all/modules/custom/ccis/css/ol/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '9.931640608848388, 50.903032833474754',
        'zoom' => '5',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_cluster' => array(
        'clusterlayer' => array(
          'administrative_boundaries' => 0,
          'map_block_for_climate_stations_openlayers_1' => 0,
          'geofield_formatter' => 0,
        ),
        'distance' => '20',
        'threshold' => '',
        'display_cluster_numbers' => 1,
        'middle_lower_bound' => '15',
        'middle_upper_bound' => '50',
        'low_color' => 'rgb(141, 203, 61)',
        'middle_color' => 'rgb(49, 190, 145)',
        'high_color' => 'rgb(35, 59, 177)',
      ),
      'openlayers_behavior_hover' => array(
        'layers' => array(
          'administrative_boundaries' => 0,
          'map_block_for_climate_stations_openlayers_1' => 0,
          'geofield_formatter' => 0,
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_plus_behavior_blocktoggle' => array(
        'enabled' => 1,
        'a_label' => 'Satellite',
        'a' => 'mapquest_openaerial',
        'b_label' => 'Map',
        'b' => 'mapquest_osm',
        'position' => 'ne',
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'administrative_boundaries' => 0,
          'map_block_for_climate_stations_openlayers_1' => 0,
          'geofield_formatter' => 0,
        ),
        'panMapIfOutOfView' => 0,
        'keepInMap' => 1,
      ),
      'openlayers_behavior_zoompanel' => array(),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => array(
          'geofield_formatter' => 'geofield_formatter',
          'mapquest_osm' => 0,
          'mapquest_openaerial' => 0,
          'administrative_boundaries' => 0,
          'map_block_for_climate_stations_openlayers_1' => 0,
        ),
        'point_zoom_level' => '5',
        'zoomtolayer_scale' => '1',
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
      'administrative_boundaries' => 'administrative_boundaries',
      'map_block_for_climate_stations_openlayers_1' => 'map_block_for_climate_stations_openlayers_1',
      'geofield_formatter' => 'geofield_formatter',
    ),
    'layer_weight' => array(
      'openlayers_geojson_picture_this' => '0',
      'map_page_for_climate_stations_openlayers_1' => '0',
      'administrative_boundaries' => '0',
      'big_map_for_climate_stations' => '0',
      'openlayers_kml_example' => '0',
      'grid_temperature' => '0',
      'grid_precipitation' => '0',
      'small_map_for_climate_stations' => '1',
      'map_block_for_climate_stations_openlayers_1' => '1',
      'geofield_formatter' => '2',
    ),
    'layer_styles' => array(
      'big_map_for_climate_stations' => '0',
      'grid_precipitation' => '0',
      'grid_temperature' => '0',
      'small_map_for_climate_stations' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'map_page_for_climate_stations_openlayers_1' => '0',
      'administrative_boundaries' => 'boundaries',
      'map_block_for_climate_stations_openlayers_1' => 'ccis_marker_green_yellow',
      'geofield_formatter' => 'ccis_marker_green_yellow_active_1',
    ),
    'layer_styles_select' => array(
      'big_map_for_climate_stations' => '0',
      'grid_precipitation' => '0',
      'grid_temperature' => '0',
      'small_map_for_climate_stations' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'map_page_for_climate_stations_openlayers_1' => '0',
      'administrative_boundaries' => '0',
      'map_block_for_climate_stations_openlayers_1' => 'ccis_marker_green_yellow',
      'geofield_formatter' => 'ccis_marker_green_yellow_active_1',
    ),
    'layer_styles_temporary' => array(
      'big_map_for_climate_stations' => '0',
      'grid_precipitation' => '0',
      'grid_temperature' => '0',
      'small_map_for_climate_stations' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'map_page_for_climate_stations_openlayers_1' => '0',
      'administrative_boundaries' => '0',
      'map_block_for_climate_stations_openlayers_1' => 'ccis_marker_green_yellow',
      'geofield_formatter' => 'ccis_marker_green_yellow_active_1',
    ),
    'layer_activated' => array(
      'administrative_boundaries' => 'administrative_boundaries',
      'map_block_for_climate_stations_openlayers_1' => 'map_block_for_climate_stations_openlayers_1',
      'geofield_formatter' => 'geofield_formatter',
      'big_map_for_climate_stations' => 0,
      'grid_precipitation' => 0,
      'grid_temperature' => 0,
      'small_map_for_climate_stations' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'map_page_for_climate_stations_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'administrative_boundaries' => 'administrative_boundaries',
      'map_block_for_climate_stations_openlayers_1' => 0,
      'geofield_formatter' => 0,
      'big_map_for_climate_stations' => 0,
      'grid_precipitation' => 0,
      'grid_temperature' => 0,
      'small_map_for_climate_stations' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'map_page_for_climate_stations_openlayers_1' => 0,
    ),
    'projection' => 'EPSG:900913',
    'displayProjection' => 'EPSG:4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['small_map_for_climate_stations'] = $openlayers_maps;

  return $export;
}
