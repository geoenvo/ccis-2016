<?php
/**
 * @file
 * ccis_feedback.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ccis_feedback_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-menu_feedback:contact
  $menu_links['menu-footer-menu_feedback:contact'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Feedback',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer-menu_feedback:contact',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Feedback');


  return $menu_links;
}
