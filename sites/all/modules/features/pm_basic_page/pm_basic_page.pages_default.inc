<?php
/**
 * @file
 * pm_basic_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function pm_basic_page_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_12aad465-b8c6-4864-852e-a1cd1b2056d1';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Daily Email Signup',
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
              'page' => 'page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'daily-email-signup',
          ),
          'context' => 'empty',
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
  $display->uuid = 'e737ad76-e694-4d2a-9c12-7e525717e7c3';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_12aad465-b8c6-4864-852e-a1cd1b2056d1';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3fd0e99a-2845-4ac3-84f8-4ec29ad44331';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_page_subtitle';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3fd0e99a-2845-4ac3-84f8-4ec29ad44331';
  $display->content['new-3fd0e99a-2845-4ac3-84f8-4ec29ad44331'] = $pane;
  $display->panels['left'][0] = 'new-3fd0e99a-2845-4ac3-84f8-4ec29ad44331';
  $pane = new stdClass();
  $pane->pid = 'new-96dae3be-64f1-4e69-be14-1c473a73f2f5';
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
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '96dae3be-64f1-4e69-be14-1c473a73f2f5';
  $display->content['new-96dae3be-64f1-4e69-be14-1c473a73f2f5'] = $pane;
  $display->panels['left'][1] = 'new-96dae3be-64f1-4e69-be14-1c473a73f2f5';
  $pane = new stdClass();
  $pane->pid = 'new-9a94f54a-d3f7-4e0e-bf66-c011ae86cc35';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'mailchimp_lists-daily_email';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '9a94f54a-d3f7-4e0e-bf66-c011ae86cc35';
  $display->content['new-9a94f54a-d3f7-4e0e-bf66-c011ae86cc35'] = $pane;
  $display->panels['left'][2] = 'new-9a94f54a-d3f7-4e0e-bf66-c011ae86cc35';
  $pane = new stdClass();
  $pane->pid = 'new-0d9d6705-5c12-43a8-b433-5786db245536';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'related_resources';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
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
  $pane->uuid = '0d9d6705-5c12-43a8-b433-5786db245536';
  $display->content['new-0d9d6705-5c12-43a8-b433-5786db245536'] = $pane;
  $display->panels['right'][0] = 'new-0d9d6705-5c12-43a8-b433-5786db245536';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_12aad465-b8c6-4864-852e-a1cd1b2056d1'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_8d12f796-cd75-47b3-9908-c14756a58158';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'A-Z index',
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
        1 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'a-z',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
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
      'main_content_column' => NULL,
      'staffresourcestop' => NULL,
      'rowonecolone' => NULL,
      'rowonecoltwo' => NULL,
      'rowonecolthree' => NULL,
      'rowtwocolone' => NULL,
      'rowtwocoltwo' => NULL,
      'rowtwocolthree' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e737ad76-e694-4d2a-9c12-7e525717e7c3';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_8d12f796-cd75-47b3-9908-c14756a58158';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3fd0e99a-2845-4ac3-84f8-4ec29ad44331';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_page_subtitle';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3fd0e99a-2845-4ac3-84f8-4ec29ad44331';
  $display->content['new-3fd0e99a-2845-4ac3-84f8-4ec29ad44331'] = $pane;
  $display->panels['left'][0] = 'new-3fd0e99a-2845-4ac3-84f8-4ec29ad44331';
  $pane = new stdClass();
  $pane->pid = 'new-8fcdd5f6-6e62-4157-80df-576368445fa0';
  $pane->panel = 'left';
  $pane->type = 'views';
  $pane->subtype = 'staff_resource_modern';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_4',
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
  $pane->uuid = '8fcdd5f6-6e62-4157-80df-576368445fa0';
  $display->content['new-8fcdd5f6-6e62-4157-80df-576368445fa0'] = $pane;
  $display->panels['left'][1] = 'new-8fcdd5f6-6e62-4157-80df-576368445fa0';
  $pane = new stdClass();
  $pane->pid = 'new-96dae3be-64f1-4e69-be14-1c473a73f2f5';
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
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '96dae3be-64f1-4e69-be14-1c473a73f2f5';
  $display->content['new-96dae3be-64f1-4e69-be14-1c473a73f2f5'] = $pane;
  $display->panels['left'][2] = 'new-96dae3be-64f1-4e69-be14-1c473a73f2f5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_8d12f796-cd75-47b3-9908-c14756a58158'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Basic Page',
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
              'page' => 'page',
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
  $display->uuid = 'e737ad76-e694-4d2a-9c12-7e525717e7c3';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3fd0e99a-2845-4ac3-84f8-4ec29ad44331';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_page_subtitle';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3fd0e99a-2845-4ac3-84f8-4ec29ad44331';
  $display->content['new-3fd0e99a-2845-4ac3-84f8-4ec29ad44331'] = $pane;
  $display->panels['left'][0] = 'new-3fd0e99a-2845-4ac3-84f8-4ec29ad44331';
  $pane = new stdClass();
  $pane->pid = 'new-96dae3be-64f1-4e69-be14-1c473a73f2f5';
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
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '96dae3be-64f1-4e69-be14-1c473a73f2f5';
  $display->content['new-96dae3be-64f1-4e69-be14-1c473a73f2f5'] = $pane;
  $display->panels['left'][1] = 'new-96dae3be-64f1-4e69-be14-1c473a73f2f5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Staff Resource',
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
        1 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'staff-resources',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'staff_resources';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'right',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_',
          1 => 'center__',
          2 => 'right_',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'left_' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => '33.74218374218374',
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      'center__' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '33.173143745962',
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      'right_' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '33.084672511854265',
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => NULL,
      'left' => NULL,
      'center_' => NULL,
      'right' => NULL,
      'left_' => NULL,
      'center__' => NULL,
      'right_' => NULL,
      'staffresourcesone' => NULL,
      'staffresourcestwo' => NULL,
      'rowonecolone' => NULL,
      'rowonecoltwo' => NULL,
      'rowonecolthree' => NULL,
      'rowtwocolone' => NULL,
      'rowtwocoltwo' => NULL,
      'rowtwocoltree' => NULL,
      'staffresourcestop' => NULL,
      'rowtwocolthree' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Staff Resources';
  $display->uuid = '5c20923d-b5f0-494c-b55e-a0764252b2ad';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-631fda72-be47-42f5-b72b-e5bd0fd98ede';
  $pane->panel = 'rowonecolone';
  $pane->type = 'views';
  $pane->subtype = 'organization';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => 'Mission Support',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'right-block',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '631fda72-be47-42f5-b72b-e5bd0fd98ede';
  $display->content['new-631fda72-be47-42f5-b72b-e5bd0fd98ede'] = $pane;
  $display->panels['rowonecolone'][0] = 'new-631fda72-be47-42f5-b72b-e5bd0fd98ede';
  $pane = new stdClass();
  $pane->pid = 'new-48d46b85-543a-4dca-8776-393f09b117b3';
  $pane->panel = 'rowonecolone';
  $pane->type = 'views';
  $pane->subtype = 'organization';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => 'Infrastructure and Safety',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'right-block',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '48d46b85-543a-4dca-8776-393f09b117b3';
  $display->content['new-48d46b85-543a-4dca-8776-393f09b117b3'] = $pane;
  $display->panels['rowonecolone'][1] = 'new-48d46b85-543a-4dca-8776-393f09b117b3';
  $pane = new stdClass();
  $pane->pid = 'new-5d926d2d-3df3-47b7-b3a5-4ac1396b1807';
  $pane->panel = 'rowonecolthree';
  $pane->type = 'views';
  $pane->subtype = 'organization';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => 'Science Directorate',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'right-block',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5d926d2d-3df3-47b7-b3a5-4ac1396b1807';
  $display->content['new-5d926d2d-3df3-47b7-b3a5-4ac1396b1807'] = $pane;
  $display->panels['rowonecolthree'][0] = 'new-5d926d2d-3df3-47b7-b3a5-4ac1396b1807';
  $pane = new stdClass();
  $pane->pid = 'new-497b2b57-41e7-49a0-8afc-de78486f0bcd';
  $pane->panel = 'rowonecoltwo';
  $pane->type = 'views';
  $pane->subtype = 'organization';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => 'Accelerator Directorate',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => 'Organizational Links',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'right-block',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '497b2b57-41e7-49a0-8afc-de78486f0bcd';
  $display->content['new-497b2b57-41e7-49a0-8afc-de78486f0bcd'] = $pane;
  $display->panels['rowonecoltwo'][0] = 'new-497b2b57-41e7-49a0-8afc-de78486f0bcd';
  $pane = new stdClass();
  $pane->pid = 'new-4b74aabe-b662-462a-b8f7-38fc03af7379';
  $pane->panel = 'rowtwocolone';
  $pane->type = 'views';
  $pane->subtype = 'organization';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => 'LCLS Directorate',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'right-block',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4b74aabe-b662-462a-b8f7-38fc03af7379';
  $display->content['new-4b74aabe-b662-462a-b8f7-38fc03af7379'] = $pane;
  $display->panels['rowtwocolone'][0] = 'new-4b74aabe-b662-462a-b8f7-38fc03af7379';
  $pane = new stdClass();
  $pane->pid = 'new-785b6ed3-aa14-4be8-9914-68b3d2e7b4bd';
  $pane->panel = 'rowtwocolthree';
  $pane->type = 'views';
  $pane->subtype = 'organization';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => 'Technology Innovation Directorate',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'right-block',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '785b6ed3-aa14-4be8-9914-68b3d2e7b4bd';
  $display->content['new-785b6ed3-aa14-4be8-9914-68b3d2e7b4bd'] = $pane;
  $display->panels['rowtwocolthree'][0] = 'new-785b6ed3-aa14-4be8-9914-68b3d2e7b4bd';
  $pane = new stdClass();
  $pane->pid = 'new-646b8d0a-a0cc-4256-bdb7-16f7ccd423c1';
  $pane->panel = 'rowtwocoltwo';
  $pane->type = 'views';
  $pane->subtype = 'organization';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => 'SSRL Directorate',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'right-block',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '646b8d0a-a0cc-4256-bdb7-16f7ccd423c1';
  $display->content['new-646b8d0a-a0cc-4256-bdb7-16f7ccd423c1'] = $pane;
  $display->panels['rowtwocoltwo'][0] = 'new-646b8d0a-a0cc-4256-bdb7-16f7ccd423c1';
  $pane = new stdClass();
  $pane->pid = 'new-032384b2-93db-45ce-8b3b-6e7138d96822';
  $pane->panel = 'staffresourcestop';
  $pane->type = 'node_body';
  $pane->subtype = 'node_body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'switch-link',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '032384b2-93db-45ce-8b3b-6e7138d96822';
  $display->content['new-032384b2-93db-45ce-8b3b-6e7138d96822'] = $pane;
  $display->panels['staffresourcestop'][0] = 'new-032384b2-93db-45ce-8b3b-6e7138d96822';
  $pane = new stdClass();
  $pane->pid = 'new-38bfe0e6-0389-4127-a7dc-080688327551';
  $pane->panel = 'staffresourcestop';
  $pane->type = 'block';
  $pane->subtype = 'quicktabs-staff_resources';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '38bfe0e6-0389-4127-a7dc-080688327551';
  $display->content['new-38bfe0e6-0389-4127-a7dc-080688327551'] = $pane;
  $display->panels['staffresourcestop'][1] = 'new-38bfe0e6-0389-4127-a7dc-080688327551';
  $pane = new stdClass();
  $pane->pid = 'new-cf6b817c-b53a-4408-bb6d-cb26ba960e66';
  $pane->panel = 'staffresourcestop';
  $pane->type = 'block';
  $pane->subtype = 'quicktabs-staff_resources_mobile_';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Staff Resources',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'cf6b817c-b53a-4408-bb6d-cb26ba960e66';
  $display->content['new-cf6b817c-b53a-4408-bb6d-cb26ba960e66'] = $pane;
  $display->panels['staffresourcestop'][2] = 'new-cf6b817c-b53a-4408-bb6d-cb26ba960e66';
  $pane = new stdClass();
  $pane->pid = 'new-dba63326-1bc4-4316-aca8-8eb3b685aa11';
  $pane->panel = 'staffresourcestop';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<h2>Organization Index</h2>',
    'format' => 'full_html',
    'substitute' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'dba63326-1bc4-4316-aca8-8eb3b685aa11';
  $display->content['new-dba63326-1bc4-4316-aca8-8eb3b685aa11'] = $pane;
  $display->panels['staffresourcestop'][3] = 'new-dba63326-1bc4-4316-aca8-8eb3b685aa11';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  return $export;
}
