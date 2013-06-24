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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'staff_resources';
  $context->description = '';
  $context->tag = 'Staff Resources';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'staff-resources' => 'staff-resources',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'quicktabs-staff_resources' => array(
          'module' => 'quicktabs',
          'delta' => 'staff_resources',
          'region' => 'content',
          'weight' => '9',
        ),
        'views-staff_resources_classic-block_3' => array(
          'module' => 'views',
          'delta' => 'staff_resources_classic-block_3',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Staff Resources');
  $export['staff_resources'] = $context;

  return $export;
}
