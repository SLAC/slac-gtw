<?php
/**
 * @file
 * Creates a Add to Calendar link.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Add to Calendar link'),
  'description' => t('Provides a Add to Calendar link.'),
  'category' => t('SLAC IP'),
  'single' => TRUE,
  'render callback' => 'slac_ip_panes_add_calendar_render',
  'defaults' => array(
    'text' => '',
  ),
  'all contexts' => TRUE,
);

/**
 * Panel render callback.
 *
 * @param string $subtype
 *   Panel subtype.
 * @param array $conf
 *   Panel configuration.
 * @param array $args
 *   Panel arguments.
 * @param string $context
 *   Panel context.
 *
 * @return object
 *   Panel render object.
 */
function slac_ip_panes_add_calendar_render($subtype, $conf, $args, $context) {
  $pane = new stdClass();
  $pane->title = '';
  $pane->content = '<div class="calendar-button">' .
      l(t('Add to Calendar'), '') . '</div>';

  return $pane;
}
