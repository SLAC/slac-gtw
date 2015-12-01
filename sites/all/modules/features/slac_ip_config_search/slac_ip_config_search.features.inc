<?php
/**
 * @file
 * slac_ip_config_search.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function slac_ip_config_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "drupal",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "1",
            "bundles" : {
              "page" : "page",
              "calendar_feed" : "calendar_feed",
              "news_article" : "news_article",
              "news_feed" : "news_feed",
              "webform" : "webform"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "aggregate-fulltext-search-field",
                "type" : "fulltext",
                "fields" : [
                  "title",
                  "author",
                  "field_page_subtitle",
                  "field_shared_contact_name",
                  "field_shared_location",
                  "field_shared_news_title",
                  "field_event_series",
                  "field_news_subtitle",
                  "field_shared_byline",
                  "body:value",
                  "body:summary",
                  "field_shared_related_files:description"
                ],
                "description" : "A Fulltext aggregation of the following fields: Title, Author, Subtitle, Contact Name, Location, News Title, Event Series, Subtitle, Byline, The main body text \\u00bb Text, The main body text \\u00bb Summary, Related Files \\u00bb The file description."
              }
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 1, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^\\\\p{L}\\\\p{N}]", "ignorable" : "[-]" }
        },
        "search_api_stopwords" : {
          "status" : 1,
          "weight" : "30",
          "settings" : {
            "fields" : { "search_api_aggregation_1" : true },
            "file" : "",
            "stopwords" : "a\\r\\nable\\r\\nabout\\r\\nacross\\r\\nafter\\r\\nall\\r\\nalmost\\r\\nalso\\r\\nam\\r\\namong\\r\\nan\\r\\nand\\r\\nany\\r\\nare\\r\\nas\\r\\nat\\r\\nbe\\r\\nbecause\\r\\nbeen\\r\\nbut\\r\\nby\\r\\ncan\\r\\ncannot\\r\\ncould\\r\\ndear\\r\\ndid\\r\\ndo\\r\\ndoes\\r\\neither\\r\\nelse\\r\\never\\r\\nevery\\r\\nfor\\r\\nfrom\\r\\nget\\r\\ngot\\r\\nhad\\r\\nhas\\r\\nhave\\r\\nhe\\r\\nher\\r\\nhers\\r\\nhim\\r\\nhis\\r\\nhow\\r\\nhowever\\r\\ni\\r\\nif\\r\\nin\\r\\ninto\\r\\nis\\r\\nit\\r\\nits\\r\\njust\\r\\nleast\\r\\nlet\\r\\nlike\\r\\nlikely\\r\\nmay\\r\\nme\\r\\nmight\\r\\nmost\\r\\nmust\\r\\nmy\\r\\nneither\\r\\nno\\r\\nnor\\r\\nnot\\r\\nof\\r\\noff\\r\\noften\\r\\non\\r\\nonly\\r\\nor\\r\\nother\\r\\nour\\r\\nown\\r\\nrather\\r\\nsaid\\r\\nsay\\r\\nsays\\r\\nshe\\r\\nshould\\r\\nsince\\r\\nso\\r\\nsome\\r\\nthan\\r\\nthat\\r\\nthe\\r\\ntheir\\r\\nthem\\r\\nthen\\r\\nthere\\r\\nthese\\r\\nthey\\r\\nthis\\r\\ntis\\r\\nto\\r\\ntoo\\r\\ntwas\\r\\nus\\r\\nwants\\r\\nwas\\r\\nwe\\r\\nwere\\r\\nwhat\\r\\nwhen\\r\\nwhere\\r\\nwhich\\r\\nwhile\\r\\nwho\\r\\nwhom\\r\\nwhy\\r\\nwill\\r\\nwith\\r\\nwould\\r\\nyet\\r\\nyou\\r\\nyour"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_event_series" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_event_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_news_news_type" : { "type" : "string" },
        "field_news_subtitle" : { "type" : "text" },
        "field_shared_byline" : { "type" : "text" },
        "field_shared_contact_name" : { "type" : "text" },
        "field_shared_location" : { "type" : "text" },
        "field_shared_news_title" : { "type" : "text" },
        "field_shared_related_files:description" : { "type" : "list\\u003Ctext\\u003E" },
        "field_shared_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_shared_tags:name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_shared_tags:parent" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_shared_tags:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_shared_tags:vocabulary" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "taxonomy_vocabulary"
        },
        "promote" : { "type" : "boolean" },
        "published_at" : { "type" : "date" },
        "search_api_aggregation_1" : { "type" : "text", "boost" : "5.0" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function slac_ip_config_search_default_search_api_server() {
  $items = array();
  $items['drupal'] = entity_import('search_api_server', '{
    "name" : "Drupal",
    "machine_name" : "drupal",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "2",
      "partial_matches" : 0,
      "indexes" : { "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "promote" : {
            "table" : "search_api_db_default_node_index",
            "column" : "promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_default_node_index",
            "column" : "sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_shared_tags" : {
            "table" : "search_api_db_default_node_index_field_shared_tags",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_event_type" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_event_type",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_news_news_type" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_news_news_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_shared_tags:name" : {
            "table" : "search_api_db_default_node_index_field_shared_tags_name",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_default_node_index",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "published_at" : {
            "table" : "search_api_db_default_node_index",
            "column" : "published_at",
            "type" : "date",
            "boost" : "1.0"
          },
          "search_api_aggregation_1" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "field_shared_tags:vocabulary" : {
            "table" : "search_api_db_default_node_index_field_shared_tags_vocabulary",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_shared_tags:parent" : {
            "table" : "search_api_db_default_node_index_field_shared_tags_parent",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_shared_tags:parents_all" : {
            "table" : "search_api_db_default_node_index_field_shared_tags_parents_all",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_event_series" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_event_series",
            "type" : "integer",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_shared_contact_name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_shared_location" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_shared_news_title" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_shared_byline" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_news_subtitle" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "body:summary" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_shared_related_files:description" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
