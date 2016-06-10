<?php
/**
 * @file
 * ledger_progress_complete.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ledger_progress_complete_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_f185b89f-977a-4766-8e0a-2054b264dc50';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -22;
  $handler->conf = array(
    'title' => 'Improvement Ledger',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'ledger_post' => 'ledger_post',
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
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Improvement & Collaboration';
  $display->uuid = '0fa0c7f6-6e4c-4f28-b77b-6a68410327c6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-39198a4c-c409-4b42-aa71-0316cb0c9dff';
    $pane->panel = 'left';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'markup' => 'h2',
      'id' => '',
      'class' => '',
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
    $pane->uuid = '39198a4c-c409-4b42-aa71-0316cb0c9dff';
    $display->content['new-39198a4c-c409-4b42-aa71-0316cb0c9dff'] = $pane;
    $display->panels['left'][0] = 'new-39198a4c-c409-4b42-aa71-0316cb0c9dff';
    $pane = new stdClass();
    $pane->pid = 'new-d805d30c-9e05-49b7-92f9-ce6b76a3821d';
    $pane->panel = 'left';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'd805d30c-9e05-49b7-92f9-ce6b76a3821d';
    $display->content['new-d805d30c-9e05-49b7-92f9-ce6b76a3821d'] = $pane;
    $display->panels['left'][1] = 'new-d805d30c-9e05-49b7-92f9-ce6b76a3821d';
    $pane = new stdClass();
    $pane->pid = 'new-813a28c4-eeac-41ab-bf50-63d5f007259c';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'improvement and collaboration blurb',
      'title' => 'About the Ledger',
      'body' => '<p>Blurb explaining the process, and the criteria for suggestion acceptance.</p>
<p>link to form to suggest improvments.</p>
<p>&nbsp;</p>
',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white blue-dashed-list',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '813a28c4-eeac-41ab-bf50-63d5f007259c';
    $display->content['new-813a28c4-eeac-41ab-bf50-63d5f007259c'] = $pane;
    $display->panels['left'][2] = 'new-813a28c4-eeac-41ab-bf50-63d5f007259c';
    $pane = new stdClass();
    $pane->pid = 'new-4f8cd2fb-c9e5-4d6d-b4d0-cbef734b5ea3';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'ledger_front_list-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4f8cd2fb-c9e5-4d6d-b4d0-cbef734b5ea3';
    $display->content['new-4f8cd2fb-c9e5-4d6d-b4d0-cbef734b5ea3'] = $pane;
    $display->panels['right'][0] = 'new-4f8cd2fb-c9e5-4d6d-b4d0-cbef734b5ea3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_f185b89f-977a-4766-8e0a-2054b264dc50'] = $handler;

  return $export;
}
