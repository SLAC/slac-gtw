<?php
/**
 * @file
 * ct_flea_market_item.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ct_flea_market_item_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_46b39677-1751-4843-a63e-d4c6fd9577ea';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Flea Market Item',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'flea_market_post' => 'flea_market_post',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'two_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'staffresourcesone' => NULL,
      'rowone' => NULL,
      'rowtwo' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ae3476f0-b269-4ce6-bc60-9605390ba390';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3ac4071b-0c90-4f96-b926-042a043717bd';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Flea Market breadcrumb link',
      'title' => '',
      'body' => '<a href="/flea-market">Flea Market</a> &gt;',
      'format' => 'full_html',
      'substitute' => 0,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'page-breadcrumb',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3ac4071b-0c90-4f96-b926-042a043717bd';
    $display->content['new-3ac4071b-0c90-4f96-b926-042a043717bd'] = $pane;
    $display->panels['left'][0] = 'new-3ac4071b-0c90-4f96-b926-042a043717bd';
    $pane = new stdClass();
    $pane->pid = 'new-baf6fefc-b541-4eb9-b22c-c8e1c9c349ab';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_flea_market_item_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'baf6fefc-b541-4eb9-b22c-c8e1c9c349ab';
    $display->content['new-baf6fefc-b541-4eb9-b22c-c8e1c9c349ab'] = $pane;
    $display->panels['left'][1] = 'new-baf6fefc-b541-4eb9-b22c-c8e1c9c349ab';
    $pane = new stdClass();
    $pane->pid = 'new-a034e0e2-163c-4eb7-b3e3-2f2534580139';
    $pane->panel = 'left';
    $pane->type = 'flag_link';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'flag_name' => 'flea_market_inappropriate',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a034e0e2-163c-4eb7-b3e3-2f2534580139';
    $display->content['new-a034e0e2-163c-4eb7-b3e3-2f2534580139'] = $pane;
    $display->panels['left'][2] = 'new-a034e0e2-163c-4eb7-b3e3-2f2534580139';
    $pane = new stdClass();
    $pane->pid = 'new-b55e0efb-f0ec-434f-b6b7-0a5318d6bb96';
    $pane->panel = 'left';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'b55e0efb-f0ec-434f-b6b7-0a5318d6bb96';
    $display->content['new-b55e0efb-f0ec-434f-b6b7-0a5318d6bb96'] = $pane;
    $display->panels['left'][3] = 'new-b55e0efb-f0ec-434f-b6b7-0a5318d6bb96';
    $pane = new stdClass();
    $pane->pid = 'new-4f8acf74-36af-4808-ad21-22a45b1db07a';
    $pane->panel = 'left';
    $pane->type = 'slac_ip_panes_email';
    $pane->subtype = 'slac_ip_panes_email';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '4f8acf74-36af-4808-ad21-22a45b1db07a';
    $display->content['new-4f8acf74-36af-4808-ad21-22a45b1db07a'] = $pane;
    $display->panels['left'][4] = 'new-4f8acf74-36af-4808-ad21-22a45b1db07a';
    $pane = new stdClass();
    $pane->pid = 'new-974093cb-e49a-4a03-a827-1287f114ec82';
    $pane->panel = 'left';
    $pane->type = 'slac_ip_panes_print';
    $pane->subtype = 'slac_ip_panes_print';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '974093cb-e49a-4a03-a827-1287f114ec82';
    $display->content['new-974093cb-e49a-4a03-a827-1287f114ec82'] = $pane;
    $display->panels['left'][5] = 'new-974093cb-e49a-4a03-a827-1287f114ec82';
    $pane = new stdClass();
    $pane->pid = 'new-9b5c6f0a-dbdd-43ad-895c-8feed80f592b';
    $pane->panel = 'left';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'slac_ip_published_date',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '9b5c6f0a-dbdd-43ad-895c-8feed80f592b';
    $display->content['new-9b5c6f0a-dbdd-43ad-895c-8feed80f592b'] = $pane;
    $display->panels['left'][6] = 'new-9b5c6f0a-dbdd-43ad-895c-8feed80f592b';
    $pane = new stdClass();
    $pane->pid = 'new-497fa9cc-c2a4-40a3-a620-9d047b8c681e';
    $pane->panel = 'left';
    $pane->type = 'slac_ip_node_author';
    $pane->subtype = 'slac_ip_node_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Posted by:',
      'override_title_heading' => 'span',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '497fa9cc-c2a4-40a3-a620-9d047b8c681e';
    $display->content['new-497fa9cc-c2a4-40a3-a620-9d047b8c681e'] = $pane;
    $display->panels['left'][7] = 'new-497fa9cc-c2a4-40a3-a620-9d047b8c681e';
    $pane = new stdClass();
    $pane->pid = 'new-6fb84e3d-ad84-44ca-ac93-1e1139f8cc46';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '6fb84e3d-ad84-44ca-ac93-1e1139f8cc46';
    $display->content['new-6fb84e3d-ad84-44ca-ac93-1e1139f8cc46'] = $pane;
    $display->panels['left'][8] = 'new-6fb84e3d-ad84-44ca-ac93-1e1139f8cc46';
    $pane = new stdClass();
    $pane->pid = 'new-bdf5f8ab-6812-475a-8965-2f7e76904af4';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_contact_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Contact',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = 'bdf5f8ab-6812-475a-8965-2f7e76904af4';
    $display->content['new-bdf5f8ab-6812-475a-8965-2f7e76904af4'] = $pane;
    $display->panels['left'][9] = 'new-bdf5f8ab-6812-475a-8965-2f7e76904af4';
    $pane = new stdClass();
    $pane->pid = 'new-c6e26bec-57c4-46d9-a12b-0509f2e17b47';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_contact_email';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'email_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = 'c6e26bec-57c4-46d9-a12b-0509f2e17b47';
    $display->content['new-c6e26bec-57c4-46d9-a12b-0509f2e17b47'] = $pane;
    $display->panels['left'][10] = 'new-c6e26bec-57c4-46d9-a12b-0509f2e17b47';
    $pane = new stdClass();
    $pane->pid = 'new-671bf82c-db85-4bc1-8c45-c08b17a3a1e8';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_contact_phone';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $pane->uuid = '671bf82c-db85-4bc1-8c45-c08b17a3a1e8';
    $display->content['new-671bf82c-db85-4bc1-8c45-c08b17a3a1e8'] = $pane;
    $display->panels['left'][11] = 'new-671bf82c-db85-4bc1-8c45-c08b17a3a1e8';
    $pane = new stdClass();
    $pane->pid = 'new-9ed6f47e-ac57-428d-81ec-1e32a6da6497';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_flea_market_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'file_rendered',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'colorbox_node_style' => 'medium',
        'colorbox_node_style_first' => '',
        'colorbox_image_style' => '',
        'colorbox_gallery' => 'post',
        'colorbox_gallery_custom' => '',
        'colorbox_caption' => 'auto',
        'colorbox_caption_custom' => '',
        'file_view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9ed6f47e-ac57-428d-81ec-1e32a6da6497';
    $display->content['new-9ed6f47e-ac57-428d-81ec-1e32a6da6497'] = $pane;
    $display->panels['right'][0] = 'new-9ed6f47e-ac57-428d-81ec-1e32a6da6497';
    $pane = new stdClass();
    $pane->pid = 'new-b96c1115-8283-412e-905a-1e0f01723551';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_contact_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'trim_length' => '300',
        'trim_type' => 'chars',
        'trim_suffix' => '...',
        'trim_link' => '0',
        'more_link' => '0',
        'more_text' => 'Read more',
        'trim_options' => array(
          'text' => 0,
        ),
        'trim_preserve_tags' => '',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Contact',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b96c1115-8283-412e-905a-1e0f01723551';
    $display->content['new-b96c1115-8283-412e-905a-1e0f01723551'] = $pane;
    $display->panels['right'][1] = 'new-b96c1115-8283-412e-905a-1e0f01723551';
    $pane = new stdClass();
    $pane->pid = 'new-c40c2739-3bcf-4835-8b15-e4259b4b7a76';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_contact_email';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'email_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c40c2739-3bcf-4835-8b15-e4259b4b7a76';
    $display->content['new-c40c2739-3bcf-4835-8b15-e4259b4b7a76'] = $pane;
    $display->panels['right'][2] = 'new-c40c2739-3bcf-4835-8b15-e4259b4b7a76';
    $pane = new stdClass();
    $pane->pid = 'new-e48a3d2a-8897-442d-8542-e94d1b3adf8e';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_contact_phone';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e48a3d2a-8897-442d-8542-e94d1b3adf8e';
    $display->content['new-e48a3d2a-8897-442d-8542-e94d1b3adf8e'] = $pane;
    $display->panels['right'][3] = 'new-e48a3d2a-8897-442d-8542-e94d1b3adf8e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_46b39677-1751-4843-a63e-d4c6fd9577ea'] = $handler;

  return $export;
}
