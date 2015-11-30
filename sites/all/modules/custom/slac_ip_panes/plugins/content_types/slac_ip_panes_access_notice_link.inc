<?php
/**
 * @file
 * Creates a link to the access notices page.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Access Notice link'),
  'description' => t('Provides a link to the access notices as a pane.'),
  'category' => t('SLAC IP'),
  'single' => TRUE,
  'render callback' => 'slac_ip_panes_access_notice_render',
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
function slac_ip_panes_access_notice_render($subtype, $conf, $args, $context) {
  $pane = new stdClass();
  $pane->title = t('');
  $pane->content = '<a href="/access" class="page-icon">Access Notice</a>';
  return $pane;
}
