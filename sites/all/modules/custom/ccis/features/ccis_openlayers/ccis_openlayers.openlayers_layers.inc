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
  $openlayers_layers->name = 'administrative_boundaries';
  $openlayers_layers->title = 'Administrative Boundaries';
  $openlayers_layers->description = 'The administrative boundaries ';
  $openlayers_layers->data = array(
    'url' => 'sites/all/modules/custom/ccis/geodata/german_boundaries_3857.geojson',
    'useBBOX' => 0,
    'resFactor' => '1',
    'useScript' => 0,
    'callbackKey' => '',
    'geojson_data' => '',
    'projection' => array(
      0 => 'EPSG:3857',
    ),
    'isBaseLayer' => 0,
    'layer_type' => 'openlayers_layer_type_geojson',
    'layer_handler' => 'geojson',
    'serverResolutions' => array(
      0 => 0.703125,
      1 => 0.3515625,
      2 => 0.17578125,
      3 => 0.087890625,
      4 => 0.0439453125,
      5 => 0.02197265625,
      6 => 0.010986328125,
      7 => 0.0054931640625,
      8 => 0.00274658203125,
      9 => 0.001373291015625,
      10 => 0.0006866455078125,
      11 => 0.00034332275390625,
      12 => 0.00017166137695312,
      13 => 8.5830688476562E-5,
      14 => 4.2915344238281E-5,
      15 => 2.1457672119141E-5,
      16 => 1.072883605957E-5,
    ),
    'vector' => TRUE,
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
  $export['administrative_boundaries'] = $openlayers_layers;

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
  $openlayers_layers->name = 'grid_precipitation';
  $openlayers_layers->title = 'Precipitation Grid';
  $openlayers_layers->description = 'Yearly precipitation amount in the year 2000';
  $openlayers_layers->data = array(
    'method' => 'url',
    'url' => 'sites/all/modules/custom/ccis/geodata/Prec_DE_2000_4326.kml',
    'file' => 0,
    'raw' => '',
    'formatOptions' => array(
      'extractStyles' => TRUE,
      'extractTracks' => FALSE,
      'extractAttributes' => TRUE,
    ),
    'projection' => array(
      0 => 'EPSG:4326',
    ),
    'isBaseLayer' => 0,
    'layer_type' => 'openlayers_layer_type_kml',
    'layer_handler' => 'kml',
    'resolutions' => array(
      0 => 0.703125,
      1 => 0.3515625,
      2 => 0.17578125,
      3 => 0.087890625,
      4 => 0.0439453125,
      5 => 0.02197265625,
      6 => 0.010986328125,
      7 => 0.0054931640625,
      8 => 0.00274658203125,
      9 => 0.001373291015625,
      10 => 0.0006866455078125,
      11 => 0.00034332275390625,
      12 => 0.00017166137695312,
      13 => 8.5830688476562E-5,
      14 => 4.2915344238281E-5,
      15 => 2.1457672119141E-5,
      16 => 1.072883605957E-5,
    ),
    'serverResolutions' => array(
      0 => 0.703125,
      1 => 0.3515625,
      2 => 0.17578125,
      3 => 0.087890625,
      4 => 0.0439453125,
      5 => 0.02197265625,
      6 => 0.010986328125,
      7 => 0.0054931640625,
      8 => 0.00274658203125,
      9 => 0.001373291015625,
      10 => 0.0006866455078125,
      11 => 0.00034332275390625,
      12 => 0.00017166137695312,
      13 => 8.5830688476562E-5,
      14 => 4.2915344238281E-5,
      15 => 2.1457672119141E-5,
      16 => 1.072883605957E-5,
    ),
    'maxExtent' => array(
      0 => -180,
      1 => -90,
      2 => 180,
      3 => 90,
    ),
    'vector' => TRUE,
    'base_url' => NULL,
    'transitionEffect' => 'resize',
    'weight' => 0,
  );
  $export['grid_precipitation'] = $openlayers_layers;

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'grid_temperature';
  $openlayers_layers->title = 'Temperature Grid';
  $openlayers_layers->description = 'Montly mean temperature derived from data for years 1981 - 2010';
  $openlayers_layers->data = array(
    'url' => 'sites/all/modules/custom/ccis/geodata/grid_temp_monthly_12_ch.geojson',
    'useBBOX' => 1,
    'resFactor' => '1',
    'useScript' => 0,
    'callbackKey' => '',
    'geojson_data' => '',
    'projection' => array(
      0 => 'EPSG:4326',
    ),
    'isBaseLayer' => 0,
    'layer_type' => 'openlayers_layer_type_geojson',
    'layer_handler' => 'geojson',
    'serverResolutions' => array(
      0 => 0.703125,
      1 => 0.3515625,
      2 => 0.17578125,
      3 => 0.087890625,
      4 => 0.0439453125,
      5 => 0.02197265625,
      6 => 0.010986328125,
      7 => 0.0054931640625,
      8 => 0.00274658203125,
      9 => 0.001373291015625,
      10 => 0.0006866455078125,
      11 => 0.00034332275390625,
      12 => 0.00017166137695312,
      13 => 8.5830688476562E-5,
      14 => 4.2915344238281E-5,
      15 => 2.1457672119141E-5,
      16 => 1.072883605957E-5,
    ),
    'vector' => TRUE,
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
  $export['grid_temperature'] = $openlayers_layers;

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
