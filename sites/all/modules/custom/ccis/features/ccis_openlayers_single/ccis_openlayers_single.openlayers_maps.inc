<?php
/**
 * @file
 * ccis_openlayers_single.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function ccis_openlayers_single_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'stationsingle';
  $openlayers_maps->title = 'Weather station';
  $openlayers_maps->description = 'Map for single Station location';
  $openlayers_maps->data = array(
    'width' => '600px',
    'height' => '400px',
    'image_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/contrib/openlayers/themes/default_dark/style.css',
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
      'openlayers_behavior_fullscreen' => array(
        'activated' => 0,
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'sortBaseLayer' => '0',
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
        'maximizeDefault' => 0,
        'div' => '',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 0,
      ),
      'openlayers_behavior_permalink' => array(
        'anchor' => 0,
      ),
      'openlayers_behavior_zoomtomaxextent' => array(),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
      'boundaries_bundeslaender_900913' => 'boundaries_bundeslaender_900913',
      'geofield_formatter' => 'geofield_formatter',
    ),
    'layer_weight' => array(
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'boundaries_bundeslaender_900913' => '0',
      'geofield_formatter' => '1',
      'ol_stations_openlayers_1' => '2',
    ),
    'layer_styles' => array(
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'ol_stations_openlayers_1' => 'default_marker_black',
      'geofield_formatter' => 'default_marker_black',
      'boundaries_bundeslaender_900913' => '0',
    ),
    'layer_styles_select' => array(
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'ol_stations_openlayers_1' => 'default_marker_black_small',
      'geofield_formatter' => '0',
      'boundaries_bundeslaender_900913' => '0',
    ),
    'layer_styles_temporary' => array(
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'ol_stations_openlayers_1' => '0',
      'geofield_formatter' => '0',
      'boundaries_bundeslaender_900913' => '0',
    ),
    'layer_activated' => array(
      'geofield_formatter' => 'geofield_formatter',
      'boundaries_bundeslaender_900913' => 'boundaries_bundeslaender_900913',
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'ol_stations_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'boundaries_bundeslaender_900913' => 'boundaries_bundeslaender_900913',
      'geofield_formatter' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
      'ol_stations_openlayers_1' => 0,
    ),
    'projection' => 'EPSG:900913',
    'displayProjection' => 'EPSG:4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['stationsingle'] = $openlayers_maps;

  return $export;
}
