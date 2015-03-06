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
  $display->uuid = 'a0d1d00f-86e3-42b5-9210-f2103f84856e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-59f29575-b7c7-46a5-840b-870d7a84a410';
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
    $pane->uuid = '59f29575-b7c7-46a5-840b-870d7a84a410';
    $display->content['new-59f29575-b7c7-46a5-840b-870d7a84a410'] = $pane;
    $display->panels['colonerowone'][0] = 'new-59f29575-b7c7-46a5-840b-870d7a84a410';
    $pane = new stdClass();
    $pane->pid = 'new-aa7c43d3-e0fe-46e4-aac0-576ac3a91ca8';
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
    $pane->uuid = 'aa7c43d3-e0fe-46e4-aac0-576ac3a91ca8';
    $display->content['new-aa7c43d3-e0fe-46e4-aac0-576ac3a91ca8'] = $pane;
    $display->panels['colonerowthree'][0] = 'new-aa7c43d3-e0fe-46e4-aac0-576ac3a91ca8';
    $pane = new stdClass();
    $pane->pid = 'new-ca5051b4-93d8-483a-bc0a-4f108ccc1239';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ca5051b4-93d8-483a-bc0a-4f108ccc1239';
    $display->content['new-ca5051b4-93d8-483a-bc0a-4f108ccc1239'] = $pane;
    $display->panels['colonerowtwo'][0] = 'new-ca5051b4-93d8-483a-bc0a-4f108ccc1239';
    $pane = new stdClass();
    $pane->pid = 'new-4a1d1966-4897-42c6-a8c7-dcf332ea0d3f';
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
    $pane->uuid = '4a1d1966-4897-42c6-a8c7-dcf332ea0d3f';
    $display->content['new-4a1d1966-4897-42c6-a8c7-dcf332ea0d3f'] = $pane;
    $display->panels['colthreerowfive'][0] = 'new-4a1d1966-4897-42c6-a8c7-dcf332ea0d3f';
    $pane = new stdClass();
    $pane->pid = 'new-4567a7d7-4124-4196-a3e7-8999437d93bf';
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
    $pane->uuid = '4567a7d7-4124-4196-a3e7-8999437d93bf';
    $display->content['new-4567a7d7-4124-4196-a3e7-8999437d93bf'] = $pane;
    $display->panels['colthreerowfive'][1] = 'new-4567a7d7-4124-4196-a3e7-8999437d93bf';
    $pane = new stdClass();
    $pane->pid = 'new-0951a45e-b34e-4054-be6d-bb4f4e92f897';
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
    $pane->uuid = '0951a45e-b34e-4054-be6d-bb4f4e92f897';
    $display->content['new-0951a45e-b34e-4054-be6d-bb4f4e92f897'] = $pane;
    $display->panels['colthreerowfour'][0] = 'new-0951a45e-b34e-4054-be6d-bb4f4e92f897';
    $pane = new stdClass();
    $pane->pid = 'new-2b0057bc-abea-4923-bae2-bf1a3ae3474f';
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
    $pane->uuid = '2b0057bc-abea-4923-bae2-bf1a3ae3474f';
    $display->content['new-2b0057bc-abea-4923-bae2-bf1a3ae3474f'] = $pane;
    $display->panels['colthreerowone'][0] = 'new-2b0057bc-abea-4923-bae2-bf1a3ae3474f';
    $pane = new stdClass();
    $pane->pid = 'new-e6471447-7293-4580-bdb5-b3c83906463e';
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
    $pane->uuid = 'e6471447-7293-4580-bdb5-b3c83906463e';
    $display->content['new-e6471447-7293-4580-bdb5-b3c83906463e'] = $pane;
    $display->panels['colthreerowsix'][0] = 'new-e6471447-7293-4580-bdb5-b3c83906463e';
    $pane = new stdClass();
    $pane->pid = 'new-69194fb6-bcbd-4ba8-9f53-83a144346807';
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
    $pane->uuid = '69194fb6-bcbd-4ba8-9f53-83a144346807';
    $display->content['new-69194fb6-bcbd-4ba8-9f53-83a144346807'] = $pane;
    $display->panels['colthreerowsix'][1] = 'new-69194fb6-bcbd-4ba8-9f53-83a144346807';
    $pane = new stdClass();
    $pane->pid = 'new-5991d64b-2cc3-46ef-9dd1-d3450dd2ace7';
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
    $pane->uuid = '5991d64b-2cc3-46ef-9dd1-d3450dd2ace7';
    $display->content['new-5991d64b-2cc3-46ef-9dd1-d3450dd2ace7'] = $pane;
    $display->panels['colthreerowsix'][2] = 'new-5991d64b-2cc3-46ef-9dd1-d3450dd2ace7';
    $pane = new stdClass();
    $pane->pid = 'new-10c5cc34-3207-4ddd-98ca-908c1d62cc27';
    $pane->panel = 'colthreerowsix';
    $pane->type = 'block';
    $pane->subtype = 'boxes-feedback';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '10c5cc34-3207-4ddd-98ca-908c1d62cc27';
    $display->content['new-10c5cc34-3207-4ddd-98ca-908c1d62cc27'] = $pane;
    $display->panels['colthreerowsix'][3] = 'new-10c5cc34-3207-4ddd-98ca-908c1d62cc27';
    $pane = new stdClass();
    $pane->pid = 'new-91c3518b-be34-493e-8b54-ed64f1d39e1a';
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
    $pane->uuid = '91c3518b-be34-493e-8b54-ed64f1d39e1a';
    $display->content['new-91c3518b-be34-493e-8b54-ed64f1d39e1a'] = $pane;
    $display->panels['colthreerowthree'][0] = 'new-91c3518b-be34-493e-8b54-ed64f1d39e1a';
    $pane = new stdClass();
    $pane->pid = 'new-5abda237-017d-4978-b506-84a3bb8dd80c';
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
    $pane->uuid = '5abda237-017d-4978-b506-84a3bb8dd80c';
    $display->content['new-5abda237-017d-4978-b506-84a3bb8dd80c'] = $pane;
    $display->panels['colthreerowtwo'][0] = 'new-5abda237-017d-4978-b506-84a3bb8dd80c';
    $pane = new stdClass();
    $pane->pid = 'new-9e8e4eb2-e963-49c8-9a11-ee6b20997789';
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
    $pane->uuid = '9e8e4eb2-e963-49c8-9a11-ee6b20997789';
    $display->content['new-9e8e4eb2-e963-49c8-9a11-ee6b20997789'] = $pane;
    $display->panels['colthreerowtwo'][1] = 'new-9e8e4eb2-e963-49c8-9a11-ee6b20997789';
    $pane = new stdClass();
    $pane->pid = 'new-ad707df0-eba1-4a6d-bd64-71eb25dc2581';
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
    $pane->uuid = 'ad707df0-eba1-4a6d-bd64-71eb25dc2581';
    $display->content['new-ad707df0-eba1-4a6d-bd64-71eb25dc2581'] = $pane;
    $display->panels['colthreerowtwo'][2] = 'new-ad707df0-eba1-4a6d-bd64-71eb25dc2581';
    $pane = new stdClass();
    $pane->pid = 'new-8dd1f84b-bb8d-4b27-91ea-0c49294857da';
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
    $pane->uuid = '8dd1f84b-bb8d-4b27-91ea-0c49294857da';
    $display->content['new-8dd1f84b-bb8d-4b27-91ea-0c49294857da'] = $pane;
    $display->panels['coltworowfive'][0] = 'new-8dd1f84b-bb8d-4b27-91ea-0c49294857da';
    $pane = new stdClass();
    $pane->pid = 'new-9f4acb14-9b15-40af-b011-518576675aa0';
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
    $pane->uuid = '9f4acb14-9b15-40af-b011-518576675aa0';
    $display->content['new-9f4acb14-9b15-40af-b011-518576675aa0'] = $pane;
    $display->panels['coltworowfour'][0] = 'new-9f4acb14-9b15-40af-b011-518576675aa0';
    $pane = new stdClass();
    $pane->pid = 'new-1e62e6ec-396d-4c37-8c27-e0ed75a4b4ab';
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
    $pane->uuid = '1e62e6ec-396d-4c37-8c27-e0ed75a4b4ab';
    $display->content['new-1e62e6ec-396d-4c37-8c27-e0ed75a4b4ab'] = $pane;
    $display->panels['coltworowone'][0] = 'new-1e62e6ec-396d-4c37-8c27-e0ed75a4b4ab';
    $pane = new stdClass();
    $pane->pid = 'new-0c2a5672-83f1-400e-87dd-69c70bed7101';
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
    $pane->uuid = '0c2a5672-83f1-400e-87dd-69c70bed7101';
    $display->content['new-0c2a5672-83f1-400e-87dd-69c70bed7101'] = $pane;
    $display->panels['coltworowthree'][0] = 'new-0c2a5672-83f1-400e-87dd-69c70bed7101';
    $pane = new stdClass();
    $pane->pid = 'new-69abf251-2689-435e-b7f5-abed75d32e39';
    $pane->panel = 'coltworowtwo';
    $pane->type = 'block';
    $pane->subtype = 'system-main-menu';
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
      'css_class' => 'brown-bodered-white blue-dashed-list',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '69abf251-2689-435e-b7f5-abed75d32e39';
    $display->content['new-69abf251-2689-435e-b7f5-abed75d32e39'] = $pane;
    $display->panels['coltworowtwo'][0] = 'new-69abf251-2689-435e-b7f5-abed75d32e39';
    $pane = new stdClass();
    $pane->pid = 'new-8965242b-de7d-49a5-bbe9-e1b4453d1984';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8965242b-de7d-49a5-bbe9-e1b4453d1984';
    $display->content['new-8965242b-de7d-49a5-bbe9-e1b4453d1984'] = $pane;
    $display->panels['coltworowtwo'][1] = 'new-8965242b-de7d-49a5-bbe9-e1b4453d1984';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page'] = $page;

  return $pages;

}
