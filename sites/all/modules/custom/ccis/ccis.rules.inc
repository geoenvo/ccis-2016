<?php
/**
 * @file Provides hooks for rules
 */

/**
 * Implements hook_rules_action_info()
 */
function ccis_rules_action_info() {
  $actions = array();
  $actions['ccis_reverse_geocode'] = array(
    'label' => t('Reverse geocode an address'),
    'group' => t('Geocoder'),
    'named parameter' => TRUE,
    'base' => 'ccis_reverse_geocode_rule_action',
    'parameter' => array(
      'latitude' => array(
        'type' => 'decimal',
        'label' => t('Latitude'),
        'required' => TRUE,
      ),
      'longitude' => array(
        'type' => 'decimal',
        'label' => t('Longitude'),
        'required' => TRUE,
      ),
    ),
    'provides' => array(
      'address' => array(
        'type' => 'text',
        'label' => t('Formatted address string'),
        'description' => t('Returns a address like: 19, Am Markt, Altstadt, Mitte (Stadtteil), Stadtbezirk Bremen-Mitte, Bremen, Free and Hanseatic City of Bremen, 28195, Germany, European Union.')
      ),
    ),
  );

  return $actions;
}

/**
 * Use the reverse geocoder from openstreetmap.org.
 *
 * @link http://wiki.openstreetmap.org/wiki/Nominatim
 */
function ccis_reverse_geocode_rule_action($values) {
  #http://nominatim.openstreetmap.org/reverse?format=xml&lat=53.075&lon=8.80708&zoom=18&addressdetails=1&accept-language=en
  if (!empty($values['latitude']) && !empty($values['longitude'])) {
    $query = array(
      'format' => 'json',
      'lat' => $values['latitude'],
      'lon' => $values['longitude'],
      'zoom' => 18,

    );
    $url = url('http://nominatim.openstreetmap.org/reverse', array('query' => $query));
    $result = drupal_http_request($url);
    if (isset($result->error)) {
      $args = array(
        '@code' => $result->code,
        '@error' => $result->error,
       );
      $msg = t("HTTP request to http://nominatim.openstreetmap.org/reverse failed.\nCode: @code\nError: @error", $args);
      throw new RulesEvaluationException($msg);
    }
    $data = json_decode($result->data);
    $address = !empty($data->display_name) ? $data->display_name : '';
    return array('address' => $address);
  }
}
