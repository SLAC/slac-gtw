<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('SLAC Node author'),
  'icon' => 'icon_node.png',
  'description' => t('The author of the referenced node, linked to the SLAC directory.'),
  'render callback' => 'slac_ip_node_author_content_type_render',
  'edit form' => 'slac_ip_node_author_content_type_edit_form',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('SLAC IP'),
);

/**
 * Render the custom content type.
 */
function slac_ip_node_author_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  // Get a shortcut to the node.
  $node = $context->data;
  $user = user_load($node->uid);

  // Build the content type block.
  $block = new stdClass();
  $block->module = 'slac_ip_node_author';
  $block->title = t('Author (SLAC Dir link)');
  $block->content = l($user->name, 'http://www-public.slac.stanford.edu/phonebook/dirsearch.aspx?mailid=' . $user->name);
  $block->delta = $node->nid;

  return $block;
}

/**
 * Returns an edit form for custom type settings.
 */
function slac_ip_node_author_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Returns the administrative title for a type.
 */
function slac_ip_node_author_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" author', array('@s' => $context->identifier));
}
