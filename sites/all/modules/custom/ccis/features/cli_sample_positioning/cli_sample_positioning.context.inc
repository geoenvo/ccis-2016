<?php
/**
 * @file
 * cli_sample_positioning.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cli_sample_positioning_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home_page_content';
  $context->description = 'organizes default blocks on font page';
  $context->tag = 'CCIS';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-slideshow-block' => array(
          'module' => 'views',
          'delta' => 'slideshow-block',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'views-events-block_events' => array(
          'module' => 'views',
          'delta' => 'events-block_events',
          'region' => 'content',
          'weight' => '-24',
        ),
        'views-news_via_feeds-block_newsfeed' => array(
          'module' => 'views',
          'delta' => 'news_via_feeds-block_newsfeed',
          'region' => 'content',
          'weight' => '-23',
        ),
        'views-blogpage-block' => array(
          'module' => 'views',
          'delta' => 'blogpage-block',
          'region' => 'content',
          'weight' => '-4',
        ),
        'views-status_feed-block' => array(
          'module' => 'views',
          'delta' => 'status_feed-block',
          'region' => 'content',
          'weight' => '-21',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CCIS');
  t('organizes default blocks on font page');
  $export['home_page_content'] = $context;

  return $export;
}
