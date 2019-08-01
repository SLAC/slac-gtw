<?php
/**
 * @file
 * slac_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function slac_rules_default_rules_configuration() {
  $items = array();
  $items['rules_notification_when_comment_has_been_added'] = entity_import('rules_config', '{ "rules_notification_when_comment_has_been_added" : {
      "LABEL" : "Notification when comment has been added",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : { "comment_insert" : [] },
      "DO" : [
        { "mail" : {
            "to" : "communications@slac.stanford.edu",
            "subject" : "A new comment has been added to: [comment:node:title]",
            "message" : "A new comment has been added to: [comment:node:title] by [site:current-user]. \\r\\n\\r\\n[comment:title]\\r\\n[comment:body]\\r\\n\\r\\nYou may edit\\/delete the comment at: [comment:url]  You may also edit all comments at: [site:url]\\/admin\\/content\\/comment.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
