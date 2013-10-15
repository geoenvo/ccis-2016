<?php
/**
 * @file
 * cli_footer_blocks.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function cli_footer_blocks_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer-menu_help:node/9
  $menu_links['menu-footer-menu_help:node/9'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/9',
    'router_path' => 'node/%',
    'link_title' => 'Help',
    'options' => array(
      'identifier' => 'menu-footer-menu_help:node/9',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-menu_legal:node/8
  $menu_links['menu-footer-menu_legal:node/8'] = array(
    'menu_name' => 'menu-footer-menu',
    'link_path' => 'node/8',
    'router_path' => 'node/%',
    'link_title' => 'Legal',
    'options' => array(
      'attributes' => array(
        'title' => 'Legal notice',
      ),
      'identifier' => 'menu-footer-menu_legal:node/8',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Help');
  t('Legal');


  return $menu_links;
}
