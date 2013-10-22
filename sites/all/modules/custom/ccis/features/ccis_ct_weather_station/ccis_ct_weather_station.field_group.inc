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
  $field_group->identifier = 'group_alias|node|weather_station|teaser';
  $field_group->group_name = 'group_alias';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_station';
  $field_group->data = array(
    'label' => 'Alias',
    'weight' => '92',
    'children' => array(
      0 => 'field_alias',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Alias',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_alias|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attachments|node|weather_station|dashboard';
  $field_group->group_name = 'group_attachments';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'dashboard';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Attachments',
    'weight' => '11',
    'children' => array(
      0 => 'field_stationlinks',
      1 => 'field_walter_lieth_diagram',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Attachments',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_attachments|node|weather_station|dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attachments|node|weather_station|teaser';
  $field_group->group_name = 'group_attachments';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Attachments',
    'weight' => '87',
    'children' => array(
      0 => 'field_stationlinks',
      1 => 'field_walter_lieth_diagram',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Attachments',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_attachments|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|weather_station|dashboard';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'dashboard';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '8',
    'children' => array(
      0 => 'group_responsible_organization',
      1 => 'group_station_contact',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'classes' => 'group-contact field-group-htabs',
        'description' => '',
        'id' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_contact|node|weather_station|dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|weather_station|teaser';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '83',
    'children' => array(
      0 => 'group_responsible_organization',
      1 => 'group_station_contact',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'classes' => 'group-contact field-group-htabs',
      ),
    ),
  );
  $export['group_contact|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data|node|weather_station|dashboard';
  $field_group->group_name = 'group_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'dashboard';
  $field_group->parent_name = 'group_station';
  $field_group->data = array(
    'label' => 'Data ',
    'weight' => '97',
    'children' => array(
      0 => 'field_datacodes',
      1 => 'field_dataquality',
      2 => 'field_datatime',
      3 => 'field_dataunits',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_data|node|weather_station|dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data|node|weather_station|default';
  $field_group->group_name = 'group_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Data ',
    'weight' => '82',
    'children' => array(
      0 => 'field_datacodes',
      1 => 'field_dataquality',
      2 => 'field_datatime',
      3 => 'field_dataunits',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'id' => '',
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
  $field_group->parent_name = 'group_station';
  $field_group->data = array(
    'label' => 'Data ',
    'weight' => '96',
    'children' => array(
      0 => 'field_datacodes',
      1 => 'field_dataquality',
      2 => 'field_datatime',
      3 => 'field_dataunits',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_data|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_instrumentation|node|weather_station|dashboard';
  $field_group->group_name = 'group_instrumentation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'dashboard';
  $field_group->parent_name = 'group_station';
  $field_group->data = array(
    'label' => 'Instrumentation',
    'weight' => '98',
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
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_instrumentation|node|weather_station|dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_instrumentation|node|weather_station|default';
  $field_group->group_name = 'group_instrumentation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Instrumentation',
    'weight' => '79',
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
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'id' => '',
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
  $field_group->parent_name = 'group_station';
  $field_group->data = array(
    'label' => 'Instrumentation',
    'weight' => '97',
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
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_instrumentation|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata_information|node|weather_station|dashboard';
  $field_group->group_name = 'group_metadata_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'dashboard';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Metadata Information',
    'weight' => '12',
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
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'id' => '',
      ),
    ),
  );
  $export['group_metadata_information|node|weather_station|dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata_information|node|weather_station|default';
  $field_group->group_name = 'group_metadata_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Metadata Information',
    'weight' => '83',
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
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'id' => '',
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
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Metadata Information',
    'weight' => '88',
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
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'id' => '',
      ),
    ),
  );
  $export['group_metadata_information|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata_main|node|weather_station|default';
  $field_group->group_name = 'group_metadata_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '77',
    'children' => array(
      0 => 'field_alias',
      1 => 'field_dateclosed',
      2 => 'field_dateopen',
      3 => 'field_mongodb_list_name',
      4 => 'field_station_geodata',
      5 => 'field_stationcode',
      6 => 'field_stationtype',
      7 => 'field_status',
      8 => 'field_wmocode',
      9 => 'field_csv_files',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-metadata-main field-group-htab',
        'id' => '',
      ),
    ),
  );
  $export['group_metadata_main|node|weather_station|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata_main|node|weather_station|teaser';
  $field_group->group_name = 'group_metadata_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Main',
    'weight' => '82',
    'children' => array(
      0 => 'field_stationcode',
      1 => 'field_wmocode',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-metadata-main field-group-htab',
        'id' => '',
      ),
    ),
  );
  $export['group_metadata_main|node|weather_station|teaser'] = $field_group;

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
  $field_group->identifier = 'group_responsible_organization|node|weather_station|dashboard';
  $field_group->group_name = 'group_responsible_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'dashboard';
  $field_group->parent_name = 'group_contact';
  $field_group->data = array(
    'label' => 'Responsible Organization',
    'weight' => '16',
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
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_responsible_organization|node|weather_station|dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_responsible_organization|node|weather_station|default';
  $field_group->group_name = 'group_responsible_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Responsible Organization',
    'weight' => '78',
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
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'id' => '',
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
  $field_group->parent_name = 'group_contact';
  $field_group->data = array(
    'label' => 'Responsible Organization',
    'weight' => '79',
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
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_responsible_organization|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_station_contact|node|weather_station|dashboard';
  $field_group->group_name = 'group_station_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'dashboard';
  $field_group->parent_name = 'group_contact';
  $field_group->data = array(
    'label' => 'Station Contact',
    'weight' => '17',
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
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_station_contact|node|weather_station|dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_station_contact|node|weather_station|default';
  $field_group->group_name = 'group_station_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Station Contact',
    'weight' => '80',
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
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'id' => '',
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
  $field_group->parent_name = 'group_contact';
  $field_group->data = array(
    'label' => 'Station Contact',
    'weight' => '80',
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
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_station_contact|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_station_description|node|weather_station|dashboard';
  $field_group->group_name = 'group_station_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'dashboard';
  $field_group->parent_name = 'group_station';
  $field_group->data = array(
    'label' => 'Station Description',
    'weight' => '95',
    'children' => array(
      0 => 'field_station_geodata',
      1 => 'field_stationabstract',
      2 => 'field_stationaccuracy',
      3 => 'field_stationadditional',
      4 => 'field_stationcrs',
      5 => 'field_stationelevation',
      6 => 'field_stationmaintenance',
      7 => 'field_stationrelocation',
      8 => 'field_stationtopo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_station_description|node|weather_station|dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_station_description|node|weather_station|default';
  $field_group->group_name = 'group_station_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Station Description',
    'weight' => '81',
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
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'id' => '',
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
      9 => 'field_walter_lieth_diagram',
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
  $field_group->parent_name = 'group_station';
  $field_group->data = array(
    'label' => 'Station Description',
    'weight' => '93',
    'children' => array(
      0 => 'field_station_geodata',
      1 => 'field_stationabstract',
      2 => 'field_stationaccuracy',
      3 => 'field_stationadditional',
      4 => 'field_stationcrs',
      5 => 'field_stationelevation',
      6 => 'field_stationmaintenance',
      7 => 'field_stationrelocation',
      8 => 'field_stationtopo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_station|node|weather_station|dashboard';
  $field_group->group_name = 'group_station';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'dashboard';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Station',
    'weight' => '10',
    'children' => array(
      0 => 'field_alias',
      1 => 'group_data',
      2 => 'group_instrumentation',
      3 => 'group_station_description',
      4 => 'group_status',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Station',
      'instance_settings' => array(
        'classes' => 'group-station field-group-htabs',
        'description' => '',
        'id' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_station|node|weather_station|dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_station|node|weather_station|teaser';
  $field_group->group_name = 'group_station';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_tabs_group';
  $field_group->data = array(
    'label' => 'Station',
    'weight' => '84',
    'children' => array(
      0 => 'group_data',
      1 => 'group_instrumentation',
      2 => 'group_station_description',
      3 => 'group_alias',
      4 => 'group_status',
      5 => 'group_type',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Station',
      'instance_settings' => array(
        'classes' => 'group-station field-group-htabs',
      ),
    ),
  );
  $export['group_station|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_status|node|weather_station|dashboard';
  $field_group->group_name = 'group_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'dashboard';
  $field_group->parent_name = 'group_station';
  $field_group->data = array(
    'label' => 'Status',
    'weight' => '96',
    'children' => array(
      0 => 'field_dateclosed',
      1 => 'field_dateopen',
      2 => 'field_stationtype',
      3 => 'field_status',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Status',
      'instance_settings' => array(
        'classes' => 'group-status field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_status|node|weather_station|dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_status|node|weather_station|teaser';
  $field_group->group_name = 'group_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_station';
  $field_group->data = array(
    'label' => 'Status',
    'weight' => '94',
    'children' => array(
      0 => 'field_dateclosed',
      1 => 'field_dateopen',
      2 => 'field_status',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Status',
      'instance_settings' => array(
        'classes' => 'group-status field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_status|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_group|node|weather_station|dashboard';
  $field_group->group_name = 'group_tabs_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'dashboard';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Information',
    'weight' => '3',
    'children' => array(
      0 => 'group_attachments',
      1 => 'group_contact',
      2 => 'group_metadata_information',
      3 => 'group_station',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-group field-group-htabs',
      ),
    ),
  );
  $export['group_tabs_group|node|weather_station|dashboard'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_group|node|weather_station|default';
  $field_group->group_name = 'group_tabs_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Information',
    'weight' => '0',
    'children' => array(
      0 => 'group_data',
      1 => 'group_instrumentation',
      2 => 'group_metadata_information',
      3 => 'group_metadata_main',
      4 => 'group_responsible_organization',
      5 => 'group_station_contact',
      6 => 'group_station_description',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-group field-group-htabs',
      ),
    ),
  );
  $export['group_tabs_group|node|weather_station|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_group|node|weather_station|teaser';
  $field_group->group_name = 'group_tabs_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Information',
    'weight' => '0',
    'children' => array(
      0 => 'group_metadata_information',
      1 => 'group_metadata_main',
      2 => 'group_contact',
      3 => 'group_station',
      4 => 'group_attachments',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs-group field-group-htabs',
      ),
    ),
  );
  $export['group_tabs_group|node|weather_station|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_type|node|weather_station|teaser';
  $field_group->group_name = 'group_type';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'weather_station';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_station';
  $field_group->data = array(
    'label' => 'Type',
    'weight' => '95',
    'children' => array(
      0 => 'field_stationtype',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Type',
      'instance_settings' => array(
        'classes' => 'group-type field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_type|node|weather_station|teaser'] = $field_group;

  return $export;
}
