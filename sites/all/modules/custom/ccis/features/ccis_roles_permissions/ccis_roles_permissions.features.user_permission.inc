<?php
/**
 * @file
 * ccis_roles_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ccis_roles_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'csv_import'.
  $permissions['csv_import'] = array(
    'name' => 'csv_import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ccis',
  );

  // Exported permission: 'delete_collections'.
  $permissions['delete_collections'] = array(
    'name' => 'delete_collections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ccis',
  );

  // Exported permission: 'edit field_address'.
  $permissions['edit field_address'] = array(
    'name' => 'edit field_address',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_beginposition'.
  $permissions['edit field_beginposition'] = array(
    'name' => 'edit field_beginposition',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ci_onlineresource'.
  $permissions['edit field_ci_onlineresource'] = array(
    'name' => 'edit field_ci_onlineresource',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_city'.
  $permissions['edit field_city'] = array(
    'name' => 'edit field_city',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_country'.
  $permissions['edit field_country'] = array(
    'name' => 'edit field_country',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_datacodes'.
  $permissions['edit field_datacodes'] = array(
    'name' => 'edit field_datacodes',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_dataquality'.
  $permissions['edit field_dataquality'] = array(
    'name' => 'edit field_dataquality',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_dataseturi'.
  $permissions['edit field_dataseturi'] = array(
    'name' => 'edit field_dataseturi',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_datatime'.
  $permissions['edit field_datatime'] = array(
    'name' => 'edit field_datatime',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_dataunits'.
  $permissions['edit field_dataunits'] = array(
    'name' => 'edit field_dataunits',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_datestamp'.
  $permissions['edit field_datestamp'] = array(
    'name' => 'edit field_datestamp',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_email'.
  $permissions['edit field_email'] = array(
    'name' => 'edit field_email',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_endposition'.
  $permissions['edit field_endposition'] = array(
    'name' => 'edit field_endposition',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_fax'.
  $permissions['edit field_fax'] = array(
    'name' => 'edit field_fax',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_fileidentifier'.
  $permissions['edit field_fileidentifier'] = array(
    'name' => 'edit field_fileidentifier',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_instructions'.
  $permissions['edit field_instructions'] = array(
    'name' => 'edit field_instructions',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_instrumentationtype'.
  $permissions['edit field_instrumentationtype'] = array(
    'name' => 'edit field_instrumentationtype',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_itemsreplacement'.
  $permissions['edit field_itemsreplacement'] = array(
    'name' => 'edit field_itemsreplacement',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_languagecode'.
  $permissions['edit field_languagecode'] = array(
    'name' => 'edit field_languagecode',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_md_charactersetcode'.
  $permissions['edit field_md_charactersetcode'] = array(
    'name' => 'edit field_md_charactersetcode',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_md_scopecode'.
  $permissions['edit field_md_scopecode'] = array(
    'name' => 'edit field_md_scopecode',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_mdmetadata'.
  $permissions['edit field_mdmetadata'] = array(
    'name' => 'edit field_mdmetadata',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_metadataconstraints'.
  $permissions['edit field_metadataconstraints'] = array(
    'name' => 'edit field_metadataconstraints',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_metadatamaintenance'.
  $permissions['edit field_metadatamaintenance'] = array(
    'name' => 'edit field_metadatamaintenance',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_metadatastandardname'.
  $permissions['edit field_metadatastandardname'] = array(
    'name' => 'edit field_metadatastandardname',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_metadatastandardversion'.
  $permissions['edit field_metadatastandardversion'] = array(
    'name' => 'edit field_metadatastandardversion',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_observedelements'.
  $permissions['edit field_observedelements'] = array(
    'name' => 'edit field_observedelements',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_observercorrections'.
  $permissions['edit field_observercorrections'] = array(
    'name' => 'edit field_observercorrections',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_observingtimes'.
  $permissions['edit field_observingtimes'] = array(
    'name' => 'edit field_observingtimes',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_phone'.
  $permissions['edit field_phone'] = array(
    'name' => 'edit field_phone',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_postcode'.
  $permissions['edit field_postcode'] = array(
    'name' => 'edit field_postcode',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_region'.
  $permissions['edit field_region'] = array(
    'name' => 'edit field_region',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_routinemaintenance'.
  $permissions['edit field_routinemaintenance'] = array(
    'name' => 'edit field_routinemaintenance',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationabstract'.
  $permissions['edit field_stationabstract'] = array(
    'name' => 'edit field_stationabstract',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationaccuracy'.
  $permissions['edit field_stationaccuracy'] = array(
    'name' => 'edit field_stationaccuracy',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationadditional'.
  $permissions['edit field_stationadditional'] = array(
    'name' => 'edit field_stationadditional',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationaddress'.
  $permissions['edit field_stationaddress'] = array(
    'name' => 'edit field_stationaddress',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationcity'.
  $permissions['edit field_stationcity'] = array(
    'name' => 'edit field_stationcity',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationcontact'.
  $permissions['edit field_stationcontact'] = array(
    'name' => 'edit field_stationcontact',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationcountry'.
  $permissions['edit field_stationcountry'] = array(
    'name' => 'edit field_stationcountry',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationemail'.
  $permissions['edit field_stationemail'] = array(
    'name' => 'edit field_stationemail',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationfax'.
  $permissions['edit field_stationfax'] = array(
    'name' => 'edit field_stationfax',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationlinks'.
  $permissions['edit field_stationlinks'] = array(
    'name' => 'edit field_stationlinks',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationmaintenance'.
  $permissions['edit field_stationmaintenance'] = array(
    'name' => 'edit field_stationmaintenance',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationphone'.
  $permissions['edit field_stationphone'] = array(
    'name' => 'edit field_stationphone',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationpostcode'.
  $permissions['edit field_stationpostcode'] = array(
    'name' => 'edit field_stationpostcode',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationprovince'.
  $permissions['edit field_stationprovince'] = array(
    'name' => 'edit field_stationprovince',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationrelocation'.
  $permissions['edit field_stationrelocation'] = array(
    'name' => 'edit field_stationrelocation',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_stationtopo'.
  $permissions['edit field_stationtopo'] = array(
    'name' => 'edit field_stationtopo',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_traininglevel'.
  $permissions['edit field_traininglevel'] = array(
    'name' => 'edit field_traininglevel',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_units'.
  $permissions['edit field_units'] = array(
    'name' => 'edit field_units',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'import weather_station feeds'.
  $permissions['import weather_station feeds'] = array(
    'name' => 'import weather_station feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format simple_html'.
  $permissions['use text format simple_html'] = array(
    'name' => 'use text format simple_html',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'view field_address'.
  $permissions['view field_address'] = array(
    'name' => 'view field_address',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_beginposition'.
  $permissions['view field_beginposition'] = array(
    'name' => 'view field_beginposition',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ci_onlineresource'.
  $permissions['view field_ci_onlineresource'] = array(
    'name' => 'view field_ci_onlineresource',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_city'.
  $permissions['view field_city'] = array(
    'name' => 'view field_city',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_country'.
  $permissions['view field_country'] = array(
    'name' => 'view field_country',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_datacodes'.
  $permissions['view field_datacodes'] = array(
    'name' => 'view field_datacodes',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_dataquality'.
  $permissions['view field_dataquality'] = array(
    'name' => 'view field_dataquality',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_dataseturi'.
  $permissions['view field_dataseturi'] = array(
    'name' => 'view field_dataseturi',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_datatime'.
  $permissions['view field_datatime'] = array(
    'name' => 'view field_datatime',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_dataunits'.
  $permissions['view field_dataunits'] = array(
    'name' => 'view field_dataunits',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_datestamp'.
  $permissions['view field_datestamp'] = array(
    'name' => 'view field_datestamp',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_email'.
  $permissions['view field_email'] = array(
    'name' => 'view field_email',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_endposition'.
  $permissions['view field_endposition'] = array(
    'name' => 'view field_endposition',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_fax'.
  $permissions['view field_fax'] = array(
    'name' => 'view field_fax',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_fileidentifier'.
  $permissions['view field_fileidentifier'] = array(
    'name' => 'view field_fileidentifier',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_instructions'.
  $permissions['view field_instructions'] = array(
    'name' => 'view field_instructions',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_instrumentationtype'.
  $permissions['view field_instrumentationtype'] = array(
    'name' => 'view field_instrumentationtype',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_itemsreplacement'.
  $permissions['view field_itemsreplacement'] = array(
    'name' => 'view field_itemsreplacement',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_languagecode'.
  $permissions['view field_languagecode'] = array(
    'name' => 'view field_languagecode',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_md_charactersetcode'.
  $permissions['view field_md_charactersetcode'] = array(
    'name' => 'view field_md_charactersetcode',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_md_scopecode'.
  $permissions['view field_md_scopecode'] = array(
    'name' => 'view field_md_scopecode',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_mdmetadata'.
  $permissions['view field_mdmetadata'] = array(
    'name' => 'view field_mdmetadata',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_metadataconstraints'.
  $permissions['view field_metadataconstraints'] = array(
    'name' => 'view field_metadataconstraints',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_metadatamaintenance'.
  $permissions['view field_metadatamaintenance'] = array(
    'name' => 'view field_metadatamaintenance',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_metadatastandardname'.
  $permissions['view field_metadatastandardname'] = array(
    'name' => 'view field_metadatastandardname',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_metadatastandardversion'.
  $permissions['view field_metadatastandardversion'] = array(
    'name' => 'view field_metadatastandardversion',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_observedelements'.
  $permissions['view field_observedelements'] = array(
    'name' => 'view field_observedelements',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_observercorrections'.
  $permissions['view field_observercorrections'] = array(
    'name' => 'view field_observercorrections',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_observingtimes'.
  $permissions['view field_observingtimes'] = array(
    'name' => 'view field_observingtimes',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_phone'.
  $permissions['view field_phone'] = array(
    'name' => 'view field_phone',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_postcode'.
  $permissions['view field_postcode'] = array(
    'name' => 'view field_postcode',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_region'.
  $permissions['view field_region'] = array(
    'name' => 'view field_region',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_routinemaintenance'.
  $permissions['view field_routinemaintenance'] = array(
    'name' => 'view field_routinemaintenance',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationabstract'.
  $permissions['view field_stationabstract'] = array(
    'name' => 'view field_stationabstract',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationaccuracy'.
  $permissions['view field_stationaccuracy'] = array(
    'name' => 'view field_stationaccuracy',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationadditional'.
  $permissions['view field_stationadditional'] = array(
    'name' => 'view field_stationadditional',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationaddress'.
  $permissions['view field_stationaddress'] = array(
    'name' => 'view field_stationaddress',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationcity'.
  $permissions['view field_stationcity'] = array(
    'name' => 'view field_stationcity',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationcontact'.
  $permissions['view field_stationcontact'] = array(
    'name' => 'view field_stationcontact',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationcountry'.
  $permissions['view field_stationcountry'] = array(
    'name' => 'view field_stationcountry',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationemail'.
  $permissions['view field_stationemail'] = array(
    'name' => 'view field_stationemail',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationfax'.
  $permissions['view field_stationfax'] = array(
    'name' => 'view field_stationfax',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationlinks'.
  $permissions['view field_stationlinks'] = array(
    'name' => 'view field_stationlinks',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationmaintenance'.
  $permissions['view field_stationmaintenance'] = array(
    'name' => 'view field_stationmaintenance',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationphone'.
  $permissions['view field_stationphone'] = array(
    'name' => 'view field_stationphone',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationpostcode'.
  $permissions['view field_stationpostcode'] = array(
    'name' => 'view field_stationpostcode',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationprovince'.
  $permissions['view field_stationprovince'] = array(
    'name' => 'view field_stationprovince',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationrelocation'.
  $permissions['view field_stationrelocation'] = array(
    'name' => 'view field_stationrelocation',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_stationtopo'.
  $permissions['view field_stationtopo'] = array(
    'name' => 'view field_stationtopo',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_traininglevel'.
  $permissions['view field_traininglevel'] = array(
    'name' => 'view field_traininglevel',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_units'.
  $permissions['view field_units'] = array(
    'name' => 'view field_units',
    'roles' => array(
      'administrator' => 'administrator',
      'climability editor' => 'climability editor',
      'special user' => 'special user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
