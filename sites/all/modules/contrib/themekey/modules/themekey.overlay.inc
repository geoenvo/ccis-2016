<?php

/**
 * @file
 * Provides some og attributes as ThemeKey properties.
 *
 * @author Markus Kalkbrenner | bio.logis GmbH
 *   @see http://drupal.org/user/124705
 *
 * @author daggerhart
 *   @see http://drupal.org/user/167806
 */

/**
* Implements hook_themekey_properties().
*
* Provides additional properties for module ThemeKey:
* - overlay:mode
*
* @return
* array of themekey properties and mapping functions
*/
function themekey_overlay_themekey_properties() {
  // Attributes for properties
  $attributes = array();
  $attributes['overlay:mode'] = array(
    'description' => t('Overlay: mode - The overlay mode current content is shown'),
    'validator' => 'themekey_validator_overlay_mode',
    'page cache' => THEMEKEY_PAGECACHE_UNSUPPORTED,
  );

  // Mapping functions
  $maps = array();
  $maps[] = array('src' => 'system:dummy',
                  'dst' => 'overlay:mode',
                  'callback' => 'themekey_overlay_dummy2mode');

  return array('attributes' => $attributes, 'maps' => $maps);
}

/**
 * ThemeKey mapping function to set a
 * ThemeKey property's value (destination)
 * with the aid of another ThemeKey property (source).
 *
 * src: system:dummy
 * dst: overlay:mode
 *
 * @param $nid
 *   a node id
 *
 * @return
 *   string
 */
function themekey_overlay_dummy2mode() {
  // hook_init() is called after hook_custom_theme()
  overlay_init();
  return overlay_get_mode();
}
