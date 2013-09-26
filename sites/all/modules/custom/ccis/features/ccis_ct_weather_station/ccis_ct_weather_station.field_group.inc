<?php
/**
 * @file
 * ccis_ct_weather_station.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ccis_ct_weather_station_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data|node|weather_station|form';
  $field_group->group_name = 'group_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data',
    'weight' => '25',
    'children' => array(
      0 => 'field_dataunits',
      1 => 'field_dataquality',
      2 => 'field_datatime',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-data field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_data|node|weather_station|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_instrumentation|node|weather_station|form';
  $field_group->group_name = 'group_instrumentation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Instrumentation',
    'weight' => '13',
    'children' => array(
      0 => 'field_instrumentationtype',
      1 => 'field_traininglevel',
      2 => 'field_observedelements',
      3 => 'field_observingtimes',
      4 => 'field_units',
      5 => 'field_instructions',
      6 => 'field_routinemaintenance',
      7 => 'field_itemsreplacement',
      8 => 'field_observercorrections',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Instrumentation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-instrumentation field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_instrumentation|node|weather_station|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadatainformation|node|weather_station|form';
  $field_group->group_name = 'group_metadatainformation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata Information',
    'weight' => '26',
    'children' => array(
      0 => 'field_mdmetadata',
      1 => 'field_fileidentifier',
      2 => 'field_languagecode',
      3 => 'field_md_charactersetcode',
      4 => 'field_md_scopecode',
      5 => 'field_ci_responsibleparty',
      6 => 'field_organisationname',
      7 => 'field_ci_contact',
      8 => 'field_ci_address',
      9 => 'field_electronicmailaddress',
      10 => 'field_ci_rolecode',
      11 => 'field_datestamp',
      12 => 'field_metadatastandardname',
      13 => 'field_metadatastandardversion',
      14 => 'field_dataseturi',
      15 => 'field_metadataconstraints',
      16 => 'field_metadatamaintenance',
      17 => 'field_ci_onlineresource',
      18 => 'field_beginposition',
      19 => 'field_endposition',
      20 => 'field_category',
      21 => 'field_keyword',
      22 => 'field_extent',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Metadata Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-metadatainformation field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_metadatainformation|node|weather_station|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organisation|node|weather_station|form';
  $field_group->group_name = 'group_organisation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Organization',
    'weight' => '12',
    'children' => array(
      0 => 'field_organisation',
      1 => 'field_address',
      2 => 'field_postcode',
      3 => 'field_city',
      4 => 'field_region',
      5 => 'field_country',
      6 => 'field_phone',
      7 => 'field_fax',
      8 => 'field_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Organization',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-organisation field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_organisation|node|weather_station|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stationcontact|node|weather_station|form';
  $field_group->group_name = 'group_stationcontact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Station Contact',
    'weight' => '14',
    'children' => array(
      0 => 'field_stationcontact',
      1 => 'field_stationaddress',
      2 => 'field_stationpostcode',
      3 => 'field_stationcity',
      4 => 'field_stationprovince',
      5 => 'field_stationcountry',
      6 => 'field_stationphone',
      7 => 'field_stationfax',
      8 => 'field_stationemail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Station Contact',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-stationcontact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_stationcontact|node|weather_station|form'] = $field_group;

  return $export;
}
