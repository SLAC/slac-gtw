<?php
/**
 * @file
 * Combines the Related files and Related links field output into one list.
 */

$plugin = array(
  'title' => t('SLAC Combined Related Items List'),
  'description' => t("Displays the node's related files and related links in a single list."),
  'category' => t('SLAC IP'),
  'single' => TRUE,
  'render callback' => 'slac_ip_combined_related_items_content_type_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'slac_ip_combined_related_items_content_type_edit_form',
  'all contexts' => TRUE,
);

/**
 * Run-time rendering of the body of the block (content type)
 *
 * @param $subtype
 *   Panel subtype.
 * @param $conf
 *   Configuration as done at admin time
 * @param array $args
 *   Panel arguments.
 * @param string $context
 *   Panel context.
 *
 * @return object
 *   An object with at least title and content members
 */
function slac_ip_combined_related_items_content_type_render($subtype, $conf, $args, $context) {
  $node_context = reset($context);
  $node = $node_context->data;

  $field_names = array(
    'field_shared_related_files' => array(
      'label' => 'hidden',
      'type' => 'file_download_link',
    ),
    'field_shared_related_links' => array(
      'label' => 'hidden',
      'type' => 'link_default',
    ),
  );

  $list_items = array();

  foreach ($field_names as $field_name => $format) {
    $field_items = field_get_items('node', $node, $field_name);

    foreach ($field_items as $item) {
      $render_array = field_view_value('node', $node, $field_name, $item, $format);
      $list_items[] = drupal_render($render_array);
    }
  }

  if (empty($list_items)) {
    return;
  }

  $block = new stdClass();
  $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';

  $list = array(
    'items' => $list_items,
  );
  $block->content = theme('item_list', $list);

  return $block;
}

/**
 * 'Edit' callback for the content type.
 */
function slac_ip_combined_related_items_content_type_edit_form($form, &$form_state) {
  return $form;
}
