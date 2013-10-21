<?php
/**
 * @file
 * ccis_theme.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ccis_theme_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global_elements';
  $context->description = 'organizes information in header and footer blocks';
  $context->tag = 'CCIS';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'lang_dropdown-language' => array(
          'module' => 'lang_dropdown',
          'delta' => 'language',
          'region' => 'utilities',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'utilities',
          'weight' => '-9',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'utilities',
          'weight' => '-8',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'user',
          'weight' => '-10',
        ),
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'user',
          'weight' => '-9',
        ),
        'views-sponsor_logos-block_sponsors' => array(
          'module' => 'views',
          'delta' => 'sponsor_logos-block_sponsors',
          'region' => 'footer_firstcolumn',
          'weight' => '-10',
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'footer_secondcolumn',
          'weight' => '-10',
        ),
        'menu-menu-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu',
          'region' => 'footer_thirdcolumn',
          'weight' => '-10',
        ),
        'simplenews-6' => array(
          'module' => 'simplenews',
          'delta' => '6',
          'region' => 'footer_thirdcolumn',
          'weight' => '-9',
        ),
        'system-navigation' => array(
          'module' => 'system',
          'delta' => 'navigation',
          'region' => 'bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CCIS');
  t('organizes information in header and footer blocks');
  $export['global_elements'] = $context;

  return $export;
}
