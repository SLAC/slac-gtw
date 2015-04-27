<?php
/**
 * @file
 * pm_flea_market.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function pm_flea_market_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'flea_market';
  $page->task = 'page';
  $page->admin_title = 'Flea Market';
  $page->admin_description = '';
  $page->path = 'flea-market';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_flea_market__panel_context_ce8be9f4-d138-465a-97e3-8b1331ba2ebe';
  $handler->task = 'page';
  $handler->subtask = 'flea_market';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Flea Market Listing',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'flea-market',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'one-col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'center' => NULL,
      'main_content_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Flea Market';
  $display->uuid = '10cc569a-39b8-4ddb-9c82-65476b2563de';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3958e3f2-ac0a-40df-adc1-ec477355cb51';
    $pane->panel = 'main_content_column';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<ul><li><a href="/flea-market/my-items">My Flea Market Items &gt;</a></li><li><a href="/node/add/flea-market-post">Submit Flea Market Ad &gt;</a></li></ul>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'flea_market_nav',
      'css_class' => 'my-flea-market-nav',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3958e3f2-ac0a-40df-adc1-ec477355cb51';
    $display->content['new-3958e3f2-ac0a-40df-adc1-ec477355cb51'] = $pane;
    $display->panels['main_content_column'][0] = 'new-3958e3f2-ac0a-40df-adc1-ec477355cb51';
    $pane = new stdClass();
    $pane->pid = 'new-38783314-328b-494f-9fab-18a60b3b0acb';
    $pane->panel = 'main_content_column';
    $pane->type = 'views_panes';
    $pane->subtype = 'flea_market_listing-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '38783314-328b-494f-9fab-18a60b3b0acb';
    $display->content['new-38783314-328b-494f-9fab-18a60b3b0acb'] = $pane;
    $display->panels['main_content_column'][1] = 'new-38783314-328b-494f-9fab-18a60b3b0acb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-38783314-328b-494f-9fab-18a60b3b0acb';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_flea_market__panel_context_3212e455-0fc3-465f-9767-2428196bda9c';
  $handler->task = 'page';
  $handler->subtask = 'flea_market';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'My Flea Market Items',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'flea-market/my-items',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'one-col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'center' => NULL,
      'main_content_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'My Flea Market Items';
  $display->uuid = '10cc569a-39b8-4ddb-9c82-65476b2563de';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3958e3f2-ac0a-40df-adc1-ec477355cb51';
    $pane->panel = 'main_content_column';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<ul><li><a href="/flea-market">Flea Market Listings &gt;</a></li><li><a href="/node/add/flea-market-post">Submit Flea Market Ad &gt;</a></li></ul>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'flea_market_nav',
      'css_class' => 'my-flea-market-nav',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3958e3f2-ac0a-40df-adc1-ec477355cb51';
    $display->content['new-3958e3f2-ac0a-40df-adc1-ec477355cb51'] = $pane;
    $display->panels['main_content_column'][0] = 'new-3958e3f2-ac0a-40df-adc1-ec477355cb51';
    $pane = new stdClass();
    $pane->pid = 'new-c1f29952-ce7a-405e-a9ef-9bfe76a86306';
    $pane->panel = 'main_content_column';
    $pane->type = 'views_panes';
    $pane->subtype = 'flea_market_listing-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c1f29952-ce7a-405e-a9ef-9bfe76a86306';
    $display->content['new-c1f29952-ce7a-405e-a9ef-9bfe76a86306'] = $pane;
    $display->panels['main_content_column'][1] = 'new-c1f29952-ce7a-405e-a9ef-9bfe76a86306';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['flea_market'] = $page;

  return $pages;

}
