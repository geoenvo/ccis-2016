<?php
/**
 * @file
 * ccis_openlayers.openlayers_styles.inc
 */

/**
 * Implements hook_openlayers_styles().
 */
function ccis_openlayers_openlayers_styles() {
  $export = array();

  $openlayers_styles = new stdClass();
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'boundaries';
  $openlayers_styles->title = 'boundaries';
  $openlayers_styles->description = 'Red stroke for boundary polygons';
  $openlayers_styles->data = array(
    'pointRadius' => 6,
    'fillColor' => '#FFFFFF',
    'strokeColor' => '#BA4040',
    'strokeWidth' => 1,
    'fillOpacity' => 0.01,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );
  $export['boundaries'] = $openlayers_styles;

  $openlayers_styles = new stdClass();
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'ccis_marker_green_yellow';
  $openlayers_styles->title = 'CCIS Marker Green Yellow';
  $openlayers_styles->description = 'Green yellow Marker for the CCIS map.';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/modules/custom/ccis/css/ol/markers/marker.png',
    'pointRadius' => 20,
    'fillColor' => '#EE9900',
    'strokeColor' => '#EE9900',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );
  $export['ccis_marker_green_yellow'] = $openlayers_styles;

  $openlayers_styles = new stdClass();
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'ccis_marker_green_yellow_active';
  $openlayers_styles->title = 'CCIS Marker Green Yellow Active';
  $openlayers_styles->description = 'Active green yellow Marker for a selected station in the CCIS map';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/modules/custom/ccis/css/ol/markers/marker_active.png',
    'pointRadius' => 20,
    'fillColor' => '#EE9900',
    'strokeColor' => '#EE9900',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );
  $export['ccis_marker_green_yellow_active'] = $openlayers_styles;

  $openlayers_styles = new stdClass();
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'ccis_marker_green_yellow_active_1';
  $openlayers_styles->title = 'CCIS Marker Green Yellow Active 1';
  $openlayers_styles->description = 'Green yellow Marker for first selected station in the CCIS map.';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/modules/custom/ccis/css/ol/markers/marker_active_1.png',
    'pointRadius' => 20,
    'fillColor' => '#EE9900',
    'strokeColor' => '#EE9900',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );
  $export['ccis_marker_green_yellow_active_1'] = $openlayers_styles;

  $openlayers_styles = new stdClass();
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'ccis_marker_green_yellow_active_2';
  $openlayers_styles->title = 'CCIS Marker Green Yellow Active 2';
  $openlayers_styles->description = 'Green yellow Marker for second selected station in the CCIS map.';
  $openlayers_styles->data = array(
    'externalGraphic' => 'sites/all/modules/custom/ccis/css/ol/markers/marker_active_2.png',
    'pointRadius' => 20,
    'fillColor' => '#EE9900',
    'strokeColor' => '#EE9900',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );
  $export['ccis_marker_green_yellow_active_2'] = $openlayers_styles;

  return $export;
}
