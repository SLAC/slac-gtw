<?php
/**
 * @file
 * ct_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ct_news_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__news';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'News',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'news',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'news' => 'news',
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
  $display->title = '';
  $display->uuid = '9c9fe7b6-dcc1-4716-aeb3-f627569f1c12';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ed2a18ab-82c0-4867-b963-9c2460271a79';
    $pane->panel = 'left';
    $pane->type = 'slac_ip_panes_print';
    $pane->subtype = 'slac_ip_panes_print';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ed2a18ab-82c0-4867-b963-9c2460271a79';
    $display->content['new-ed2a18ab-82c0-4867-b963-9c2460271a79'] = $pane;
    $display->panels['left'][0] = 'new-ed2a18ab-82c0-4867-b963-9c2460271a79';
    $pane = new stdClass();
    $pane->pid = 'new-d6fe9503-e787-446e-923a-af85c3d24907';
    $pane->panel = 'left';
    $pane->type = 'slac_ip_panes_email';
    $pane->subtype = 'slac_ip_panes_email';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd6fe9503-e787-446e-923a-af85c3d24907';
    $display->content['new-d6fe9503-e787-446e-923a-af85c3d24907'] = $pane;
    $display->panels['left'][1] = 'new-d6fe9503-e787-446e-923a-af85c3d24907';
    $pane = new stdClass();
    $pane->pid = 'new-2e04dac4-f6ab-4e96-9327-8c25182da465';
    $pane->panel = 'left';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '2e04dac4-f6ab-4e96-9327-8c25182da465';
    $display->content['new-2e04dac4-f6ab-4e96-9327-8c25182da465'] = $pane;
    $display->panels['left'][2] = 'new-2e04dac4-f6ab-4e96-9327-8c25182da465';
    $pane = new stdClass();
    $pane->pid = 'new-001bc4d8-60c6-4d08-a64b-2ef32050479b';
    $pane->panel = 'left';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'long',
      'context' => 'argument_entity_id:node_1',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '001bc4d8-60c6-4d08-a64b-2ef32050479b';
    $display->content['new-001bc4d8-60c6-4d08-a64b-2ef32050479b'] = $pane;
    $display->panels['left'][3] = 'new-001bc4d8-60c6-4d08-a64b-2ef32050479b';
    $pane = new stdClass();
    $pane->pid = 'new-b8964404-09b3-4389-81d1-efb220c686f5';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_byline';
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
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'b8964404-09b3-4389-81d1-efb220c686f5';
    $display->content['new-b8964404-09b3-4389-81d1-efb220c686f5'] = $pane;
    $display->panels['left'][4] = 'new-b8964404-09b3-4389-81d1-efb220c686f5';
    $pane = new stdClass();
    $pane->pid = 'new-0d6e1559-2d27-4533-b524-dd5fc730bbe9';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_location';
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
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '0d6e1559-2d27-4533-b524-dd5fc730bbe9';
    $display->content['new-0d6e1559-2d27-4533-b524-dd5fc730bbe9'] = $pane;
    $display->panels['left'][5] = 'new-0d6e1559-2d27-4533-b524-dd5fc730bbe9';
    $pane = new stdClass();
    $pane->pid = 'new-7697f898-c9e8-4544-bed0-22971ebb7e9a';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_news_subtitle';
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
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '7697f898-c9e8-4544-bed0-22971ebb7e9a';
    $display->content['new-7697f898-c9e8-4544-bed0-22971ebb7e9a'] = $pane;
    $display->panels['left'][6] = 'new-7697f898-c9e8-4544-bed0-22971ebb7e9a';
    $pane = new stdClass();
    $pane->pid = 'new-9b012b29-ae44-492f-b39f-72c1d67a3e44';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'file_rendered',
      'delta_limit' => '1',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'image_style' => 'featured_news',
        'image_link' => '',
        'file_view_mode' => 'default',
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
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '9b012b29-ae44-492f-b39f-72c1d67a3e44';
    $display->content['new-9b012b29-ae44-492f-b39f-72c1d67a3e44'] = $pane;
    $display->panels['left'][7] = 'new-9b012b29-ae44-492f-b39f-72c1d67a3e44';
    $pane = new stdClass();
    $pane->pid = 'new-1860c7cb-7965-4d5a-be2c-422d9bd2abea';
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
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '1860c7cb-7965-4d5a-be2c-422d9bd2abea';
    $display->content['new-1860c7cb-7965-4d5a-be2c-422d9bd2abea'] = $pane;
    $display->panels['left'][8] = 'new-1860c7cb-7965-4d5a-be2c-422d9bd2abea';
    $pane = new stdClass();
    $pane->pid = 'new-1995afda-eccf-45aa-bb6f-f7ea133ee64e';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_contact_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Contact',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = '1995afda-eccf-45aa-bb6f-f7ea133ee64e';
    $display->content['new-1995afda-eccf-45aa-bb6f-f7ea133ee64e'] = $pane;
    $display->panels['left'][9] = 'new-1995afda-eccf-45aa-bb6f-f7ea133ee64e';
    $pane = new stdClass();
    $pane->pid = 'new-5f30f224-665e-4f22-ba93-e78e8a4f4642';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_contact_email';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'email_default',
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
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = '5f30f224-665e-4f22-ba93-e78e8a4f4642';
    $display->content['new-5f30f224-665e-4f22-ba93-e78e8a4f4642'] = $pane;
    $display->panels['left'][10] = 'new-5f30f224-665e-4f22-ba93-e78e8a4f4642';
    $pane = new stdClass();
    $pane->pid = 'new-c3c088c6-a407-4f75-be64-d7ae1967c43e';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_contact_phone';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'telephone_link',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'title' => '',
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
    $pane->position = 11;
    $pane->locks = array();
    $pane->uuid = 'c3c088c6-a407-4f75-be64-d7ae1967c43e';
    $display->content['new-c3c088c6-a407-4f75-be64-d7ae1967c43e'] = $pane;
    $display->panels['left'][11] = 'new-c3c088c6-a407-4f75-be64-d7ae1967c43e';
    $pane = new stdClass();
    $pane->pid = 'new-da320e38-af4d-4836-adc7-f8ee5d94c8c1';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
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
    $pane->position = 12;
    $pane->locks = array();
    $pane->uuid = 'da320e38-af4d-4836-adc7-f8ee5d94c8c1';
    $display->content['new-da320e38-af4d-4836-adc7-f8ee5d94c8c1'] = $pane;
    $display->panels['left'][12] = 'new-da320e38-af4d-4836-adc7-f8ee5d94c8c1';
    $pane = new stdClass();
    $pane->pid = 'new-50321a9c-df30-4e63-b49d-9ff062f162d7';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'file_rendered',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'image_style' => 'featured_news',
        'image_link' => '',
        'file_view_mode' => 'teaser',
      ),
      'context' => 'argument_entity_id:node_1',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '50321a9c-df30-4e63-b49d-9ff062f162d7';
    $display->content['new-50321a9c-df30-4e63-b49d-9ff062f162d7'] = $pane;
    $display->panels['right'][0] = 'new-50321a9c-df30-4e63-b49d-9ff062f162d7';
    $pane = new stdClass();
    $pane->pid = 'new-569d9684-0fd1-4823-be3b-d5274da1f3a1';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shared_video';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'file_rendered',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'controls' => 1,
        'autoplay' => 0,
        'loop' => 0,
        'multiple_file_behavior' => 'tags',
        'width' => '',
        'height' => '',
        'file_view_mode' => 'default',
      ),
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '569d9684-0fd1-4823-be3b-d5274da1f3a1';
    $display->content['new-569d9684-0fd1-4823-be3b-d5274da1f3a1'] = $pane;
    $display->panels['right'][1] = 'new-569d9684-0fd1-4823-be3b-d5274da1f3a1';
    $pane = new stdClass();
    $pane->pid = 'new-786520ba-25b9-4742-b1ec-a0f098063787';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'featured_news-featured_news_panel_pane';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '786520ba-25b9-4742-b1ec-a0f098063787';
    $display->content['new-786520ba-25b9-4742-b1ec-a0f098063787'] = $pane;
    $display->panels['right'][2] = 'new-786520ba-25b9-4742-b1ec-a0f098063787';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-1860c7cb-7965-4d5a-be2c-422d9bd2abea';
  $handler->conf['display'] = $display;
  $export['node_view__news'] = $handler;

  return $export;
}
