<?php
/**
 * @file
 * Provide views data and handlers for termstatus.module
 */

/**
 * @defgroup views_termstatus_module termstatus.module handlers
 *
 * @{
 */

/**
 * Implements hook_views_data()
 */
function termstatus_views_data() {
  // ----------------------------------------------------------------------
  // termstatus table

  $data['termstatus']['table']['group']  = t('Taxonomy term');
  $data['termstatus']['table']['join'] = array(
    'taxonomy_term_data' => array(
      'left_field' => 'tid',
      'field' => 'tid',
    ),
  );

  $data['termstatus']['status'] = array(
    'title' => t('Published'),
    'help' => t('Whether or not the term is published.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
      'output formats' => array(
        'published-notpublished' => array(t('Published'), t('Not published')),
      ),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Published'),
      'type' => 'yes-no',
      'use equal' => TRUE, // Use status = 1 instead of status <> 0 in WHERE statment
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

/**
 * @}
 */
