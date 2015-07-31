<?php
/**
 * @file
 * Creates a flag link for anonymous users that redirects them to the log in form.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Anonymous flag link'),
  'description' => t('Provides a flag link pane that redirects users to the login form and then back to the item they wish to flag.'),
  'category' => t('Flea Market Item'),
  'single' => TRUE,
  'render callback' => 'ct_flea_market_item_anonymous_flag_render',
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
function ct_flea_market_item_anonymous_flag_render($subtype, $conf, $args, $context) {
  global $user;
  if (!$user->uid) {
    $link = l(
      t('Report as inappropriate'), 
      'user/login/', 
      array(
        'query'=> array(
          'destination' => $context['argument_entity_id:node_1']->data->path['source']
        ),
        'attributes' => array(
          'class' => 'flag',
          'title' => 'Report as Inappropriate',
          'rel' => 'nofollow',
        ),
      )
    );
    $content = '<span class="flag-wrapper flag-flea-market-inappropriate">';
    $content .= $link . '</span>';
    $pane = new stdClass();
    $pane->title = t('');
    $pane->content = $content; 
    return $pane;
  }
}

