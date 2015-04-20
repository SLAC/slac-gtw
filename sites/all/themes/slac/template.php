<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * A QUICK OVERVIEW OF DRUPAL THEMING
 *
 *   The default HTML for all of Drupal's markup is specified by its modules.
 *   For example, the comment.module provides the default HTML markup and CSS
 *   styling that is wrapped around each comment. Fortunately, each piece of
 *   markup can optionally be overridden by the theme.
 *
 *   Drupal deals with each chunk of content using a "theme hook". The raw
 *   content is placed in PHP variables and passed through the theme hook, which
 *   can either be a template file (which you should already be familiary with)
 *   or a theme function. For example, the "comment" theme hook is implemented
 *   with a comment.tpl.php template file, but the "breadcrumb" theme hooks is
 *   implemented with a theme_breadcrumb() theme function. Regardless if the
 *   theme hook uses a template file or theme function, the template or function
 *   does the same kind of work; it takes the PHP variables passed to it and
 *   wraps the raw content with the desired HTML markup.
 *
 *   Most theme hooks are implemented with template files. Theme hooks that use
 *   theme functions do so for performance reasons - theme_field() is faster
 *   than a field.tpl.php - or for legacy reasons - theme_breadcrumb() has "been
 *   that way forever."
 *
 *   The variables used by theme functions or template files come from a handful
 *   of sources:
 *   - the contents of other theme hooks that have already been rendered into
 *     HTML. For example, the HTML from theme_breadcrumb() is put into the
 *     $breadcrumb variable of the page.tpl.php template file.
 *   - raw data provided directly by a module (often pulled from a database)
 *   - a "render element" provided directly by a module. A render element is a
 *     nested PHP array which contains both content and meta data with hints on
 *     how the content should be rendered. If a variable in a template file is a
 *     render element, it needs to be rendered with the render() function and
 *     then printed using:
 *       <?php print render($variable); ?>
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. With this file you can do three things:
 *   - Modify any theme hooks variables or add your own variables, using
 *     preprocess or process functions.
 *   - Override any theme function. That is, replace a module's default theme
 *     function with one you write.
 *   - Call hook_*_alter() functions which allow you to alter various parts of
 *     Drupal's internals, including the render elements in forms. The most
 *     useful of which include hook_form_alter(), hook_form_FORM_ID_alter(),
 *     and hook_page_alter(). See api.drupal.org for more information about
 *     _alter functions.
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   If a theme hook uses a theme function, Drupal will use the default theme
 *   function unless your theme overrides it. To override a theme function, you
 *   have to first find the theme function that generates the output. (The
 *   api.drupal.org website is a good place to find which file contains which
 *   function.) Then you can copy the original function in its entirety and
 *   paste it in this template.php file, changing the prefix from theme_ to
 *   STARTERKIT_. For example:
 *
 *     original, found in modules/field/field.module: theme_field()
 *     theme override, found in template.php: STARTERKIT_field()
 *
 *   where STARTERKIT is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_field() function.
 *
 *   Note that base themes can also override theme functions. And those
 *   overrides will be used by sub-themes unless the sub-theme chooses to
 *   override again.
 *
 *   Zen core only overrides one theme function. If you wish to override it, you
 *   should first look at how Zen core implements this function:
 *     theme_breadcrumbs()      in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called theme hook suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node--forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and theme hook suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440 and http://drupal.org/node/1089656
 */

/**
 * Preprocess quicktabs
 */
function slac_preprocess_qt_quicktabs(&$variables) {
  // adding the tab title into each tab content area for staff resources
  $element = $variables['element'];
  if ($element['#options']['attributes']['id'] === 'quicktabs-staff_resources') {
    foreach ($element['tabs']['tablinks'] as $key => $data) {
      $element['container']['divs'][$key]['#prefix'] .= '<h3>' . $data['#title'] . '</h3>';
    }
  }
  $variables['element'] = $element;
}


function slac_preprocess_block(&$variables) {
  // In the header region visually hide block titles.
  if ($variables['block']->region == 'header') {
    $variables['title_attributes_array']['class'][] = 'element-invisible';
  }
}

