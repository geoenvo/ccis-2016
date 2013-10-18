<?php
/**
 * @file
 * ccis_ct_weather_station.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ccis_ct_weather_station_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|weather_station|dashboard';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'weather_station';
  $ds_fieldsetting->view_mode = 'dashboard';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|weather_station|dashboard'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ccis_ct_weather_station_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|weather_station|dashboard';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'weather_station';
  $ds_layout->view_mode = 'dashboard';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_wmocode',
        2 => 'field_stationcode',
        3 => 'group_tabs_group',
        4 => 'group_contact',
        5 => 'group_station',
        6 => 'group_attachments',
        7 => 'group_metadata_information',
        8 => 'group_responsible_organization',
        9 => 'group_station_contact',
        10 => 'field_status',
        11 => 'field_stationtype',
        12 => 'field_dateclosed',
        13 => 'field_stationlinks',
        14 => 'field_dateopen',
        15 => 'field_walter_lieth_diagram',
        16 => 'field_dataunits',
        17 => 'field_datacodes',
        18 => 'field_dataquality',
        19 => 'field_datatime',
        20 => 'field_mdmetadata',
        21 => 'field_organisation',
        22 => 'field_fileidentifier',
        23 => 'field_address',
        24 => 'field_postcode',
        25 => 'field_languagecode',
        26 => 'field_md_charactersetcode',
        27 => 'field_city',
        28 => 'field_instrumentationtype',
        29 => 'field_traininglevel',
        30 => 'field_md_scopecode',
        31 => 'field_region',
        32 => 'field_observedelements',
        33 => 'field_ci_responsibleparty',
        34 => 'field_country',
        35 => 'field_phone',
        36 => 'field_stationcontact',
        37 => 'field_organisationname',
        38 => 'field_observingtimes',
        39 => 'field_stationaddress',
        40 => 'field_units',
        41 => 'field_fax',
        42 => 'field_ci_contact',
        43 => 'field_stationpostcode',
        44 => 'field_ci_address',
        45 => 'field_instructions',
        46 => 'field_email',
        47 => 'field_routinemaintenance',
        48 => 'field_stationcity',
        49 => 'field_electronicmailaddress',
        50 => 'field_itemsreplacement',
        51 => 'field_stationprovince',
        52 => 'field_ci_rolecode',
        53 => 'field_observercorrections',
        54 => 'field_stationcountry',
        55 => 'field_datestamp',
        56 => 'field_metadatastandardname',
        57 => 'field_stationphone',
        58 => 'field_dataseturi',
        59 => 'field_stationfax',
        60 => 'field_stationemail',
        61 => 'field_metadataconstraints',
        62 => 'field_metadatamaintenance',
        63 => 'field_metadatastandardversion',
        64 => 'field_ci_onlineresource',
        65 => 'field_beginposition',
        66 => 'field_endposition',
        67 => 'field_category',
        68 => 'field_keyword',
        69 => 'field_extent',
        70 => 'field_alias',
        71 => 'field_stationabstract',
        72 => 'group_station_description',
        73 => 'field_stationadditional',
        74 => 'group_status',
        75 => 'group_data',
        76 => 'field_station_geodata',
        77 => 'field_stationcrs',
        78 => 'group_instrumentation',
        79 => 'field_stationelevation',
        80 => 'field_stationrelocation',
        81 => 'field_stationaccuracy',
        82 => 'field_stationmaintenance',
        83 => 'field_stationtopo',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_wmocode' => 'ds_content',
      'field_stationcode' => 'ds_content',
      'group_tabs_group' => 'ds_content',
      'group_contact' => 'ds_content',
      'group_station' => 'ds_content',
      'group_attachments' => 'ds_content',
      'group_metadata_information' => 'ds_content',
      'group_responsible_organization' => 'ds_content',
      'group_station_contact' => 'ds_content',
      'field_status' => 'ds_content',
      'field_stationtype' => 'ds_content',
      'field_dateclosed' => 'ds_content',
      'field_stationlinks' => 'ds_content',
      'field_dateopen' => 'ds_content',
      'field_walter_lieth_diagram' => 'ds_content',
      'field_dataunits' => 'ds_content',
      'field_datacodes' => 'ds_content',
      'field_dataquality' => 'ds_content',
      'field_datatime' => 'ds_content',
      'field_mdmetadata' => 'ds_content',
      'field_organisation' => 'ds_content',
      'field_fileidentifier' => 'ds_content',
      'field_address' => 'ds_content',
      'field_postcode' => 'ds_content',
      'field_languagecode' => 'ds_content',
      'field_md_charactersetcode' => 'ds_content',
      'field_city' => 'ds_content',
      'field_instrumentationtype' => 'ds_content',
      'field_traininglevel' => 'ds_content',
      'field_md_scopecode' => 'ds_content',
      'field_region' => 'ds_content',
      'field_observedelements' => 'ds_content',
      'field_ci_responsibleparty' => 'ds_content',
      'field_country' => 'ds_content',
      'field_phone' => 'ds_content',
      'field_stationcontact' => 'ds_content',
      'field_organisationname' => 'ds_content',
      'field_observingtimes' => 'ds_content',
      'field_stationaddress' => 'ds_content',
      'field_units' => 'ds_content',
      'field_fax' => 'ds_content',
      'field_ci_contact' => 'ds_content',
      'field_stationpostcode' => 'ds_content',
      'field_ci_address' => 'ds_content',
      'field_instructions' => 'ds_content',
      'field_email' => 'ds_content',
      'field_routinemaintenance' => 'ds_content',
      'field_stationcity' => 'ds_content',
      'field_electronicmailaddress' => 'ds_content',
      'field_itemsreplacement' => 'ds_content',
      'field_stationprovince' => 'ds_content',
      'field_ci_rolecode' => 'ds_content',
      'field_observercorrections' => 'ds_content',
      'field_stationcountry' => 'ds_content',
      'field_datestamp' => 'ds_content',
      'field_metadatastandardname' => 'ds_content',
      'field_stationphone' => 'ds_content',
      'field_dataseturi' => 'ds_content',
      'field_stationfax' => 'ds_content',
      'field_stationemail' => 'ds_content',
      'field_metadataconstraints' => 'ds_content',
      'field_metadatamaintenance' => 'ds_content',
      'field_metadatastandardversion' => 'ds_content',
      'field_ci_onlineresource' => 'ds_content',
      'field_beginposition' => 'ds_content',
      'field_endposition' => 'ds_content',
      'field_category' => 'ds_content',
      'field_keyword' => 'ds_content',
      'field_extent' => 'ds_content',
      'field_alias' => 'ds_content',
      'field_stationabstract' => 'ds_content',
      'group_station_description' => 'ds_content',
      'field_stationadditional' => 'ds_content',
      'group_status' => 'ds_content',
      'group_data' => 'ds_content',
      'field_station_geodata' => 'ds_content',
      'field_stationcrs' => 'ds_content',
      'group_instrumentation' => 'ds_content',
      'field_stationelevation' => 'ds_content',
      'field_stationrelocation' => 'ds_content',
      'field_stationaccuracy' => 'ds_content',
      'field_stationmaintenance' => 'ds_content',
      'field_stationtopo' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|weather_station|dashboard'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function ccis_ct_weather_station_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'dashboard';
  $ds_view_mode->label = 'Dashboard';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['dashboard'] = $ds_view_mode;

  return $export;
}
