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
  $items['ct_flea_market_item_send_email_when_comment_is_flagged'] = entity_import('rules_config', '{ "ct_flea_market_item_send_email_when_comment_is_flagged" : {
      "LABEL" : "Send email when comment is flagged",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_flagged_comment_flag" : [] },
      "DO" : [
        { "mail" : {
            "to" : "communications@slac.stanford.edu",
            "subject" : "A comment has been flagged as inappropriate.",
            "message" : "The comment at: [flagged-comment:node] by [flagged-comment:author] has been flagged as inappropriate.",
            "from" : "communications@slac.stanford.edu",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
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
