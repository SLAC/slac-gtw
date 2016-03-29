<?php
/**
 * @file
 * slac_weather_blocks.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function slac_weather_blocks_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'new_weather_traffic';
  $mini->category = 'Miscellaneous';
  $mini->admin_title = 'new_weather_traffic';
  $mini->admin_description = 'A block to replace the weather and traffic module that is no longer supported';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'zen_no_wrapper';
  $display->layout_settings = array(
    'main_classes' => '',
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8a8a0a74-c6dc-489b-b9cd-9bef5b1ecfef';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2320f2f7-4630-4100-9fcc-211ab27bc466';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'wunderground_weather-wunderground_weather_current_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Current Conditions',
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
    $pane->uuid = '2320f2f7-4630-4100-9fcc-211ab27bc466';
    $display->content['new-2320f2f7-4630-4100-9fcc-211ab27bc466'] = $pane;
    $display->panels['main'][0] = 'new-2320f2f7-4630-4100-9fcc-211ab27bc466';
    $pane = new stdClass();
    $pane->pid = 'new-55684a34-d81a-4493-98a5-b76665f1eea7';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'wunderground_weather-wunderground_weather_forecast_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Forcast',
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
    $pane->uuid = '55684a34-d81a-4493-98a5-b76665f1eea7';
    $display->content['new-55684a34-d81a-4493-98a5-b76665f1eea7'] = $pane;
    $display->panels['main'][1] = 'new-55684a34-d81a-4493-98a5-b76665f1eea7';
    $pane = new stdClass();
    $pane->pid = 'new-78304b87-d289-4acb-8710-8ca0867f18d3';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'boxes-weather_traffic';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Traffic',
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
    $pane->uuid = '78304b87-d289-4acb-8710-8ca0867f18d3';
    $display->content['new-78304b87-d289-4acb-8710-8ca0867f18d3'] = $pane;
    $display->panels['main'][2] = 'new-78304b87-d289-4acb-8710-8ca0867f18d3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2320f2f7-4630-4100-9fcc-211ab27bc466';
  $mini->display = $display;
  $export['new_weather_traffic'] = $mini;

  return $export;
}
