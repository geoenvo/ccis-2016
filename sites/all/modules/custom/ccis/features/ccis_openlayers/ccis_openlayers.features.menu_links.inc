<?php
/**
 * @file
 * ccis_openlayers.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ccis_openlayers_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_map:map
  $menu_links['main-menu_map:map'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'map',
    'router_path' => 'map',
    'link_title' => 'Map',
    'options' => array(
      'identifier' => 'main-menu_map:map',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -30,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Map');


  return $menu_links;
}
