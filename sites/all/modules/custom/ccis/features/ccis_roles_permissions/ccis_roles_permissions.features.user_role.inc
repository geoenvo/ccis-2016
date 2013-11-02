<?php
/**
 * @file
 * ccis_roles_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ccis_roles_permissions_user_default_roles() {
  $roles = array();

  // Exported role: climability editor.
  $roles['climability editor'] = array(
    'name' => 'climability editor',
    'weight' => 4,
  );

  // Exported role: special user.
  $roles['special user'] = array(
    'name' => 'special user',
    'weight' => 3,
  );

  return $roles;
}
