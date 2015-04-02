<?php
/**
 * @file
 * slac_ip_config_moderation.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function slac_ip_config_moderation_default_rules_configuration() {
  $items = array();
  $items['rules_workbench_notification_new_draft_author_notification'] = entity_import('rules_config', '{ "rules_workbench_notification_new_draft_author_notification" : {
      "LABEL" : "Workbench notification new draft author notification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "SLAC IP Config Moderation" ],
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "draft" } },
        { "content_is_using_workbench_moderation" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:author]",
            "subject" : "Your item, \\u0022[node:title],\\u0022 has been saved.",
            "message" : "You can view, edit and submit the item for publishing at:\\r\\n[node:url].\\r\\n\\r\\n\\r\\nThank you,\\r\\n\\r\\nSLAC Communications",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
