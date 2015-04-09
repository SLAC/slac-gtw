<?php
/**
 * @file
 * slac_igp_config.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function slac_igp_config_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front_page';
  $page->task = 'page';
  $page->admin_title = 'Front Page';
  $page->admin_description = '';
  $page->path = 'front';
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
  $handler->name = 'page_front_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'front_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Home Page',
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
  $display->layout = 'frontpage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'colonerowone' => NULL,
      'colonerowtwo' => NULL,
      'colonerowthree' => NULL,
      'coltworowone' => NULL,
      'coltworowtwo' => NULL,
      'coltworowthree' => NULL,
      'coltworowfour' => NULL,
      'colthreerowone' => NULL,
      'colthreerowtwo' => NULL,
      'colthreerowthree' => NULL,
      'colthreerowfour' => NULL,
      'colthreerowfive' => NULL,
      'colthreerowsix' => NULL,
      'coltworowfive' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a6785b3e-ac44-4265-821d-0306402b8c0d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-61eb4510-1f55-41ee-bdb5-09cfa5c07679';
    $pane->panel = 'colonerowone';
    $pane->type = 'block';
    $pane->subtype = 'views-news-block';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '61eb4510-1f55-41ee-bdb5-09cfa5c07679';
    $display->content['new-61eb4510-1f55-41ee-bdb5-09cfa5c07679'] = $pane;
    $display->panels['colonerowone'][0] = 'new-61eb4510-1f55-41ee-bdb5-09cfa5c07679';
    $pane = new stdClass();
    $pane->pid = 'new-f2351ada-fcca-4e09-b9c7-c3060e9650c3';
    $pane->panel = 'colonerowthree';
    $pane->type = 'block';
    $pane->subtype = 'views-news-block_3';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'blue-bodered-white no-bg',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f2351ada-fcca-4e09-b9c7-c3060e9650c3';
    $display->content['new-f2351ada-fcca-4e09-b9c7-c3060e9650c3'] = $pane;
    $display->panels['colonerowthree'][0] = 'new-f2351ada-fcca-4e09-b9c7-c3060e9650c3';
    $pane = new stdClass();
    $pane->pid = 'new-37ad32d3-085c-43b0-9fe4-e65a379b4370';
    $pane->panel = 'colonerowtwo';
    $pane->type = 'views';
    $pane->subtype = 'slac_news';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
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
    $pane->uuid = '37ad32d3-085c-43b0-9fe4-e65a379b4370';
    $display->content['new-37ad32d3-085c-43b0-9fe4-e65a379b4370'] = $pane;
    $display->panels['colonerowtwo'][0] = 'new-37ad32d3-085c-43b0-9fe4-e65a379b4370';
    $pane = new stdClass();
    $pane->pid = 'new-25830832-5472-4916-a0a3-81843df40ed9';
    $pane->panel = 'colonerowtwo';
    $pane->type = 'views';
    $pane->subtype = 'news';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '8',
      'pager_id' => '0',
      'offset' => '',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 1,
      'override_title_text' => '<a href="https://news.slac.stanford.edu/tags/staff-benefits-resources/lab-news">LAB NEWS</a>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'blue-bodered-white no-bg',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '25830832-5472-4916-a0a3-81843df40ed9';
    $display->content['new-25830832-5472-4916-a0a3-81843df40ed9'] = $pane;
    $display->panels['colonerowtwo'][1] = 'new-25830832-5472-4916-a0a3-81843df40ed9';
    $pane = new stdClass();
    $pane->pid = 'new-ec1dc49a-827e-4685-821b-c6e760af2ca9';
    $pane->panel = 'colthreerowfive';
    $pane->type = 'block';
    $pane->subtype = 'boxes-it_help_desk';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ec1dc49a-827e-4685-821b-c6e760af2ca9';
    $display->content['new-ec1dc49a-827e-4685-821b-c6e760af2ca9'] = $pane;
    $display->panels['colthreerowfive'][0] = 'new-ec1dc49a-827e-4685-821b-c6e760af2ca9';
    $pane = new stdClass();
    $pane->pid = 'new-9c49d626-a6ea-4be3-8b60-a610bf499c72';
    $pane->panel = 'colthreerowfive';
    $pane->type = 'block';
    $pane->subtype = 'views-flea_market-block';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9c49d626-a6ea-4be3-8b60-a610bf499c72';
    $display->content['new-9c49d626-a6ea-4be3-8b60-a610bf499c72'] = $pane;
    $display->panels['colthreerowfive'][1] = 'new-9c49d626-a6ea-4be3-8b60-a610bf499c72';
    $pane = new stdClass();
    $pane->pid = 'new-4125565c-b09f-46bd-b838-79903549f878';
    $pane->panel = 'colthreerowfour';
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
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => 'Organization Index',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4125565c-b09f-46bd-b838-79903549f878';
    $display->content['new-4125565c-b09f-46bd-b838-79903549f878'] = $pane;
    $display->panels['colthreerowfour'][0] = 'new-4125565c-b09f-46bd-b838-79903549f878';
    $pane = new stdClass();
    $pane->pid = 'new-c0a99c52-d91c-4daf-9852-c1e905e113ff';
    $pane->panel = 'colthreerowone';
    $pane->type = 'block';
    $pane->subtype = 'boxes-search_people';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white no-bg',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c0a99c52-d91c-4daf-9852-c1e905e113ff';
    $display->content['new-c0a99c52-d91c-4daf-9852-c1e905e113ff'] = $pane;
    $display->panels['colthreerowone'][0] = 'new-c0a99c52-d91c-4daf-9852-c1e905e113ff';
    $pane = new stdClass();
    $pane->pid = 'new-4ab9910a-8622-4702-a755-b8026a1a09c6';
    $pane->panel = 'colthreerowsix';
    $pane->type = 'block';
    $pane->subtype = 'boxes-site_security';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4ab9910a-8622-4702-a755-b8026a1a09c6';
    $display->content['new-4ab9910a-8622-4702-a755-b8026a1a09c6'] = $pane;
    $display->panels['colthreerowsix'][0] = 'new-4ab9910a-8622-4702-a755-b8026a1a09c6';
    $pane = new stdClass();
    $pane->pid = 'new-0f83568f-2f80-4619-94f4-00493a7ca0f6';
    $pane->panel = 'colthreerowsix';
    $pane->type = 'block';
    $pane->subtype = 'boxes-stanford_compliance';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0f83568f-2f80-4619-94f4-00493a7ca0f6';
    $display->content['new-0f83568f-2f80-4619-94f4-00493a7ca0f6'] = $pane;
    $display->panels['colthreerowsix'][1] = 'new-0f83568f-2f80-4619-94f4-00493a7ca0f6';
    $pane = new stdClass();
    $pane->pid = 'new-9672c131-3e48-4e4f-9e94-af57b159ff3b';
    $pane->panel = 'colthreerowsix';
    $pane->type = 'block';
    $pane->subtype = 'boxes-connect';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '9672c131-3e48-4e4f-9e94-af57b159ff3b';
    $display->content['new-9672c131-3e48-4e4f-9e94-af57b159ff3b'] = $pane;
    $display->panels['colthreerowsix'][2] = 'new-9672c131-3e48-4e4f-9e94-af57b159ff3b';
    $pane = new stdClass();
    $pane->pid = 'new-c0566837-ec4a-41dd-afae-060a6b4a249d';
    $pane->panel = 'colthreerowthree';
    $pane->type = 'block';
    $pane->subtype = 'boxes-slac_projects';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c0566837-ec4a-41dd-afae-060a6b4a249d';
    $display->content['new-c0566837-ec4a-41dd-afae-060a6b4a249d'] = $pane;
    $display->panels['colthreerowthree'][0] = 'new-c0566837-ec4a-41dd-afae-060a6b4a249d';
    $pane = new stdClass();
    $pane->pid = 'new-4481ec24-da24-47c6-8392-18c14b77f12f';
    $pane->panel = 'colthreerowtwo';
    $pane->type = 'views';
    $pane->subtype = 'staff_resource_modern';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '18',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_2',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white desktop',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4481ec24-da24-47c6-8392-18c14b77f12f';
    $display->content['new-4481ec24-da24-47c6-8392-18c14b77f12f'] = $pane;
    $display->panels['colthreerowtwo'][0] = 'new-4481ec24-da24-47c6-8392-18c14b77f12f';
    $pane = new stdClass();
    $pane->pid = 'new-c5c9d0dc-e5bc-4dd3-967e-5ac45635e581';
    $pane->panel = 'colthreerowtwo';
    $pane->type = 'views';
    $pane->subtype = 'staff_resource_modern';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '18',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_3',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white blue-striped-list mobile',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c5c9d0dc-e5bc-4dd3-967e-5ac45635e581';
    $display->content['new-c5c9d0dc-e5bc-4dd3-967e-5ac45635e581'] = $pane;
    $display->panels['colthreerowtwo'][1] = 'new-c5c9d0dc-e5bc-4dd3-967e-5ac45635e581';
    $pane = new stdClass();
    $pane->pid = 'new-8c0b190a-16e6-4bd0-ac35-ee47b18a5c24';
    $pane->panel = 'colthreerowtwo';
    $pane->type = 'views';
    $pane->subtype = 'top_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '',
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
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white desktop',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8c0b190a-16e6-4bd0-ac35-ee47b18a5c24';
    $display->content['new-8c0b190a-16e6-4bd0-ac35-ee47b18a5c24'] = $pane;
    $display->panels['colthreerowtwo'][2] = 'new-8c0b190a-16e6-4bd0-ac35-ee47b18a5c24';
    $pane = new stdClass();
    $pane->pid = 'new-0c2839e1-4c81-4f99-a2e1-c5fcad80f627';
    $pane->panel = 'coltworowfive';
    $pane->type = 'block';
    $pane->subtype = 'weather_block-weather_block';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0c2839e1-4c81-4f99-a2e1-c5fcad80f627';
    $display->content['new-0c2839e1-4c81-4f99-a2e1-c5fcad80f627'] = $pane;
    $display->panels['coltworowfive'][0] = 'new-0c2839e1-4c81-4f99-a2e1-c5fcad80f627';
    $pane = new stdClass();
    $pane->pid = 'new-b3a7a5ca-2d77-4982-bd20-2b73650db455';
    $pane->panel = 'coltworowfour';
    $pane->type = 'block';
    $pane->subtype = 'views-access_information-block';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b3a7a5ca-2d77-4982-bd20-2b73650db455';
    $display->content['new-b3a7a5ca-2d77-4982-bd20-2b73650db455'] = $pane;
    $display->panels['coltworowfour'][0] = 'new-b3a7a5ca-2d77-4982-bd20-2b73650db455';
    $pane = new stdClass();
    $pane->pid = 'new-1ed069f0-d205-44aa-ba40-67d3462f8a2c';
    $pane->panel = 'coltworowone';
    $pane->type = 'views';
    $pane->subtype = 'news';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '3',
      'pager_id' => '0',
      'offset' => '',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_4',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1ed069f0-d205-44aa-ba40-67d3462f8a2c';
    $display->content['new-1ed069f0-d205-44aa-ba40-67d3462f8a2c'] = $pane;
    $display->panels['coltworowone'][0] = 'new-1ed069f0-d205-44aa-ba40-67d3462f8a2c';
    $pane = new stdClass();
    $pane->pid = 'new-3a98c25b-f230-4840-ae8a-d14df30a9fa5';
    $pane->panel = 'coltworowthree';
    $pane->type = 'block';
    $pane->subtype = 'views-calendar-block';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'brown-bodered-white',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3a98c25b-f230-4840-ae8a-d14df30a9fa5';
    $display->content['new-3a98c25b-f230-4840-ae8a-d14df30a9fa5'] = $pane;
    $display->panels['coltworowthree'][0] = 'new-3a98c25b-f230-4840-ae8a-d14df30a9fa5';
    $pane = new stdClass();
    $pane->pid = 'new-76508b3a-8a77-44dc-992b-e22b78e5d9bf';
    $pane->panel = 'coltworowtwo';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-sidebar-menu';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '76508b3a-8a77-44dc-992b-e22b78e5d9bf';
    $display->content['new-76508b3a-8a77-44dc-992b-e22b78e5d9bf'] = $pane;
    $display->panels['coltworowtwo'][0] = 'new-76508b3a-8a77-44dc-992b-e22b78e5d9bf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page'] = $page;

  return $pages;

}
