<?php
/**
 * @file
 * pm_access_notices.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function pm_access_notices_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'access_notices';
  $page->task = 'page';
  $page->admin_title = 'Access Notices';
  $page->admin_description = '';
  $page->path = 'access';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_access_notices__panel_context_2c9df7b6-6246-44b1-ae46-fe75720a7ac1';
  $handler->task = 'page';
  $handler->subtask = 'access_notices';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $display->title = 'Access Notices';
  $display->uuid = '0006b0b0-cc6b-4079-8ff6-3fd69a9c8830';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_access_notices__panel_context_2c9df7b6-6246-44b1-ae46-fe75720a7ac1';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8c417eaf-4f67-4715-bc57-d6719993fa23';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 'access_notice_listing-panel_pane_1';
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
  $pane->uuid = '8c417eaf-4f67-4715-bc57-d6719993fa23';
  $display->content['new-8c417eaf-4f67-4715-bc57-d6719993fa23'] = $pane;
  $display->panels['left'][0] = 'new-8c417eaf-4f67-4715-bc57-d6719993fa23';
  $pane = new stdClass();
  $pane->pid = 'new-95ac6556-45d5-4b30-9de7-026d4c80295f';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Access Notices Feed link',
    'title' => '',
    'body' => '<div class="feed-icon"><a class="feed-icon" href="/access/feed" title="Subscribe to SLAC Access Notices"><img alt="Access Notices RSS Feed Icon" height="16" src="/misc/feed.png" width="16"> Access Notices RSS Feed</a></div>',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '95ac6556-45d5-4b30-9de7-026d4c80295f';
  $display->content['new-95ac6556-45d5-4b30-9de7-026d4c80295f'] = $pane;
  $display->panels['right'][0] = 'new-95ac6556-45d5-4b30-9de7-026d4c80295f';
  $pane = new stdClass();
  $pane->pid = 'new-a0f32989-d04a-4af3-845f-650abfd647f7';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a0f32989-d04a-4af3-845f-650abfd647f7';
  $display->content['new-a0f32989-d04a-4af3-845f-650abfd647f7'] = $pane;
  $display->panels['right'][1] = 'new-a0f32989-d04a-4af3-845f-650abfd647f7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['access_notices'] = $page;

  return $pages;

}
