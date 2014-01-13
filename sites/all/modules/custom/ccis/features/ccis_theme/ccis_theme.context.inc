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
          'weight' => '-21',
        ),
        'boxes-socialmedia' => array(
          'module' => 'boxes',
          'delta' => 'socialmedia',
          'region' => 'utilities',
          'weight' => '-20',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'utilities',
          'weight' => '-19',
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
        'boxes-contactinfo' => array(
          'module' => 'boxes',
          'delta' => 'contactinfo',
          'region' => 'footer_secondcolumn',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'footer_thirdcolumn',
          'weight' => '-10',
        ),
        'menu-menu-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu',
          'region' => 'footer_fourthcolumn',
          'weight' => '-10',
        ),
        'simplenews-1' => array(
          'module' => 'simplenews',
          'delta' => '1',
          'region' => 'footer_fourthcolumn',
          'weight' => '-9',
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
