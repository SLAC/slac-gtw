<?php
/**
 * @file
 * Creates a email link.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Email link'),
  'description' => t('Provides an email link.'),
  'category' => t('SLAC IP'),
  'single' => TRUE,
  'render callback' => 'slac_ip_panes_email_render',
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
function slac_ip_panes_email_render($subtype, $conf, $args, $context) {
  $title = $context['argument_entity_id:node_1']->data->title;
  $url = $GLOBALS['base_url'] . '/' . drupal_lookup_path('alias', current_path());
  $pane = new stdClass();
  $pane->title = t('');
  $pane->content = '<div class="email-button"><a href="mailto:?subject=' . $title;
  $pane->content .= '&body=' . $title . ' ' . $url . '">Email</a></div>';
  return $pane;
}
