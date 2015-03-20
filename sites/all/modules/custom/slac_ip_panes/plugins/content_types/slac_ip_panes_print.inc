<?php
/**
 * @file
 * Creates Print link.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Print link'),
  'description' => t('Provides a print link.'),
  'category' => t('SLAC IP'),
  'single' => TRUE,
  'render callback' => 'slac_ip_panes_print_render',
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
function slac_ip_panes_print_render($subtype, $conf, $args, $context) {
  $pane = new stdClass();
  $pane->title = t('');
  $pane->content = '<div class="js-print-button"></div>';
  drupal_add_js(drupal_get_path('module', 'slac_ip_panes') . '/plugins/content_types/print.js');
  return $pane;
}
