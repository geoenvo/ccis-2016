<?php
/**
 * @file
 * ccis_ct_weather_station.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ccis_ct_weather_station_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_walter_lieth_diagram';
  $strongarm->value = 'edit-i18n';
  $export['additional_settings__active_tab_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_weather_station';
  $strongarm->value = 'edit-rabbit-hole';
  $export['additional_settings__active_tab_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_walter_lieth_diagram';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_walter_lieth_diagram';
  $strongarm->value = '[node:field-weather-station]-Walter-Lieth-Diagram';
  $export['auto_entitylabel_pattern_node_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_walter_lieth_diagram';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_node_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ccis_station_search_terms';
  $strongarm->value = array(
    'field_alias' => 'field_alias',
    'field_address' => 0,
    'field_category' => 0,
    'field_ci_address' => 0,
    'field_ci_contact' => 0,
    'field_ci_onlineresource' => 0,
    'field_ci_responsibleparty' => 0,
    'field_ci_rolecode' => 0,
    'field_city' => 0,
    'field_country' => 0,
    'field_datacodes' => 0,
    'field_dataquality' => 0,
    'field_dataseturi' => 0,
    'field_datatime' => 0,
    'field_dataunits' => 0,
    'field_electronicmailaddress' => 0,
    'field_email' => 0,
    'field_extent' => 0,
    'field_fax' => 0,
    'field_fileidentifier' => 0,
    'field_instructions' => 0,
    'field_instrumentationtype' => 0,
    'field_itemsreplacement' => 0,
    'field_keyword' => 0,
    'field_languagecode' => 0,
    'field_md_charactersetcode' => 0,
    'field_md_scopecode' => 0,
    'field_mdmetadata' => 0,
    'field_metadataconstraints' => 0,
    'field_metadatamaintenance' => 0,
    'field_metadatastandardname' => 0,
    'field_metadatastandardversion' => 0,
    'field_observedelements' => 0,
    'field_observercorrections' => 0,
    'field_observingtimes' => 0,
    'field_organisation' => 0,
    'field_organisationname' => 0,
    'field_phone' => 0,
    'field_postcode' => 0,
    'field_region' => 0,
    'field_routinemaintenance' => 0,
    'field_stationabstract' => 0,
    'field_stationaccuracy' => 0,
    'field_stationaddress' => 0,
    'field_stationcity' => 0,
    'field_stationcode' => 0,
    'field_stationcontact' => 0,
    'field_stationcountry' => 0,
    'field_stationcrs' => 0,
    'field_stationelevation' => 0,
    'field_stationemail' => 0,
    'field_stationfax' => 0,
    'field_stationlinks' => 0,
    'field_stationmaintenance' => 0,
    'field_stationphone' => 0,
    'field_stationpostcode' => 0,
    'field_stationprovince' => 0,
    'field_stationrelocation' => 0,
    'field_stationtopo' => 0,
    'field_stationtype' => 0,
    'field_traininglevel' => 0,
    'field_units' => 0,
    'field_wmocode' => 0,
  );
  $export['ccis_station_search_terms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_walter_lieth_diagram';
  $strongarm->value = 0;
  $export['comment_anonymous_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_weather_station';
  $strongarm->value = 0;
  $export['comment_anonymous_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_walter_lieth_diagram';
  $strongarm->value = 1;
  $export['comment_default_mode_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_weather_station';
  $strongarm->value = 1;
  $export['comment_default_mode_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_walter_lieth_diagram';
  $strongarm->value = '50';
  $export['comment_default_per_page_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_weather_station';
  $strongarm->value = '50';
  $export['comment_default_per_page_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_walter_lieth_diagram';
  $strongarm->value = 1;
  $export['comment_form_location_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_weather_station';
  $strongarm->value = 1;
  $export['comment_form_location_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_walter_lieth_diagram';
  $strongarm->value = '1';
  $export['comment_preview_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_weather_station';
  $strongarm->value = '1';
  $export['comment_preview_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_walter_lieth_diagram';
  $strongarm->value = 1;
  $export['comment_subject_field_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_weather_station';
  $strongarm->value = 1;
  $export['comment_subject_field_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_walter_lieth_diagram';
  $strongarm->value = '0';
  $export['comment_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_weather_station';
  $strongarm->value = '0';
  $export['comment_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__walter_lieth_diagram';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'dashboard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'language' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(
        'language' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__weather_station';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'dashboard' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '26',
        ),
        'path' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_walter_lieth_diagram';
  $strongarm->value = '1';
  $export['i18n_node_extended_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_weather_station';
  $strongarm->value = 1;
  $export['i18n_node_extended_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_walter_lieth_diagram';
  $strongarm->value = array(
    0 => 'current',
  );
  $export['i18n_node_options_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_weather_station';
  $strongarm->value = array();
  $export['i18n_node_options_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_walter_lieth_diagram';
  $strongarm->value = '2';
  $export['language_content_type_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_weather_station';
  $strongarm->value = '0';
  $export['language_content_type_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_border_size';
  $strongarm->value = '10';
  $export['lightbox2_border_size'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_box_color';
  $strongarm->value = 'fff';
  $export['lightbox2_box_color'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_disable_close_click';
  $strongarm->value = 1;
  $export['lightbox2_disable_close_click'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_disable_resize';
  $strongarm->value = 0;
  $export['lightbox2_disable_resize'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_disable_zoom';
  $strongarm->value = 0;
  $export['lightbox2_disable_zoom'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_download_link_text';
  $strongarm->value = '';
  $export['lightbox2_download_link_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_enable_contact';
  $strongarm->value = 0;
  $export['lightbox2_enable_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_enable_login';
  $strongarm->value = 0;
  $export['lightbox2_enable_login'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_enable_video';
  $strongarm->value = 0;
  $export['lightbox2_enable_video'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_fadein_speed';
  $strongarm->value = '0.4';
  $export['lightbox2_fadein_speed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_filter_xss_allowed_tags';
  $strongarm->value = 'p, br, a, em, strong, cite, code, ul, ol, li, dl, dt, dd';
  $export['lightbox2_filter_xss_allowed_tags'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_flv_player_flashvars';
  $strongarm->value = '';
  $export['lightbox2_flv_player_flashvars'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_flv_player_path';
  $strongarm->value = 'flvplayer.swf';
  $export['lightbox2_flv_player_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_font_color';
  $strongarm->value = '000';
  $export['lightbox2_font_color'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_force_show_nav';
  $strongarm->value = 0;
  $export['lightbox2_force_show_nav'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_image_count_str';
  $strongarm->value = 'Image !current of !total';
  $export['lightbox2_image_count_str'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_image_group_node_id';
  $strongarm->value = '1';
  $export['lightbox2_image_group_node_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_js_location';
  $strongarm->value = 'header';
  $export['lightbox2_js_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_keys_close';
  $strongarm->value = 'c x 27';
  $export['lightbox2_keys_close'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_keys_next';
  $strongarm->value = 'n 39';
  $export['lightbox2_keys_next'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_keys_play_pause';
  $strongarm->value = '32';
  $export['lightbox2_keys_play_pause'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_keys_previous';
  $strongarm->value = 'p 37';
  $export['lightbox2_keys_previous'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_keys_zoom';
  $strongarm->value = 'z';
  $export['lightbox2_keys_zoom'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_lite';
  $strongarm->value = 0;
  $export['lightbox2_lite'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_loop_items';
  $strongarm->value = 0;
  $export['lightbox2_loop_items'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_node_link_target';
  $strongarm->value = 0;
  $export['lightbox2_node_link_target'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_node_link_text';
  $strongarm->value = '';
  $export['lightbox2_node_link_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_overlay_color';
  $strongarm->value = '000';
  $export['lightbox2_overlay_color'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_overlay_opacity';
  $strongarm->value = '0.8';
  $export['lightbox2_overlay_opacity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_page_count_str';
  $strongarm->value = 'Page !current of !total';
  $export['lightbox2_page_count_str'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_page_init_action';
  $strongarm->value = 'page_disable';
  $export['lightbox2_page_init_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_page_list';
  $strongarm->value = '';
  $export['lightbox2_page_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_resize_sequence';
  $strongarm->value = '0';
  $export['lightbox2_resize_sequence'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_resize_speed';
  $strongarm->value = '0.4';
  $export['lightbox2_resize_speed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_show_caption';
  $strongarm->value = 1;
  $export['lightbox2_show_caption'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_slidedown_speed';
  $strongarm->value = '0.6';
  $export['lightbox2_slidedown_speed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_top_position';
  $strongarm->value = '';
  $export['lightbox2_top_position'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_use_alt_layout';
  $strongarm->value = 0;
  $export['lightbox2_use_alt_layout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'lightbox2_video_count_str';
  $strongarm->value = 'Video !current of !total';
  $export['lightbox2_video_count_str'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_walter_lieth_diagram';
  $strongarm->value = array();
  $export['menu_options_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_weather_station';
  $strongarm->value = array();
  $export['menu_options_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_walter_lieth_diagram';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_weather_station';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_walter_lieth_diagram';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_weather_station';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_walter_lieth_diagram';
  $strongarm->value = '1';
  $export['node_preview_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_weather_station';
  $strongarm->value = '1';
  $export['node_preview_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_walter_lieth_diagram';
  $strongarm->value = 0;
  $export['node_submitted_walter_lieth_diagram'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_weather_station';
  $strongarm->value = 0;
  $export['node_submitted_weather_station'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_walter_lieth_diagram_pattern';
  $strongarm->value = 'diagram/[node:title]';
  $export['pathauto_node_walter_lieth_diagram_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_action_weather_station';
  $strongarm->value = '1';
  $export['rh_node_action_weather_station'] = $strongarm;

  return $export;
}
