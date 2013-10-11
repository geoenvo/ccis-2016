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
  $field_group->identifier = 'group_data|node|weather_station|default';
  $field_group->group_name = 'group_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data ',
    'weight' => '14',
    'children' => array(
      0 => 'field_datacodes',
      1 => 'field_dataquality',
      2 => 'field_datatime',
      3 => 'field_dataunits',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-data field-group-fieldset',
      ),
    ),
  );
  $export['group_data|node|weather_station|default'] = $field_group;

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
      0 => 'field_datacodes',
      1 => 'field_dataquality',
      2 => 'field_datatime',
      3 => 'field_dataunits',
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
  $field_group->identifier = 'group_data|node|weather_station|teaser';
  $field_group->group_name = 'group_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data ',
    'weight' => '14',
    'children' => array(
      0 => 'field_datacodes',
      1 => 'field_dataquality',
      2 => 'field_datatime',
      3 => 'field_dataunits',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-data field-group-fieldset',
      ),
    ),
  );
  $export['group_data|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_instrumentation|node|weather_station|default';
  $field_group->group_name = 'group_instrumentation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Instrumentation',
    'weight' => '11',
    'children' => array(
      0 => 'field_instructions',
      1 => 'field_instrumentationtype',
      2 => 'field_itemsreplacement',
      3 => 'field_observedelements',
      4 => 'field_observercorrections',
      5 => 'field_observingtimes',
      6 => 'field_routinemaintenance',
      7 => 'field_traininglevel',
      8 => 'field_units',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_instrumentation|node|weather_station|default'] = $field_group;

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
    'weight' => '12',
    'children' => array(
      0 => 'field_instructions',
      1 => 'field_instrumentationtype',
      2 => 'field_itemsreplacement',
      3 => 'field_observedelements',
      4 => 'field_observercorrections',
      5 => 'field_observingtimes',
      6 => 'field_routinemaintenance',
      7 => 'field_traininglevel',
      8 => 'field_units',
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
  $field_group->identifier = 'group_instrumentation|node|weather_station|teaser';
  $field_group->group_name = 'group_instrumentation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Instrumentation',
    'weight' => '11',
    'children' => array(
      0 => 'field_instructions',
      1 => 'field_instrumentationtype',
      2 => 'field_itemsreplacement',
      3 => 'field_observedelements',
      4 => 'field_observercorrections',
      5 => 'field_observingtimes',
      6 => 'field_routinemaintenance',
      7 => 'field_traininglevel',
      8 => 'field_units',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_instrumentation|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata_information|node|weather_station|default';
  $field_group->group_name = 'group_metadata_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata Information',
    'weight' => '19',
    'children' => array(
      0 => 'field_beginposition',
      1 => 'field_category',
      2 => 'field_ci_address',
      3 => 'field_ci_contact',
      4 => 'field_ci_onlineresource',
      5 => 'field_ci_responsibleparty',
      6 => 'field_ci_rolecode',
      7 => 'field_dataseturi',
      8 => 'field_datestamp',
      9 => 'field_electronicmailaddress',
      10 => 'field_endposition',
      11 => 'field_extent',
      12 => 'field_fileidentifier',
      13 => 'field_keyword',
      14 => 'field_languagecode',
      15 => 'field_md_charactersetcode',
      16 => 'field_md_scopecode',
      17 => 'field_mdmetadata',
      18 => 'field_metadataconstraints',
      19 => 'field_metadatamaintenance',
      20 => 'field_metadatastandardname',
      21 => 'field_metadatastandardversion',
      22 => 'field_organisationname',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-metadata-information field-group-fieldset',
      ),
    ),
  );
  $export['group_metadata_information|node|weather_station|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata_information|node|weather_station|teaser';
  $field_group->group_name = 'group_metadata_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata Information',
    'weight' => '15',
    'children' => array(
      0 => 'field_beginposition',
      1 => 'field_category',
      2 => 'field_ci_address',
      3 => 'field_ci_contact',
      4 => 'field_ci_onlineresource',
      5 => 'field_ci_responsibleparty',
      6 => 'field_ci_rolecode',
      7 => 'field_dataseturi',
      8 => 'field_datestamp',
      9 => 'field_electronicmailaddress',
      10 => 'field_endposition',
      11 => 'field_extent',
      12 => 'field_fileidentifier',
      13 => 'field_keyword',
      14 => 'field_languagecode',
      15 => 'field_md_charactersetcode',
      16 => 'field_md_scopecode',
      17 => 'field_mdmetadata',
      18 => 'field_metadataconstraints',
      19 => 'field_metadatamaintenance',
      20 => 'field_metadatastandardname',
      21 => 'field_metadatastandardversion',
      22 => 'field_organisationname',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-metadata-information field-group-fieldset',
      ),
    ),
  );
  $export['group_metadata_information|node|weather_station|teaser'] = $field_group;

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
      0 => 'field_beginposition',
      1 => 'field_category',
      2 => 'field_ci_address',
      3 => 'field_ci_contact',
      4 => 'field_ci_onlineresource',
      5 => 'field_ci_responsibleparty',
      6 => 'field_ci_rolecode',
      7 => 'field_dataseturi',
      8 => 'field_datestamp',
      9 => 'field_electronicmailaddress',
      10 => 'field_endposition',
      11 => 'field_extent',
      12 => 'field_fileidentifier',
      13 => 'field_keyword',
      14 => 'field_languagecode',
      15 => 'field_md_charactersetcode',
      16 => 'field_md_scopecode',
      17 => 'field_mdmetadata',
      18 => 'field_metadataconstraints',
      19 => 'field_metadatamaintenance',
      20 => 'field_metadatastandardname',
      21 => 'field_metadatastandardversion',
      22 => 'field_organisationname',
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
    'weight' => '11',
    'children' => array(
      0 => 'field_address',
      1 => 'field_city',
      2 => 'field_country',
      3 => 'field_email',
      4 => 'field_fax',
      5 => 'field_organisation',
      6 => 'field_phone',
      7 => 'field_postcode',
      8 => 'field_region',
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
  $field_group->identifier = 'group_responsible_organization|node|weather_station|default';
  $field_group->group_name = 'group_responsible_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Responsible Organization',
    'weight' => '10',
    'children' => array(
      0 => 'field_address',
      1 => 'field_city',
      2 => 'field_country',
      3 => 'field_email',
      4 => 'field_fax',
      5 => 'field_organisation',
      6 => 'field_phone',
      7 => 'field_postcode',
      8 => 'field_region',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-responsible-organization field-group-fieldset',
      ),
    ),
  );
  $export['group_responsible_organization|node|weather_station|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_responsible_organization|node|weather_station|teaser';
  $field_group->group_name = 'group_responsible_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Responsible Organization',
    'weight' => '10',
    'children' => array(
      0 => 'field_address',
      1 => 'field_city',
      2 => 'field_country',
      3 => 'field_email',
      4 => 'field_fax',
      5 => 'field_organisation',
      6 => 'field_phone',
      7 => 'field_postcode',
      8 => 'field_region',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-responsible-organization field-group-fieldset',
      ),
    ),
  );
  $export['group_responsible_organization|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_station_contact|node|weather_station|default';
  $field_group->group_name = 'group_station_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Station Contact',
    'weight' => '12',
    'children' => array(
      0 => 'field_stationaddress',
      1 => 'field_stationcity',
      2 => 'field_stationcontact',
      3 => 'field_stationcountry',
      4 => 'field_stationemail',
      5 => 'field_stationfax',
      6 => 'field_stationphone',
      7 => 'field_stationpostcode',
      8 => 'field_stationprovince',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-station-contact field-group-fieldset',
      ),
    ),
  );
  $export['group_station_contact|node|weather_station|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_station_contact|node|weather_station|teaser';
  $field_group->group_name = 'group_station_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Station Contact',
    'weight' => '12',
    'children' => array(
      0 => 'field_stationaddress',
      1 => 'field_stationcity',
      2 => 'field_stationcontact',
      3 => 'field_stationcountry',
      4 => 'field_stationemail',
      5 => 'field_stationfax',
      6 => 'field_stationphone',
      7 => 'field_stationpostcode',
      8 => 'field_stationprovince',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-station-contact field-group-fieldset',
      ),
    ),
  );
  $export['group_station_contact|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_station_description|node|weather_station|default';
  $field_group->group_name = 'group_station_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Station Description',
    'weight' => '13',
    'children' => array(
      0 => 'field_stationabstract',
      1 => 'field_stationaccuracy',
      2 => 'field_stationadditional',
      3 => 'field_stationcrs',
      4 => 'field_stationelevation',
      5 => 'field_stationlinks',
      6 => 'field_stationmaintenance',
      7 => 'field_stationrelocation',
      8 => 'field_stationtopo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-station-description field-group-fieldset',
      ),
    ),
  );
  $export['group_station_description|node|weather_station|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_station_description|node|weather_station|form';
  $field_group->group_name = 'group_station_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Station Description',
    'weight' => '14',
    'children' => array(
      0 => 'field_stationabstract',
      1 => 'field_stationaccuracy',
      2 => 'field_stationadditional',
      3 => 'field_stationcrs',
      4 => 'field_stationelevation',
      5 => 'field_stationlinks',
      6 => 'field_stationmaintenance',
      7 => 'field_stationrelocation',
      8 => 'field_stationtopo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-station-description field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_station_description|node|weather_station|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_station_description|node|weather_station|teaser';
  $field_group->group_name = 'group_station_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Station Description',
    'weight' => '13',
    'children' => array(
      0 => 'field_stationabstract',
      1 => 'field_stationaccuracy',
      2 => 'field_stationadditional',
      3 => 'field_stationcrs',
      4 => 'field_stationelevation',
      5 => 'field_stationlinks',
      6 => 'field_stationmaintenance',
      7 => 'field_stationrelocation',
      8 => 'field_stationtopo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-station-description field-group-fieldset',
      ),
    ),
  );
  $export['group_station_description|node|weather_station|teaser'] = $field_group;

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
    'weight' => '13',
    'children' => array(
      0 => 'field_stationaddress',
      1 => 'field_stationcity',
      2 => 'field_stationcontact',
      3 => 'field_stationcountry',
      4 => 'field_stationemail',
      5 => 'field_stationfax',
      6 => 'field_stationphone',
      7 => 'field_stationpostcode',
      8 => 'field_stationprovince',
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
