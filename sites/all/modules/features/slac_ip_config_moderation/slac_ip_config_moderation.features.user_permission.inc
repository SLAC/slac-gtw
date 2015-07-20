<?php
/**
 * @file
 * slac_ip_config_moderation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function slac_ip_config_moderation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access unpublish button'.
  $permissions['access unpublish button'] = array(
    'name' => 'access unpublish button',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'unpublish_button',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'author' => 'author',
      'editor' => 'editor',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer workbench moderation'.
  $permissions['administer workbench moderation'] = array(
    'name' => 'administer workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'bypass workbench moderation'.
  $permissions['bypass workbench moderation'] = array(
    'name' => 'bypass workbench moderation',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'create draft for access_information nodes in draft state'.
  $permissions['create draft for access_information nodes in draft state'] = array(
    'name' => 'create draft for access_information nodes in draft state',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'slac_ip_config_moderation',
  );

  // Exported permission: 'create draft for access_information nodes in needs_review state'.
  $permissions['create draft for access_information nodes in needs_review state'] = array(
    'name' => 'create draft for access_information nodes in needs_review state',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'slac_ip_config_moderation',
  );

  // Exported permission: 'create draft for access_information nodes in published state'.
  $permissions['create draft for access_information nodes in published state'] = array(
    'name' => 'create draft for access_information nodes in published state',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'slac_ip_config_moderation',
  );

  // Exported permission: 'create draft for event nodes in draft state'.
  $permissions['create draft for event nodes in draft state'] = array(
    'name' => 'create draft for event nodes in draft state',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'slac_ip_config_moderation',
  );

  // Exported permission: 'create draft for event nodes in needs_review state'.
  $permissions['create draft for event nodes in needs_review state'] = array(
    'name' => 'create draft for event nodes in needs_review state',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'slac_ip_config_moderation',
  );

  // Exported permission: 'create draft for event nodes in published state'.
  $permissions['create draft for event nodes in published state'] = array(
    'name' => 'create draft for event nodes in published state',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'slac_ip_config_moderation',
  );

  // Exported permission: 'create draft for flea_market_post nodes in draft state'.
  $permissions['create draft for flea_market_post nodes in draft state'] = array(
    'name' => 'create draft for flea_market_post nodes in draft state',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'slac_ip_config_moderation',
  );

  // Exported permission: 'create draft for flea_market_post nodes in needs_review state'.
  $permissions['create draft for flea_market_post nodes in needs_review state'] = array(
    'name' => 'create draft for flea_market_post nodes in needs_review state',
    'roles' => array(),
    'module' => 'slac_ip_config_moderation',
  );

  // Exported permission: 'create draft for flea_market_post nodes in published state'.
  $permissions['create draft for flea_market_post nodes in published state'] = array(
    'name' => 'create draft for flea_market_post nodes in published state',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'slac_ip_config_moderation',
  );

  // Exported permission: 'create draft for news nodes in draft state'.
  $permissions['create draft for news nodes in draft state'] = array(
    'name' => 'create draft for news nodes in draft state',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'slac_ip_config_moderation',
  );

  // Exported permission: 'create draft for news nodes in needs_review state'.
  $permissions['create draft for news nodes in needs_review state'] = array(
    'name' => 'create draft for news nodes in needs_review state',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'slac_ip_config_moderation',
  );

  // Exported permission: 'create draft for news nodes in published state'.
  $permissions['create draft for news nodes in published state'] = array(
    'name' => 'create draft for news nodes in published state',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'slac_ip_config_moderation',
  );

  // Exported permission: 'moderate access_information state from draft to needs_review'.
  $permissions['moderate access_information state from draft to needs_review'] = array(
    'name' => 'moderate access_information state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate access_information state from draft to published'.
  $permissions['moderate access_information state from draft to published'] = array(
    'name' => 'moderate access_information state from draft to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate access_information state from needs_review to draft'.
  $permissions['moderate access_information state from needs_review to draft'] = array(
    'name' => 'moderate access_information state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate access_information state from needs_review to published'.
  $permissions['moderate access_information state from needs_review to published'] = array(
    'name' => 'moderate access_information state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate access_information state from published to draft'.
  $permissions['moderate access_information state from published to draft'] = array(
    'name' => 'moderate access_information state from published to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from draft to published'.
  $permissions['moderate content from draft to published'] = array(
    'name' => 'moderate content from draft to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to draft'.
  $permissions['moderate content from needs_review to draft'] = array(
    'name' => 'moderate content from needs_review to draft',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to published'.
  $permissions['moderate content from needs_review to published'] = array(
    'name' => 'moderate content from needs_review to published',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from published to draft'.
  $permissions['moderate content from published to draft'] = array(
    'name' => 'moderate content from published to draft',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'manager' => 'manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate event state from draft to needs_review'.
  $permissions['moderate event state from draft to needs_review'] = array(
    'name' => 'moderate event state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate event state from draft to published'.
  $permissions['moderate event state from draft to published'] = array(
    'name' => 'moderate event state from draft to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate event state from needs_review to draft'.
  $permissions['moderate event state from needs_review to draft'] = array(
    'name' => 'moderate event state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate event state from needs_review to published'.
  $permissions['moderate event state from needs_review to published'] = array(
    'name' => 'moderate event state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate event state from published to draft'.
  $permissions['moderate event state from published to draft'] = array(
    'name' => 'moderate event state from published to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate flea_market_post state from draft to needs_review'.
  $permissions['moderate flea_market_post state from draft to needs_review'] = array(
    'name' => 'moderate flea_market_post state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate flea_market_post state from needs_review to draft'.
  $permissions['moderate flea_market_post state from needs_review to draft'] = array(
    'name' => 'moderate flea_market_post state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate flea_market_post state from needs_review to published'.
  $permissions['moderate flea_market_post state from needs_review to published'] = array(
    'name' => 'moderate flea_market_post state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate flea_market_post state from published to draft'.
  $permissions['moderate flea_market_post state from published to draft'] = array(
    'name' => 'moderate flea_market_post state from published to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news state from draft to needs_review'.
  $permissions['moderate news state from draft to needs_review'] = array(
    'name' => 'moderate news state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news state from draft to published'.
  $permissions['moderate news state from draft to published'] = array(
    'name' => 'moderate news state from draft to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news state from needs_review to draft'.
  $permissions['moderate news state from needs_review to draft'] = array(
    'name' => 'moderate news state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news state from needs_review to published'.
  $permissions['moderate news state from needs_review to published'] = array(
    'name' => 'moderate news state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news state from published to draft'.
  $permissions['moderate news state from published to draft'] = array(
    'name' => 'moderate news state from published to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'use workbench_moderation my drafts tab'.
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'author' => 'author',
      'editor' => 'editor',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'use workbench_moderation needs review tab'.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'author' => 'author',
      'editor' => 'editor',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view all unpublished content'.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'author' => 'author',
      'editor' => 'editor',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation messages'.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'workbench_moderation',
  );

  return $permissions;
}
