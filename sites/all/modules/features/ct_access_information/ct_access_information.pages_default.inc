<?php
/**
 * @file
 * ct_access_information.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ct_access_information_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_8ae96847-f0c2-47e5-8809-9cffcc9a003a';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Access Information',
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
              'access_information' => 'access_information',
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
    $pane->pid = 'new-7854f869-b990-40d5-bbde-e350599a3ec2';
    $pane->panel = 'left';
    $pane->type = 'slac_ip_panes_access_notice_link';
    $pane->subtype = 'slac_ip_panes_access_notice_link';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7854f869-b990-40d5-bbde-e350599a3ec2';
    $display->content['new-7854f869-b990-40d5-bbde-e350599a3ec2'] = $pane;
    $display->panels['left'][0] = 'new-7854f869-b990-40d5-bbde-e350599a3ec2';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b55e0efb-f0ec-434f-b6b7-0a5318d6bb96';
    $display->content['new-b55e0efb-f0ec-434f-b6b7-0a5318d6bb96'] = $pane;
    $display->panels['left'][1] = 'new-b55e0efb-f0ec-434f-b6b7-0a5318d6bb96';
    $pane = new stdClass();
    $pane->pid = 'new-aee90b4c-7be3-40e0-9a4b-aaf2b5e2089c';
    $pane->panel = 'left';
    $pane->type = 'slac_ip_panes_add_calendar';
    $pane->subtype = 'slac_ip_panes_add_calendar';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'aee90b4c-7be3-40e0-9a4b-aaf2b5e2089c';
    $display->content['new-aee90b4c-7be3-40e0-9a4b-aaf2b5e2089c'] = $pane;
    $display->panels['left'][2] = 'new-aee90b4c-7be3-40e0-9a4b-aaf2b5e2089c';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '4f8acf74-36af-4808-ad21-22a45b1db07a';
    $display->content['new-4f8acf74-36af-4808-ad21-22a45b1db07a'] = $pane;
    $display->panels['left'][3] = 'new-4f8acf74-36af-4808-ad21-22a45b1db07a';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '974093cb-e49a-4a03-a827-1287f114ec82';
    $display->content['new-974093cb-e49a-4a03-a827-1287f114ec82'] = $pane;
    $display->panels['left'][4] = 'new-974093cb-e49a-4a03-a827-1287f114ec82';
    $pane = new stdClass();
    $pane->pid = 'new-e1eec562-4efa-4536-b49b-99ef8e66b5eb';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'slac_ip_access_date',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'value',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Start',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'e1eec562-4efa-4536-b49b-99ef8e66b5eb';
    $display->content['new-e1eec562-4efa-4536-b49b-99ef8e66b5eb'] = $pane;
    $display->panels['left'][5] = 'new-e1eec562-4efa-4536-b49b-99ef8e66b5eb';
    $pane = new stdClass();
    $pane->pid = 'new-35121f6c-0f35-42c8-b452-0163ab3a4603';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'slac_ip_access_date',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'value2',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'End',
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
    $pane->uuid = '35121f6c-0f35-42c8-b452-0163ab3a4603';
    $display->content['new-35121f6c-0f35-42c8-b452-0163ab3a4603'] = $pane;
    $display->panels['left'][6] = 'new-35121f6c-0f35-42c8-b452-0163ab3a4603';
    $pane = new stdClass();
    $pane->pid = 'new-0895acc9-cfca-41cc-9cde-31d9e164b38f';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_location';
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
      'override_title_text' => 'Location',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '0895acc9-cfca-41cc-9cde-31d9e164b38f';
    $display->content['new-0895acc9-cfca-41cc-9cde-31d9e164b38f'] = $pane;
    $display->panels['left'][7] = 'new-0895acc9-cfca-41cc-9cde-31d9e164b38f';
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
    $pane->pid = 'new-a2bd58aa-a059-465b-9a61-896fb94df5a7';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Tags',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 12;
    $pane->locks = array();
    $pane->uuid = 'a2bd58aa-a059-465b-9a61-896fb94df5a7';
    $display->content['new-a2bd58aa-a059-465b-9a61-896fb94df5a7'] = $pane;
    $display->panels['left'][12] = 'new-a2bd58aa-a059-465b-9a61-896fb94df5a7';
    $pane = new stdClass();
    $pane->pid = 'new-5b4630cf-1685-44ca-8678-e123336de9cc';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'file_rendered',
      'delta_limit' => '1',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'image_style' => '',
        'image_link' => '',
        'file_view_mode' => 'default',
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
    $pane->uuid = '5b4630cf-1685-44ca-8678-e123336de9cc';
    $display->content['new-5b4630cf-1685-44ca-8678-e123336de9cc'] = $pane;
    $display->panels['right'][0] = 'new-5b4630cf-1685-44ca-8678-e123336de9cc';
    $pane = new stdClass();
    $pane->pid = 'new-b1fe1112-ccd4-45f8-9445-851e0b5d0759';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_related_files';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'file_download_link',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'text' => 'Download [file:name]',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Related Links',
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
    $pane->uuid = 'b1fe1112-ccd4-45f8-9445-851e0b5d0759';
    $display->content['new-b1fe1112-ccd4-45f8-9445-851e0b5d0759'] = $pane;
    $display->panels['right'][1] = 'new-b1fe1112-ccd4-45f8-9445-851e0b5d0759';
    $pane = new stdClass();
    $pane->pid = 'new-461f7b0a-0942-416e-85b3-60d6d06a682d';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_related_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '461f7b0a-0942-416e-85b3-60d6d06a682d';
    $display->content['new-461f7b0a-0942-416e-85b3-60d6d06a682d'] = $pane;
    $display->panels['right'][2] = 'new-461f7b0a-0942-416e-85b3-60d6d06a682d';
    $pane = new stdClass();
    $pane->pid = 'new-16285bef-4df6-44f2-915a-af048e5e7af7';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-maps-and-directions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '16285bef-4df6-44f2-915a-af048e5e7af7';
    $display->content['new-16285bef-4df6-44f2-915a-af048e5e7af7'] = $pane;
    $display->panels['right'][3] = 'new-16285bef-4df6-44f2-915a-af048e5e7af7';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_8ae96847-f0c2-47e5-8809-9cffcc9a003a'] = $handler;

  return $export;
}
