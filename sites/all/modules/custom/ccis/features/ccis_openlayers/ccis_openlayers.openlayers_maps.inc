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
  $openlayers_maps->name = 'clone_of_geofield_formatter_map';
  $openlayers_maps->title = 'Wheather stations';
  $openlayers_maps->description = 'Wheather stations';
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
      'openlayers_behavior_cluster' => array(
        'clusterlayer' => array(
          'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
          'geofield_formatter' => 0,
          'kml_test' => 0,
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
        'panIcons' => 1,
      ),
      'openlayers_behavior_permalink' => array(
        'anchor' => 1,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
          'geofield_formatter' => 0,
          'kml_test' => 0,
        ),
        'panMapIfOutOfView' => 0,
        'keepInMap' => 1,
      ),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => array(
          'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
          'mapquest_osm' => 0,
          'mapquest_openaerial' => 0,
          'geofield_formatter' => 0,
          'kml_test' => 0,
        ),
        'point_zoom_level' => '5',
        'zoomtolayer_scale' => '1',
      ),
      'openlayers_behavior_zoomtomaxextent' => array(),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
      'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
    ),
    'layer_weight' => array(
      'geofield_formatter' => '0',
      'kml_test' => '0',
      'ol_stations_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'openlayers_kml_example' => '0',
      'bundeslaender_900913_2' => '0',
      'googletest' => '0',
      'bundeslaender_900913' => '0',
    ),
    'layer_styles' => array(
      'bundeslaender_900913' => '0',
      'bundeslaender_900913_2' => '0',
      'googletest' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
      'kml_test' => '0',
      'ol_stations_openlayers_1' => 'default_marker_black',
    ),
    'layer_styles_select' => array(
      'bundeslaender_900913' => '0',
      'bundeslaender_900913_2' => '0',
      'googletest' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
      'kml_test' => '0',
      'ol_stations_openlayers_1' => 'default_marker_black',
    ),
    'layer_styles_temporary' => array(
      'bundeslaender_900913' => '0',
      'bundeslaender_900913_2' => '0',
      'googletest' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
      'kml_test' => '0',
      'ol_stations_openlayers_1' => '0',
    ),
    'layer_activated' => array(
      'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
      'geofield_formatter' => 0,
      'kml_test' => 0,
      'bundeslaender_900913' => 0,
      'bundeslaender_900913_2' => 0,
      'googletest' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
    ),
    'layer_switcher' => array(
      'ol_stations_openlayers_1' => 'ol_stations_openlayers_1',
      'geofield_formatter' => 0,
      'kml_test' => 0,
      'bundeslaender_900913' => 0,
      'bundeslaender_900913_2' => 0,
      'googletest' => 0,
      'openlayers_kml_example' => 0,
      'openlayers_geojson_picture_this' => 0,
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
