<?php
/**
 * @file
 * pm_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function pm_news_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news';
  $page->task = 'page';
  $page->admin_title = 'News';
  $page->admin_description = 'temporary placeholder page for /news';
  $page->path = 'news';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'News',
    'name' => 'main-menu',
    'weight' => '-51',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_news__panel_context_4053b205-f89c-4845-b50c-037d2315e2d4';
  $handler->task = 'page';
  $handler->subtask = 'news';
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
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '40980e20-7d86-402b-b4c4-c6e45e9fcf77';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-30e087a9-f39c-4a72-b976-6dae3a733999';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'news_archive-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'exposed' => array(
        'field_news_news_type_value' => 'All',
        'date_filter' => array(
          'value' => NULL,
        ),
      ),
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
    $pane->uuid = '30e087a9-f39c-4a72-b976-6dae3a733999';
    $display->content['new-30e087a9-f39c-4a72-b976-6dae3a733999'] = $pane;
    $display->panels['left'][0] = 'new-30e087a9-f39c-4a72-b976-6dae3a733999';
    $pane = new stdClass();
    $pane->pid = 'new-e90ee0c5-df2e-4ae4-952c-41dce883c0a5';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-news_archive-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
      'override_title' => 1,
      'override_title_text' => 'News Archives',
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
    $pane->uuid = 'e90ee0c5-df2e-4ae4-952c-41dce883c0a5';
    $display->content['new-e90ee0c5-df2e-4ae4-952c-41dce883c0a5'] = $pane;
    $display->panels['right'][0] = 'new-e90ee0c5-df2e-4ae4-952c-41dce883c0a5';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-30e087a9-f39c-4a72-b976-6dae3a733999';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news'] = $page;

  return $pages;

}
