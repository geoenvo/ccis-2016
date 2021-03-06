<?php
/**
 * @file
 * ccis_weather_station_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ccis_weather_station_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'weather_station';
  $feeds_importer->config = array(
    'name' => 'Weather Station',
    'description' => 'Weather Station Importer',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'xml',
        'direct' => 1,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'clim:wmoCode/clim:CharacterString/text()',
          'xpathparser:1' => 'clim:name/clim:CharacterString/text()',
          'xpathparser:2' => 'clim:alias/clim:CharacterString/text()',
          'xpathparser:3' => 'clim:wmoCode/clim:CharacterString/text()',
          'xpathparser:4' => 'clim:stationCode/clim:CharacterString/text()',
          'xpathparser:5' => '',
          'xpathparser:6' => 'clim:status/clim:dateOpen/clim:Date/text()',
          'xpathparser:7' => 'clim:status/clim:dateClosed/clim:Date/text()',
          'xpathparser:8' => 'clim:stationType/clim:CharacterString/text()',
          'xpathparser:9' => 'clim:pointOfContact/clim:CI_ResponsibleParty/clim:organisation/clim:CharacterString/text()',
          'xpathparser:10' => 'clim:pointOfContact/clim:CI_ResponsibleParty/clim:address/clim:CharacterString/text()',
          'xpathparser:11' => 'clim:pointOfContact/clim:CI_ResponsibleParty/clim:postcode/clim:CharacterString/text()',
          'xpathparser:12' => 'clim:pointOfContact/clim:CI_ResponsibleParty/clim:city/clim:CharacterString/text()',
          'xpathparser:13' => 'clim:pointOfContact/clim:CI_ResponsibleParty/clim:region/clim:CharacterString/text()',
          'xpathparser:14' => 'clim:pointOfContact/clim:CI_ResponsibleParty/clim:country/clim:CharacterString/text()',
          'xpathparser:15' => 'clim:pointOfContact/clim:CI_ResponsibleParty/clim:phone/clim:CharacterString/text()',
          'xpathparser:16' => 'clim:pointOfContact/clim:CI_ResponsibleParty/clim:fax/clim:CharacterString/text()',
          'xpathparser:17' => 'clim:pointOfContact/clim:CI_ResponsibleParty/clim:email/clim:CharacterString/text()',
          'xpathparser:18' => 'clim:instrumentation/clim:instrumentationType/clim:CharacterString/text()',
          'xpathparser:19' => 'clim:instrumentation/clim:trainingLevel/clim:CharacterString/text()',
          'xpathparser:20' => 'clim:instrumentation/clim:observedElements/clim:CharacterString/text()',
          'xpathparser:21' => 'clim:instrumentation/clim:observedTime/clim:CharacterString/text()',
          'xpathparser:22' => 'clim:instrumentation/clim:units/clim:CharacterString/text()',
          'xpathparser:23' => 'clim:instrumentation/clim:instructions/clim:CharacterString/text()',
          'xpathparser:24' => 'clim:instrumentation/clim:routineMaintenance/clim:CharacterString/text()',
          'xpathparser:25' => 'clim:instrumentation/clim:itemsReplacement/clim:CharacterString/text()',
          'xpathparser:26' => 'clim:instrumentation/clim:observerCorrections/clim:CharacterString/text()',
          'xpathparser:27' => 'clim:station/clim:stationContact/clim:CharacterString/text()',
          'xpathparser:28' => 'clim:station/clim:stationAddress/clim:CharacterString/text()',
          'xpathparser:29' => 'clim:station/clim:stationPostcode/clim:CharacterString/text()',
          'xpathparser:30' => 'clim:station/clim:stationCity/clim:CharacterString/text()',
          'xpathparser:31' => 'clim:station/clim:stationProvince/clim:CharacterString/text()',
          'xpathparser:32' => 'clim:station/clim:stationCountry/clim:CharacterString/text()',
          'xpathparser:33' => 'clim:station/clim:stationPhone/clim:CharacterString/text()',
          'xpathparser:34' => 'clim:station/clim:stationFax/clim:CharacterString/text()',
          'xpathparser:35' => 'clim:station/clim:stationEmail/clim:CharacterString/text()',
          'xpathparser:36' => 'clim:description/clim:stationAbstract/clim:CharacterString/text()',
          'xpathparser:37' => 'clim:description/clim:latitude/clim:Decimal/text()',
          'xpathparser:38' => 'clim:description/clim:longitude/clim:Decimal/text()',
          'xpathparser:39' => 'clim:description/clim:stationCRS/clim:CharacterString/text()',
          'xpathparser:40' => 'clim:description/clim:stationElevation/clim:CharacterString/text()',
          'xpathparser:41' => 'clim:description/clim:stationRelocation/clim:CharacterString/text()',
          'xpathparser:42' => 'clim:description/clim:stationAccuracy/clim:CharacterString/text()',
          'xpathparser:43' => 'clim:description/clim:stationMaintenance/clim:CharacterString/text()',
          'xpathparser:44' => 'clim:description/clim:stationTopo/clim:CharacterString/text()',
          'xpathparser:45' => 'clim:description/clim:stationLinks/clim:CharacterString/text()',
          'xpathparser:46' => 'clim:data/clim:dataUnits/clim:CharacterString/text()',
          'xpathparser:47' => 'clim:data/clim:dataCodes/clim:CharacterString/text()',
          'xpathparser:48' => 'clim:data/clim:dataQuality/clim:CharacterString/text()',
          'xpathparser:49' => 'clim:data/clim:dataTime/clim:CharacterString/text()',
          'xpathparser:50' => '',
          'xpathparser:51' => 'clim:fileIdentifier/clim:CharacterString/text()',
          'xpathparser:52' => 'clim:language/clim:LanguageCode/text()',
          'xpathparser:53' => 'clim:characterSet/clim:MD_CharacterSetCode/text()',
          'xpathparser:54' => 'clim:hierarchyLevel/clim:MD_ScopeCode/text()',
          'xpathparser:55' => '',
          'xpathparser:56' => 'clim:contact/clim:CI_ResponsibleParty/clim:organisationName/clim:CharacterString/text()',
          'xpathparser:57' => '',
          'xpathparser:58' => '',
          'xpathparser:59' => 'clim:contact/clim:CI_ResponsibleParty/clim:contactInfo/clim:CI_Contact/clim:address/clim:CI_Address/clim:electronicMailAddress/clim:CharacterString/text()',
          'xpathparser:60' => 'clim:contact/clim:CI_ResponsibleParty/clim:role/clim:CI_RoleCode/text()',
          'xpathparser:61' => 'clim:dateStamp/clim:Date/text()',
          'xpathparser:62' => 'clim:metadataStandardName/clim:CharacterString/text()',
          'xpathparser:63' => 'clim:metadataStandardVersion/clim:CharacterString/text()',
          'xpathparser:64' => 'clim:dataSetURI/clim:CharacterString/text()',
          'xpathparser:65' => 'clim:metadataConstraints/clim:CharacterString/text()',
          'xpathparser:66' => 'clim:metadataMaintenance/clim:CharacterString/text()',
          'xpathparser:67' => 'clim:transferOptions/clim:MD_DigitalTransferOptions/clim:onLine/clim:CI_OnlineResource/clim:linkage/clim:URL/text()',
          'xpathparser:68' => 'clim:extent/clim:EX_Extent/clim:temporalElement/clim:EX_TemporalExtent/clim:extent/clim:TimePeriod/clim:beginPosition/text()',
          'xpathparser:69' => 'clim:extent/clim:EX_Extent/clim:temporalElement/clim:EX_TemporalExtent/clim:extent/clim:TimePeriod/clim:endPosition/text()',
          'xpathparser:70' => 'clim:topicCategory/clim:MD_TopicCategoryCode/text()',
          'xpathparser:71' => 'clim:descriptiveKeywords//clim:keyword/clim:CharacterString/text()',
          'xpathparser:72' => 'clim:extent/clim:EX_Extent/clim:geographicElement/clim:EX_GeographicBoundingBox//clim:Decimal/text()',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
          'xpathparser:19' => 0,
          'xpathparser:20' => 0,
          'xpathparser:21' => 0,
          'xpathparser:22' => 0,
          'xpathparser:23' => 0,
          'xpathparser:24' => 0,
          'xpathparser:25' => 0,
          'xpathparser:26' => 0,
          'xpathparser:27' => 0,
          'xpathparser:28' => 0,
          'xpathparser:29' => 0,
          'xpathparser:30' => 0,
          'xpathparser:31' => 0,
          'xpathparser:32' => 0,
          'xpathparser:33' => 0,
          'xpathparser:34' => 0,
          'xpathparser:35' => 0,
          'xpathparser:36' => 0,
          'xpathparser:37' => 0,
          'xpathparser:38' => 0,
          'xpathparser:39' => 0,
          'xpathparser:40' => 0,
          'xpathparser:41' => 0,
          'xpathparser:42' => 0,
          'xpathparser:43' => 0,
          'xpathparser:44' => 0,
          'xpathparser:45' => 0,
          'xpathparser:46' => 0,
          'xpathparser:47' => 0,
          'xpathparser:48' => 0,
          'xpathparser:49' => 0,
          'xpathparser:50' => 0,
          'xpathparser:51' => 0,
          'xpathparser:52' => 0,
          'xpathparser:53' => 0,
          'xpathparser:54' => 0,
          'xpathparser:55' => 0,
          'xpathparser:56' => 0,
          'xpathparser:57' => 0,
          'xpathparser:58' => 0,
          'xpathparser:59' => 0,
          'xpathparser:60' => 0,
          'xpathparser:61' => 0,
          'xpathparser:62' => 0,
          'xpathparser:63' => 0,
          'xpathparser:64' => 0,
          'xpathparser:65' => 0,
          'xpathparser:66' => 0,
          'xpathparser:67' => 0,
          'xpathparser:68' => 0,
          'xpathparser:69' => 0,
          'xpathparser:70' => 0,
          'xpathparser:71' => 0,
          'xpathparser:72' => 0,
        ),
        'context' => '/clim:MD_Metadata',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
            'xpathparser:19' => 0,
            'xpathparser:20' => 0,
            'xpathparser:21' => 0,
            'xpathparser:22' => 0,
            'xpathparser:23' => 0,
            'xpathparser:24' => 0,
            'xpathparser:25' => 0,
            'xpathparser:26' => 0,
            'xpathparser:27' => 0,
            'xpathparser:28' => 0,
            'xpathparser:29' => 0,
            'xpathparser:30' => 0,
            'xpathparser:31' => 0,
            'xpathparser:32' => 0,
            'xpathparser:33' => 0,
            'xpathparser:34' => 0,
            'xpathparser:35' => 0,
            'xpathparser:36' => 0,
            'xpathparser:37' => 0,
            'xpathparser:38' => 0,
            'xpathparser:39' => 0,
            'xpathparser:40' => 0,
            'xpathparser:41' => 0,
            'xpathparser:42' => 0,
            'xpathparser:43' => 0,
            'xpathparser:44' => 0,
            'xpathparser:45' => 0,
            'xpathparser:46' => 0,
            'xpathparser:47' => 0,
            'xpathparser:48' => 0,
            'xpathparser:49' => 0,
            'xpathparser:50' => 0,
            'xpathparser:51' => 0,
            'xpathparser:52' => 0,
            'xpathparser:53' => 0,
            'xpathparser:54' => 0,
            'xpathparser:55' => 0,
            'xpathparser:56' => 0,
            'xpathparser:57' => 0,
            'xpathparser:58' => 0,
            'xpathparser:59' => 0,
            'xpathparser:60' => 0,
            'xpathparser:61' => 0,
            'xpathparser:62' => 0,
            'xpathparser:63' => 0,
            'xpathparser:64' => 0,
            'xpathparser:65' => 0,
            'xpathparser:66' => 0,
            'xpathparser:67' => 0,
            'xpathparser:68' => 0,
            'xpathparser:69' => 0,
            'xpathparser:70' => 0,
            'xpathparser:71' => 0,
            'xpathparser:72' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_alias',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_wmocode',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_stationcode',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_status',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_dateopen:start',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_dateclosed:start',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_stationtype',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_organisation',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_address',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_postcode',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_city',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_region',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_country',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_phone',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_fax',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_email',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_instrumentationtype',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'xpathparser:19',
            'target' => 'field_traininglevel',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_observedelements',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_observingtimes',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'xpathparser:22',
            'target' => 'field_units',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'xpathparser:23',
            'target' => 'field_instructions',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'xpathparser:24',
            'target' => 'field_routinemaintenance',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'xpathparser:25',
            'target' => 'field_itemsreplacement',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'xpathparser:26',
            'target' => 'field_observercorrections',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'xpathparser:27',
            'target' => 'field_stationcontact',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'xpathparser:28',
            'target' => 'field_stationaddress',
            'unique' => FALSE,
          ),
          29 => array(
            'source' => 'xpathparser:29',
            'target' => 'field_stationpostcode',
            'unique' => FALSE,
          ),
          30 => array(
            'source' => 'xpathparser:30',
            'target' => 'field_stationcity',
            'unique' => FALSE,
          ),
          31 => array(
            'source' => 'xpathparser:31',
            'target' => 'field_stationprovince',
            'unique' => FALSE,
          ),
          32 => array(
            'source' => 'xpathparser:32',
            'target' => 'field_stationcountry',
            'unique' => FALSE,
          ),
          33 => array(
            'source' => 'xpathparser:33',
            'target' => 'field_stationphone',
            'unique' => FALSE,
          ),
          34 => array(
            'source' => 'xpathparser:34',
            'target' => 'field_stationfax',
            'unique' => FALSE,
          ),
          35 => array(
            'source' => 'xpathparser:35',
            'target' => 'field_stationemail',
            'unique' => FALSE,
          ),
          36 => array(
            'source' => 'xpathparser:36',
            'target' => 'field_stationabstract',
            'unique' => FALSE,
          ),
          37 => array(
            'source' => 'xpathparser:37',
            'target' => 'field_station_geodata:lat',
            'unique' => FALSE,
          ),
          38 => array(
            'source' => 'xpathparser:38',
            'target' => 'field_station_geodata:lon',
            'unique' => FALSE,
          ),
          39 => array(
            'source' => 'xpathparser:39',
            'target' => 'field_stationcrs',
            'unique' => FALSE,
          ),
          40 => array(
            'source' => 'xpathparser:40',
            'target' => 'field_stationelevation',
            'unique' => FALSE,
          ),
          41 => array(
            'source' => 'xpathparser:41',
            'target' => 'field_stationrelocation',
            'unique' => FALSE,
          ),
          42 => array(
            'source' => 'xpathparser:42',
            'target' => 'field_stationaccuracy',
            'unique' => FALSE,
          ),
          43 => array(
            'source' => 'xpathparser:43',
            'target' => 'field_stationmaintenance',
            'unique' => FALSE,
          ),
          44 => array(
            'source' => 'xpathparser:44',
            'target' => 'field_stationtopo',
            'unique' => FALSE,
          ),
          45 => array(
            'source' => 'xpathparser:45',
            'target' => 'field_stationlinks',
            'unique' => FALSE,
          ),
          46 => array(
            'source' => 'xpathparser:46',
            'target' => 'field_dataunits',
            'unique' => FALSE,
          ),
          47 => array(
            'source' => 'xpathparser:47',
            'target' => 'field_datacodes',
            'unique' => FALSE,
          ),
          48 => array(
            'source' => 'xpathparser:48',
            'target' => 'field_dataquality',
            'unique' => FALSE,
          ),
          49 => array(
            'source' => 'xpathparser:49',
            'target' => 'field_datatime',
            'unique' => FALSE,
          ),
          50 => array(
            'source' => 'xpathparser:50',
            'target' => 'field_mdmetadata',
            'unique' => FALSE,
          ),
          51 => array(
            'source' => 'xpathparser:51',
            'target' => 'field_fileidentifier',
            'unique' => FALSE,
          ),
          52 => array(
            'source' => 'xpathparser:52',
            'target' => 'field_languagecode',
            'unique' => FALSE,
          ),
          53 => array(
            'source' => 'xpathparser:53',
            'target' => 'field_md_charactersetcode',
            'unique' => FALSE,
          ),
          54 => array(
            'source' => 'xpathparser:54',
            'target' => 'field_md_scopecode',
            'unique' => FALSE,
          ),
          55 => array(
            'source' => 'xpathparser:55',
            'target' => 'field_ci_responsibleparty',
            'unique' => FALSE,
          ),
          56 => array(
            'source' => 'xpathparser:56',
            'target' => 'field_organisationname',
            'unique' => FALSE,
          ),
          57 => array(
            'source' => 'xpathparser:57',
            'target' => 'field_ci_contact',
            'unique' => FALSE,
          ),
          58 => array(
            'source' => 'xpathparser:58',
            'target' => 'field_ci_address',
            'unique' => FALSE,
          ),
          59 => array(
            'source' => 'xpathparser:59',
            'target' => 'field_electronicmailaddress',
            'unique' => FALSE,
          ),
          60 => array(
            'source' => 'xpathparser:60',
            'target' => 'field_ci_rolecode',
            'unique' => FALSE,
          ),
          61 => array(
            'source' => 'xpathparser:61',
            'target' => 'field_datestamp:start',
            'unique' => FALSE,
          ),
          62 => array(
            'source' => 'xpathparser:62',
            'target' => 'field_metadatastandardname',
            'unique' => FALSE,
          ),
          63 => array(
            'source' => 'xpathparser:63',
            'target' => 'field_metadatastandardversion',
            'unique' => FALSE,
          ),
          64 => array(
            'source' => 'xpathparser:64',
            'target' => 'field_dataseturi',
            'unique' => FALSE,
          ),
          65 => array(
            'source' => 'xpathparser:65',
            'target' => 'field_metadataconstraints',
            'unique' => FALSE,
          ),
          66 => array(
            'source' => 'xpathparser:66',
            'target' => 'field_metadatamaintenance',
            'unique' => FALSE,
          ),
          67 => array(
            'source' => 'xpathparser:67',
            'target' => 'field_ci_onlineresource',
            'unique' => FALSE,
          ),
          68 => array(
            'source' => 'xpathparser:68',
            'target' => 'field_beginposition:start',
            'unique' => FALSE,
          ),
          69 => array(
            'source' => 'xpathparser:69',
            'target' => 'field_endposition:start',
            'unique' => FALSE,
          ),
          70 => array(
            'source' => 'xpathparser:70',
            'target' => 'field_category',
            'unique' => FALSE,
          ),
          71 => array(
            'source' => 'xpathparser:71',
            'target' => 'field_keyword',
            'unique' => FALSE,
          ),
          72 => array(
            'source' => 'xpathparser:72',
            'target' => 'field_extent',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'weather_station',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['weather_station'] = $feeds_importer;

  return $export;
}
