<?php
/**
 * @file
 * slac_igp_resources.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function slac_igp_resources_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'research_resources';
  $context->description = '';
  $context->tag = 'Research Resources';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'research-resources' => 'research-resources',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-research_resources-block' => array(
          'module' => 'views',
          'delta' => 'research_resources-block',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Research Resources');
  $export['research_resources'] = $context;

  return $export;
}
