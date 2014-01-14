<?php
/**
 * @file
 * ccis_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ccis_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'event';
  $context->description = 'menu position + breadcrumb for event';
  $context->tag = 'CCIS';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'breadcrumb' => 'events',
    'menu' => 'events',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('CCIS');
  t('menu position + breadcrumb for event');
  $export['event'] = $context;

  return $export;
}
