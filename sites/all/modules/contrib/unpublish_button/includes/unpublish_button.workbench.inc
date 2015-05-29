<?php
/**
 * @file
 * Workbench Moderation specific code for the Unpublish button.
 */

/**
 * Helper function for Workbench Moderation node form alter. 
 */
function _unpublish_button_workbench_node_form(&$form) {
  // Only applies to nodes with moderation enabled.
  if (!workbench_moderation_node_moderated($form['#node'])) {
    return;
  }
  $current_state = variable_get('workbench_moderation_default_state_' . $form['type']['#value'], workbench_moderation_state_none());
  // Remove 'unpublished' action if it exists.
  // @todo: Figure out how to do this in a more generic fashion.
  if (isset($form['actions']['unpublished'])) {
    unset($form['actions']['unpublished']);
  }
  // Remove 'Unpublish' button if Workbench Moderation Buttons added one.
  // @todo: Figure out how to do this in a more generic fashion.
  if (isset($form['#workbench_moderation_buttons_list']['Unpublish'])) {
    unset($form['#workbench_moderation_buttons_list']['Unpublish']);
  }
  // When there is a Published revision, provide an Unpublish button.
  if (!empty($form['#node']->workbench_moderation['published'])) {
    // Add Submit handler.
    $form['actions']['submit']['#submit'][] = 'unpublish_button_node_form_submit';
    // Add the Unpublish button.
    _unpublish_button_add_button($form, 'Unpublish');
  }
}

/**
 * Helper function for Workbench Moderation node form validation.
 */
function _unpublish_button_workbench_node_form_validate($form, &$form_state) {
  // Check for the 'Unpublish' operation.
  if ($form_state['values']['op'] == 'Unpublish') {
    // Retrieve the published node information.
    if (!empty($form['#entity']->workbench_moderation['published'])) {
      $node = $form['#entity']->workbench_moderation['published'];
    }
    else {
      $form_state['rebuild'] = TRUE;
      drupal_set_message(t('There is no currently published revision.'), 'error');
    }
    // Check for available published node id and revision id.
    if (isset($node->nid) && isset($node->vid)) {
      // Create link to the Unpublish form for the Published revision.
      $form_state['unpublish_link'] = 'node/' . $node->nid  . '/moderation/'. $node->vid  . '/unpublish';
    }
    else {
      $form_state['rebuild'] = TRUE;
      drupal_set_message(t('There was an error retrieving the published revision id.'), 'error');
    }
  }
}

/**
 * Helper function for Workbench Moderation node form submit handler.
 */
function _unpublish_button_workbench_node_form_submit($form, &$form_state) {
  if (isset($form_state['unpublish_link'])) {
    // Clear any confusing messages about node updates.
    drupal_get_messages();
    // Redirect users to the 'Unpublish' form.
    $form_state['redirect'] = $form_state['unpublish_link'];
    // In case there is a destination parameter, override it.
    if (isset($_GET['destination'])) {
      unset($_GET['destination']);
      drupal_static_reset('drupal_get_destination') ;
    }
  }
}

