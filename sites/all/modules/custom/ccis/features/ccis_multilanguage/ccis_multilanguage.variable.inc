<?php
/**
 * @file
 * ccis_multilanguage.variable.inc
 */

/**
 * Implements hook_variable_realm_default_variables().
 */
function ccis_multilanguage_variable_realm_default_variables() {
$realm_variables = array();
  $realm_variables['language']['de'] = array();
  $realm_variables['language']['en'] = array();
  $realm_variables['language']['es'] = array();
  $realm_variables['language']['fr'] = array();
  $realm_variables['language']['id'] = array();

return $realm_variables;
}
