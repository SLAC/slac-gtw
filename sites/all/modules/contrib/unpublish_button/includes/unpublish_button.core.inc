<?php
/**
 * @file
 * Drupal core compatible code for the Unpublish button.
 */

/**
 * Helper function for 'core' node form alter. 
 */
function _unpublish_button_core_node_form(&$form) {
  // Override the core submit handler (this prevents multiple revisions).
  unset($form['actions']['submit']['#submit']);
  $form['actions']['submit']['#submit'][] = 'unpublish_button_node_form_submit';
  // Add button to the form based on current status.
  if ($form['#node']->status) {
    // Add the Unpublish button.
    _unpublish_button_add_button($form, 'Unpublish');
  }
  else {
    // Add a Publish button instead.
    _unpublish_button_add_button($form, 'Publish');
  }
}

/**
 * Helper function for 'core' node form validation.
 */
function _unpublish_button_core_node_form_validate($form, &$form_state) {
  // Check for the 'Unpublish' operation.
  if ($form_state['values']['op'] == 'Unpublish') {
    // Ensure the node is actually published.
    if ($form['#node']->status != 1) {
      $form_state['rebuild'] = TRUE;
      drupal_set_message(t('There was an error. The node is not Published.'), 'error');
    }
  }
  // Check for the 'Publish' operation.
  if ($form_state['values']['op'] == 'Publish') {
    // Ensure the node is not already published.
    if ($form['#node']->status == 1) {
      $form_state['rebuild'] = TRUE;
      drupal_set_message(t('There was an error. The node is already Published.'), 'error');
    }
  }
}

/**
 * Helper function for 'core' node form submit handler.
 */
function _unpublish_button_core_node_form_submit($form, &$form_state) {
  // Check for a Publish or Unpublish action and set status.
  if ($form_state['values']['op'] == 'Unpublish') {
    $status = 0;
  }
  elseif ($form_state['values']['op'] == 'Publish') {
    $status = 1;
  }
  if (isset($status)) {
    // Set new node status.
    $form_state['values']['status'] = $status;
  }
  // Submit the node form.
  node_form_submit($form, $form_state);
}
