<?php
/**
 * @file
 * pm_taxonomy_term_template.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function pm_taxonomy_term_template_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__panel_context_d512d93d-ed17-4ae0-9b16-963e4289eb07';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Taxonomy Listing',
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
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'one-col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'main_content_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7799a698-2833-4421-bf5f-84164b6dcfa4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-91fb6533-a997-4401-96a3-d5284ff14405';
    $pane->panel = 'main_content_column';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_taxonomy_listing-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '91fb6533-a997-4401-96a3-d5284ff14405';
    $display->content['new-91fb6533-a997-4401-96a3-d5284ff14405'] = $pane;
    $display->panels['main_content_column'][0] = 'new-91fb6533-a997-4401-96a3-d5284ff14405';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__panel_context_d512d93d-ed17-4ae0-9b16-963e4289eb07'] = $handler;

  return $export;
}
