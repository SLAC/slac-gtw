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
  $handler->weight = -21;
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
  $display->title = '%node:title';
  $display->uuid = '0fa0c7f6-6e4c-4f28-b77b-6a68410327c6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d805d30c-9e05-49b7-92f9-ce6b76a3821d';
    $pane->panel = 'left';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd805d30c-9e05-49b7-92f9-ce6b76a3821d';
    $display->content['new-d805d30c-9e05-49b7-92f9-ce6b76a3821d'] = $pane;
    $display->panels['left'][0] = 'new-d805d30c-9e05-49b7-92f9-ce6b76a3821d';
    $pane = new stdClass();
    $pane->pid = 'new-edc2017d-4085-4809-ae6b-5f18e8c9a437';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_file';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'file_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'text' => 'Ledger Document: [file:name]',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'edc2017d-4085-4809-ae6b-5f18e8c9a437';
    $display->content['new-edc2017d-4085-4809-ae6b-5f18e8c9a437'] = $pane;
    $display->panels['left'][1] = 'new-edc2017d-4085-4809-ae6b-5f18e8c9a437';
    $pane = new stdClass();
    $pane->pid = 'new-813a28c4-eeac-41ab-bf50-63d5f007259c';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'improvement and collaboration blurb',
      'title' => '<none>',
      'body' => '<p><span style="font-family: Helvetica; font-size: 15px; font-variant-ligatures: normal; font-variant-position: normal; font-variant-numeric: normal; font-variant-alternates: normal; font-variant-east-asian: normal; line-height: normal;">In response to the feedback from staff, the "Improvement &amp; Collaboration Ledger" is a place to highlight the actions SLAC is taking to streamline what do and how we work together to get things done. The types of processes and activities highlighted in the ledger can vary widely, and are in no way representative of the full expanse of activities happening at SLAC. Instead, the ledger is simply meant as a way to raise lab-wide awareness over a few of the ways SLAC is working to remove administrative roadblocks and frustrations in order to focus our time and energy on work that truly advances the mission of the lab. See&nbsp;</span><a href="/content/about-improvement-collaboration-ledger" style="color: rgb(149, 79, 114); text-decoration: underline; font-family: Helvetica; font-size: 15px; font-variant-ligatures: normal; font-variant-position: normal; font-variant-numeric: normal; font-variant-alternates: normal; font-variant-east-asian: normal; line-height: normal;">About the Improvement &amp; Collaboration Ledger</a><span style="font-family: Helvetica; font-size: 15px; font-variant-ligatures: normal; font-variant-position: normal; font-variant-numeric: normal; font-variant-alternates: normal; font-variant-east-asian: normal; line-height: normal;">&nbsp;and&nbsp;</span><a href="/content/about-efficiency-initiative" style="color: rgb(149, 79, 114); text-decoration: underline; font-family: Helvetica; font-size: 15px; font-variant-ligatures: normal; font-variant-position: normal; font-variant-numeric: normal; font-variant-alternates: normal; font-variant-east-asian: normal; line-height: normal;">About the Efficiency Initiative</a><span style="font-family: Helvetica; font-size: 15px; font-variant-ligatures: normal; font-variant-position: normal; font-variant-numeric: normal; font-variant-alternates: normal; font-variant-east-asian: normal; line-height: normal;">&nbsp;for more information.</span></p>
',
      'format' => 'full_html',
      'substitute' => 1,
      'name' => 'ledger_background_info_blurb',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
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
