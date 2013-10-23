<?php
/**
 * @file
 * ccis_events.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ccis_events_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_events--news:events
  $menu_links['main-menu_events--news:events'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'events',
    'router_path' => 'events',
    'link_title' => 'Events & News',
    'options' => array(
      'identifier' => 'main-menu_events--news:events',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Events & News');


  return $menu_links;
}
