<?php
/**
 * @file
 * ccis_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ccis_rules_default_rules_configuration() {
  $items = array();
  $items['rules_geocodetoaddress'] = entity_import('rules_config', '{ "rules_geocodetoaddress" : {
      "LABEL" : "geocodetoaddress",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "ccis" ],
      "ON" : { "node_update--weather_station" : { "bundle" : "weather_station" } },
      "IF" : [ { "data_is_empty" : { "data" : [ "node:field-address-data" ] } } ],
      "DO" : [
        { "ccis_reverse_geocode" : {
            "USING" : {
              "latitude" : [ "node:field-station-geodata:lat" ],
              "longitude" : [ "node:field-station-geodata:lon" ]
            },
            "PROVIDE" : { "address" : { "address" : "Formatted address string" } }
          }
        },
        { "data_set" : { "data" : [ "node:field-address-data" ], "value" : [ "address" ] } }
      ]
    }
  }');
  return $items;
}
