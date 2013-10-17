<?php
/**
 * @file
 * ccis_users.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ccis_users_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_company|profile2|main|form';
  $field_group->group_name = 'group_company';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'company',
    'weight' => '0',
    'children' => array(
      0 => 'field_company',
      1 => 'field_company_address',
      2 => 'field_company_city',
      3 => 'field_company_postcode',
      4 => 'field_company_phone',
      5 => 'field_company_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-company field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_company|profile2|main|form'] = $field_group;

  return $export;
}