function slac_menu_link(array $variables) {
  $element = $variables['element'];
  $original_link = $element['#original_link'];
  $depth = 'depth-' . $original_link['depth'];
  $menu_name = 'item-' . $original_link['menu_name'];

  $variables['element']['#attributes']['class'][] = $depth;
  $variables['element']['#attributes']['class'][] = $menu_name;

  return theme_menu_link($variables);
}

/**
 * Override file entity download link.
 *
 * Removes the file size and moves the icon to the end of the link.
 *
 * @see theme_file_file_link()
 */
function slac_file_entity_download_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $uri = file_entity_download_uri($file);
  $icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $uri['options']['attributes']['type'] = $file->filemime . '; length=' . $file->filesize;
  if (empty($variables['file']->description)) {

    // Provide the default link text. Remove the 'Download ' string that is in the
    // default output.
    $variables['text'] = '[file:name]';

    // Perform un-sanitized token replacement if $uri['options']['html'] is empty
    // since then l() will escape the link text.
    $variables['text'] = token_replace($variables['text'], array('file' => $file), array('clear' => TRUE, 'sanitize' => empty($uri['options']['html'])));
  }
  else {
    $variables['text'] = $variables['file']->description;
  }
  $output = '<span class="file">';
  $output .= l($variables['text'], $uri['path'], $uri['options']) . ' ' . $icon;
  $output .= '</span>';

  return $output;
}

/**
* @implements hook_preprocess_node()
*/
function slac_preprocess_node(&$variables, $hook) {
  $view_mode = $variables['view_mode'];
  $content_type = $variables['type'];
  $variables['theme_hook_suggestions'][] = 'node__' . $view_mode;
  $variables['theme_hook_suggestions'][] = 'node__' . $content_type . '_' . $view_mode;

  $view_mode_preprocess = 'slac_preprocess_node_' . $content_type . '_' . $view_mode;
  if (function_exists($view_mode_preprocess)) {
    $view_mode_preprocess($variables, $hook);
  }

  $view_mode_preprocess = 'slac_preprocess_node_' . $view_mode;
  if (function_exists($view_mode_preprocess)) {
    $view_mode_preprocess($variables, $hook);
  }
}

/**
 * Override the range separator for all date fields.
 */
function slac_date_display_range($variables) {
  $date1 = $variables['date1'];
  $date2 = $variables['date2'];
  $timezone = $variables['timezone'];
  $attributes_start = $variables['attributes_start'];
  $attributes_end = $variables['attributes_end'];

  $start_date = '<span class="date-display-start"' . drupal_attributes($attributes_start) . '>' . $date1 . '</span>';
  $end_date = '<span class="date-display-end"' . drupal_attributes($attributes_end) . '>' . $date2 . $timezone . '</span>';

  // If microdata attributes for the start date property have been passed in,
  // add the microdata in meta tags.
  if (!empty($variables['add_microdata'])) {
    $start_date .= '<meta' . drupal_attributes($variables['microdata']['value']['#attributes']) . '/>';
    $end_date .= '<meta' . drupal_attributes($variables['microdata']['value2']['#attributes']) . '/>';
  }

  // Wrap the result with the attributes.
  return t('!start-date - !end-date', array(
    '!start-date' => $start_date,
    '!end-date' => $end_date,
  ));
}

/**
 * Override or insert variables for theme_field().
 */
function slac_process_field(&$vars) {
  $element = $vars['element'];
  // Field type image
  if ($element['#field_type'] == 'image') {
    // Reduce the number of images displayed in certain view modes to one.
    if ($element['#view_mode'] == 'news_archive') {
      $item = reset($vars['items']);
      $vars['items'] = array($item);
    }
  }
}

/**
 * Override or insert variables for theme_views_view().
 */
function slac_preprocess_views_view(&$vars) {
  $view = &$vars['view'];
  if ($view->name == 'news_archive') {
    // Update the title based on the News type filter.
    if (isset($view->exposed_data['field_news_news_type_value'])) {
      $type = $view->exposed_data['field_news_news_type_value'];
      if ($type !== 'All') {
        // Update the title.
        $view->build_info['title'] = $type;
      }
    }
  }
}
