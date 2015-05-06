<?php
/**
 * @file
 * pm_calendar.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function pm_calendar_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'calendar';
  $page->task = 'page';
  $page->admin_title = 'Calendar';
  $page->admin_description = '';
  $page->path = 'calendar';
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
  $handler->name = 'page_calendar__panel_context_adef7f7d-560e-4ad4-ba48-206ef4474ece';
  $handler->task = 'page';
  $handler->subtask = 'calendar';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Month View',
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
            'paths' => 'calendar',
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
      'main_content_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Calendar';
  $display->uuid = 'c4ce7776-1775-4514-bdb5-d86a55721356';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-570538b7-1b27-467c-a124-f9bfd05f2a43';
    $pane->panel = 'main_content_column';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Calendar Nav - Month',
      'title' => '<none>',
      'body' => '<ul>
<li class="day"><a href="/calendar/day">Day</a></li>
<li class="week"><a href="/calendar/week">Week</a></li>
<li class="month active"><a href="/calendar">Month</a></li>
</ul>',
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
    $pane->uuid = '570538b7-1b27-467c-a124-f9bfd05f2a43';
    $display->content['new-570538b7-1b27-467c-a124-f9bfd05f2a43'] = $pane;
    $display->panels['main_content_column'][0] = 'new-570538b7-1b27-467c-a124-f9bfd05f2a43';
    $pane = new stdClass();
    $pane->pid = 'new-45a5bc1e-c379-499f-8c13-e087f2f086d2';
    $pane->panel = 'main_content_column';
    $pane->type = 'views';
    $pane->subtype = 'calendar_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page_1',
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
    $pane->uuid = '45a5bc1e-c379-499f-8c13-e087f2f086d2';
    $display->content['new-45a5bc1e-c379-499f-8c13-e087f2f086d2'] = $pane;
    $display->panels['main_content_column'][1] = 'new-45a5bc1e-c379-499f-8c13-e087f2f086d2';
    $pane = new stdClass();
    $pane->pid = 'new-6473bdce-3317-4b34-85de-e9461b692cb5';
    $pane->panel = 'main_content_column';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'full_html',
      'substitute' => TRUE,
      'name' => 'calendar_event_type_legend',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6473bdce-3317-4b34-85de-e9461b692cb5';
    $display->content['new-6473bdce-3317-4b34-85de-e9461b692cb5'] = $pane;
    $display->panels['main_content_column'][2] = 'new-6473bdce-3317-4b34-85de-e9461b692cb5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-45a5bc1e-c379-499f-8c13-e087f2f086d2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_calendar__panel_context_53f43e95-3e9a-4001-9891-31e43e443505';
  $handler->task = 'page';
  $handler->subtask = 'calendar';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Week View',
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
            'paths' => 'calendar/week',
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
      'main_content_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Calendar';
  $display->uuid = 'c4ce7776-1775-4514-bdb5-d86a55721356';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2ace3dd9-039e-44bf-b30e-8162164bdd28';
    $pane->panel = 'main_content_column';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Calendar Nav - Week',
      'title' => '<none>',
      'body' => '<ul>
<li class="day"><a href="/calendar/day">Day</a></li>
<li class="week active"><a href="/calendar/week">Week</a></li>
<li class="month"><a href="/calendar">Month</a></li>
</ul>',
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
    $pane->uuid = '2ace3dd9-039e-44bf-b30e-8162164bdd28';
    $display->content['new-2ace3dd9-039e-44bf-b30e-8162164bdd28'] = $pane;
    $display->panels['main_content_column'][0] = 'new-2ace3dd9-039e-44bf-b30e-8162164bdd28';
    $pane = new stdClass();
    $pane->pid = 'new-9d5c42ca-282d-4ea6-901c-e4ffa199aed9';
    $pane->panel = 'main_content_column';
    $pane->type = 'views';
    $pane->subtype = 'calendar_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page_2',
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
    $pane->uuid = '9d5c42ca-282d-4ea6-901c-e4ffa199aed9';
    $display->content['new-9d5c42ca-282d-4ea6-901c-e4ffa199aed9'] = $pane;
    $display->panels['main_content_column'][1] = 'new-9d5c42ca-282d-4ea6-901c-e4ffa199aed9';
    $pane = new stdClass();
    $pane->pid = 'new-e4d00f19-2889-45ba-a561-5492b53944b6';
    $pane->panel = 'main_content_column';
    $pane->type = 'custom';
    $pane->subtype = 'calendar_event_type_legend';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e4d00f19-2889-45ba-a561-5492b53944b6';
    $display->content['new-e4d00f19-2889-45ba-a561-5492b53944b6'] = $pane;
    $display->panels['main_content_column'][2] = 'new-e4d00f19-2889-45ba-a561-5492b53944b6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_calendar__panel_context_2ed2df70-9ef0-48de-bea6-c9c2375f19e0';
  $handler->task = 'page';
  $handler->subtask = 'calendar';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Day View',
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
            'paths' => 'calendar/day',
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
      'main_content_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Calendar';
  $display->uuid = 'c4ce7776-1775-4514-bdb5-d86a55721356';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f1cc4734-acfa-43f0-94af-0ab013b59496';
    $pane->panel = 'main_content_column';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Calendar Nav - Day',
      'title' => '<none>',
      'body' => '<ul>
<li class="day active"><a href="/calendar/day">Day</a></li>
<li class="week"><a href="/calendar/week">Week</a></li>
<li class="month"><a href="/calendar">Month</a></li>
</ul>',
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
    $pane->uuid = 'f1cc4734-acfa-43f0-94af-0ab013b59496';
    $display->content['new-f1cc4734-acfa-43f0-94af-0ab013b59496'] = $pane;
    $display->panels['main_content_column'][0] = 'new-f1cc4734-acfa-43f0-94af-0ab013b59496';
    $pane = new stdClass();
    $pane->pid = 'new-1eb7c454-696c-463c-ae5f-99db46f5f796';
    $pane->panel = 'main_content_column';
    $pane->type = 'views';
    $pane->subtype = 'calendar_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page_3',
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
    $pane->uuid = '1eb7c454-696c-463c-ae5f-99db46f5f796';
    $display->content['new-1eb7c454-696c-463c-ae5f-99db46f5f796'] = $pane;
    $display->panels['main_content_column'][1] = 'new-1eb7c454-696c-463c-ae5f-99db46f5f796';
    $pane = new stdClass();
    $pane->pid = 'new-2869b83c-a0b4-4641-8f29-433106925054';
    $pane->panel = 'main_content_column';
    $pane->type = 'custom';
    $pane->subtype = 'calendar_event_type_legend';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2869b83c-a0b4-4641-8f29-433106925054';
    $display->content['new-2869b83c-a0b4-4641-8f29-433106925054'] = $pane;
    $display->panels['main_content_column'][2] = 'new-2869b83c-a0b4-4641-8f29-433106925054';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['calendar'] = $page;

  return $pages;

}
