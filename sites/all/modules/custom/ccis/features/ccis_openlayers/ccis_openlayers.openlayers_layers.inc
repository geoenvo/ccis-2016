<?php
/**
 * @file
 * ccis_openlayers.openlayers_layers.inc
 */

/**
 * Implements hook_openlayers_layers().
 */
function ccis_openlayers_openlayers_layers() {
  $export = array();

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'big_map_for_climate_stations';
  $openlayers_layers->title = 'Big map for climate stations';
  $openlayers_layers->description = 'Big map for climate stations';
  $openlayers_layers->data = array(
    'views' => array(
      'view' => 'big_maps_for_weather_stations',
      'display' => 'openlayers_1',
    ),
    'projection' => array(
      0 => 'EPSG:4326',
    ),
    'isBaseLayer' => 0,
    'layer_type' => 'openlayers_views_vector',
    'layer_handler' => 'openlayers_views_vector',
    'vector' => TRUE,
    'type' => 'Vector',
    'url' => array(),
    'options' => array(),
    'events' => array(),
    'serverResolutions' => array(
      0 => 156543.0339,
      1 => 78271.51695,
      2 => 39135.758475,
      3 => 19567.8792375,
      4 => 9783.93961875,
      5 => 4891.969809375,
      6 => 2445.9849046875,
      7 => 1222.9924523438,
      8 => 611.49622617188,
      9 => 305.74811308594,
      10 => 152.87405654297,
      11 => 76.437028271484,
      12 => 38.218514135742,
      13 => 19.109257067871,
      14 => 9.5546285339355,
      15 => 4.7773142669678,
      16 => 2.3886571334839,
      17 => 1.1943285667419,
      18 => 0.59716428337097,
      19 => 0.29858214169741,
      20 => 0.1492910708487,
      21 => 0.074645535424352,
    ),
    'resolutions' => array(
      0 => 156543.0339,
      1 => 78271.51695,
      2 => 39135.758475,
      3 => 19567.8792375,
      4 => 9783.93961875,
      5 => 4891.969809375,
      6 => 2445.9849046875,
      7 => 1222.9924523438,
      8 => 611.49622617188,
      9 => 305.74811308594,
      10 => 152.87405654297,
      11 => 76.437028271484,
      12 => 38.218514135742,
      13 => 19.109257067871,
      14 => 9.5546285339355,
      15 => 4.7773142669678,
      16 => 2.3886571334839,
      17 => 1.1943285667419,
      18 => 0.59716428337097,
      19 => 0.29858214169741,
      20 => 0.1492910708487,
      21 => 0.074645535424352,
    ),
    'base_url' => NULL,
    'transitionEffect' => 'resize',
    'weight' => 0,
  );
  $export['big_map_for_climate_stations'] = $openlayers_layers;

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'boundaries_bundeslaender_900913';
  $openlayers_layers->title = 'Administrative Boundaries';
  $openlayers_layers->description = 'administrative boundaries of the german bundeslaender';
  $openlayers_layers->data = array(
    'base_url' => 'http://144.76.110.35:8080/geoserver/dashboard/wms',
    'params' => array(
      'buffer' => '2',
      'ratio' => '1.5',
      'singleTile' => 0,
    ),
    'options' => array(
      'TRANSPARENT' => 'true',
      'exceptions' => 'application/vnd.ogc.se_inimage',
      'format' => 'image/png',
      'layers' => array(
        0 => 'dashboard:bundeslaender_900913',
      ),
      'styles' => '',
    ),
    'projection' => array(
      0 => 'EPSG:900913',
    ),
    'isBaseLayer' => 0,
    'layer_type' => 'openlayers_layer_type_wms',
    'layer_handler' => 'wms',
    'transitionEffect' => 'resize',
    'weight' => 0,
    'serverResolutions' => array(
      0 => 156543.0339,
      1 => 78271.51695,
      2 => 39135.758475,
      3 => 19567.8792375,
      4 => 9783.93961875,
      5 => 4891.969809375,
      6 => 2445.9849046875,
      7 => 1222.9924523438,
      8 => 611.49622617188,
      9 => 305.74811308594,
      10 => 152.87405654297,
      11 => 76.437028271484,
      12 => 38.218514135742,
      13 => 19.109257067871,
      14 => 9.5546285339355,
      15 => 4.7773142669678,
      16 => 2.3886571334839,
      17 => 1.1943285667419,
      18 => 0.59716428337097,
      19 => 0.29858214169741,
      20 => 0.1492910708487,
      21 => 0.074645535424352,
    ),
    'resolutions' => array(
      0 => 156543.0339,
      1 => 78271.51695,
      2 => 39135.758475,
      3 => 19567.8792375,
      4 => 9783.93961875,
      5 => 4891.969809375,
      6 => 2445.9849046875,
      7 => 1222.9924523438,
      8 => 611.49622617188,
      9 => 305.74811308594,
      10 => 152.87405654297,
      11 => 76.437028271484,
      12 => 38.218514135742,
      13 => 19.109257067871,
      14 => 9.5546285339355,
      15 => 4.7773142669678,
      16 => 2.3886571334839,
      17 => 1.1943285667419,
      18 => 0.59716428337097,
      19 => 0.29858214169741,
      20 => 0.1492910708487,
      21 => 0.074645535424352,
    ),
  );
  $export['boundaries_bundeslaender_900913'] = $openlayers_layers;

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'small_map_for_climate_stations';
  $openlayers_layers->title = 'Small map for climate stations';
  $openlayers_layers->description = 'Small map for climate stations';
  $openlayers_layers->data = array(
    'views' => array(
      'view' => 'ol_stations',
      'display' => 'openlayers_1',
    ),
    'projection' => array(
      0 => 'EPSG:4326',
    ),
    'isBaseLayer' => 0,
    'layer_type' => 'openlayers_views_vector',
    'layer_handler' => 'openlayers_views_vector',
    'vector' => TRUE,
    'type' => 'Vector',
    'url' => array(),
    'options' => array(),
    'events' => array(),
    'serverResolutions' => array(
      0 => 156543.0339,
      1 => 78271.51695,
      2 => 39135.758475,
      3 => 19567.8792375,
      4 => 9783.93961875,
      5 => 4891.969809375,
      6 => 2445.9849046875,
      7 => 1222.9924523438,
      8 => 611.49622617188,
      9 => 305.74811308594,
      10 => 152.87405654297,
      11 => 76.437028271484,
      12 => 38.218514135742,
      13 => 19.109257067871,
      14 => 9.5546285339355,
      15 => 4.7773142669678,
      16 => 2.3886571334839,
      17 => 1.1943285667419,
      18 => 0.59716428337097,
      19 => 0.29858214169741,
      20 => 0.1492910708487,
      21 => 0.074645535424352,
    ),
    'resolutions' => array(
      0 => 156543.0339,
      1 => 78271.51695,
      2 => 39135.758475,
      3 => 19567.8792375,
      4 => 9783.93961875,
      5 => 4891.969809375,
      6 => 2445.9849046875,
      7 => 1222.9924523438,
      8 => 611.49622617188,
      9 => 305.74811308594,
      10 => 152.87405654297,
      11 => 76.437028271484,
      12 => 38.218514135742,
      13 => 19.109257067871,
      14 => 9.5546285339355,
      15 => 4.7773142669678,
      16 => 2.3886571334839,
      17 => 1.1943285667419,
      18 => 0.59716428337097,
      19 => 0.29858214169741,
      20 => 0.1492910708487,
      21 => 0.074645535424352,
    ),
    'base_url' => NULL,
    'transitionEffect' => 'resize',
    'weight' => 0,
  );
  $export['small_map_for_climate_stations'] = $openlayers_layers;

  return $export;
}
