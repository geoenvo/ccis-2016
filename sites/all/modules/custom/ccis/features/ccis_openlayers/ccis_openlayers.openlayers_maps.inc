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
  $openlayers_maps->name = 'clone_of_clone_of_geofield_formatter_map';
  $openlayers_maps->title = 'Big map for Weather stations';
  $openlayers_maps->description = 'Big map for Weather stations';
  $openlayers_maps->data = array(
    'width' => '940px',
    'height' => '570px',
    'image_path' => 'sites/all/modules/custom/ccis/css/ol/img/',
    'css_path' => 'sites/all/modules/custom/ccis/css/ol/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '9.931640580102298, 51.275',
        'zoom' => '6',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_cluster' => array(
        'clusterlayer' => array(
          'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
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
          'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
          'geofield_formatter' => 0,
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
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
          'boundaries_bundeslaender_900913' => 0,
          'ol_stations_openlayers_1' => 0,
        ),
        'point_zoom_level' => '5',
        'zoomtolayer_scale' => '1',
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
      'boundaries_bundeslaender_900913' => 'boundaries_bundeslaender_900913',
      'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
      'geofield_formatter' => 'geofield_formatter',
    ),
    'layer_weight' => array(
      'boundaries_bundeslaender_900913' => '0',
      'openlayers_kml_example' => '0',
      'clone_of_ol_stations_openlayers_1' => '0',
      'big_maps_for_weather_stations_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'ol_stations_openlayers_1' => '1',
      'geofield_formatter' => '2',
    ),
    'layer_styles' => array(
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'big_maps_for_weather_stations_openlayers_1' => '0',
      'clone_of_ol_stations_openlayers_1' => '0',
      'boundaries_bundeslaender_900913' => '0',
      'ol_stations_openlayers_1' => 'ccis_marker_green_yellow',
      'geofield_formatter' => 'ccis_marker_green_yellow_active_1',
    ),
    'layer_styles_select' => array(
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'big_maps_for_weather_stations_openlayers_1' => '0',
      'clone_of_ol_stations_openlayers_1' => '0',
      'boundaries_bundeslaender_900913' => '0',
      'ol_stations_openlayers_1' => 'ccis_marker_green_yellow',
      'geofield_formatter' => 'ccis_marker_green_yellow_active_1',
    ),
    'layer_styles_temporary' => array(
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'big_maps_for_weather_stations_openlayers_1' => '0',
      'clone_of_ol_stations_openlayers_1' => '0',
      'boundaries_bundeslaender_900913' => '0',
      'ol_stations_openlayers_1' => 'ccis_marker_green_yellow',
      'geofield_formatter' => 'ccis_marker_green_yellow_active_1',
    ),
    'layer_activated' => array(
      'boundaries_bundeslaender_900913' => 'boundaries_bundeslaender_900913',
      'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
      'geofield_formatter' => 'geofield_formatter',
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'big_maps_for_weather_stations_openlayers_1' => 0,
      'clone_of_ol_stations_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'boundaries_bundeslaender_900913' => 'boundaries_bundeslaender_900913',
      'ol_stations_openlayers_1' => 0,
      'geofield_formatter' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'big_maps_for_weather_stations_openlayers_1' => 0,
      'clone_of_ol_stations_openlayers_1' => 0,
    ),
    'projection' => 'EPSG:900913',
    'displayProjection' => 'EPSG:4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['clone_of_clone_of_geofield_formatter_map'] = $openlayers_maps;

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'clone_of_geofield_formatter_map';
  $openlayers_maps->title = 'Weather stations';
  $openlayers_maps->description = 'Weather stations';
  $openlayers_maps->data = array(
    'width' => '950px',
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
          'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
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
          'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
          'geofield_formatter' => 0,
        ),
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
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
          'boundaries_bundeslaender_900913' => 0,
          'ol_stations_openlayers_1' => 0,
        ),
        'point_zoom_level' => '5',
        'zoomtolayer_scale' => '1',
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
      'boundaries_bundeslaender_900913' => 'boundaries_bundeslaender_900913',
      'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
      'geofield_formatter' => 'geofield_formatter',
    ),
    'layer_weight' => array(
      'boundaries_bundeslaender_900913' => '0',
      'openlayers_kml_example' => '0',
      'clone_of_ol_stations_openlayers_1' => '0',
      'big_maps_for_weather_stations_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'ol_stations_openlayers_1' => '1',
      'geofield_formatter' => '2',
    ),
    'layer_styles' => array(
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'big_maps_for_weather_stations_openlayers_1' => '0',
      'clone_of_ol_stations_openlayers_1' => '0',
      'boundaries_bundeslaender_900913' => '0',
      'ol_stations_openlayers_1' => 'ccis_marker_green_yellow',
      'geofield_formatter' => 'ccis_marker_green_yellow_active_1',
    ),
    'layer_styles_select' => array(
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'big_maps_for_weather_stations_openlayers_1' => '0',
      'clone_of_ol_stations_openlayers_1' => '0',
      'boundaries_bundeslaender_900913' => '0',
      'ol_stations_openlayers_1' => 'ccis_marker_green_yellow',
      'geofield_formatter' => 'ccis_marker_green_yellow_active_1',
    ),
    'layer_styles_temporary' => array(
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'big_maps_for_weather_stations_openlayers_1' => '0',
      'clone_of_ol_stations_openlayers_1' => '0',
      'boundaries_bundeslaender_900913' => '0',
      'ol_stations_openlayers_1' => 'ccis_marker_green_yellow',
      'geofield_formatter' => 'ccis_marker_green_yellow_active_1',
    ),
    'layer_activated' => array(
      'boundaries_bundeslaender_900913' => 'boundaries_bundeslaender_900913',
      'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
      'geofield_formatter' => 'geofield_formatter',
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'big_maps_for_weather_stations_openlayers_1' => 0,
      'clone_of_ol_stations_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'boundaries_bundeslaender_900913' => 'boundaries_bundeslaender_900913',
      'ol_stations_openlayers_1' => 0,
      'geofield_formatter' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'big_maps_for_weather_stations_openlayers_1' => 0,
      'clone_of_ol_stations_openlayers_1' => 0,
    ),
    'projection' => 'EPSG:900913',
    'displayProjection' => 'EPSG:4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['clone_of_geofield_formatter_map'] = $openlayers_maps;

  return $export;
}
