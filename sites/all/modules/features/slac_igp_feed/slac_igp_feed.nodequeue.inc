<?php
/**
 * @file
 * slac_igp_feed.nodequeue.inc
 */

/**
 * Move a node in a subqueue to front
 * 
 * @params
 * (int)  $nid                  Node nid
 * (int) $subqueue              Subqueue passed by reference
 * (bool) $front                Push the node to the front of the queue
 *
 * @return
 *
 */
function slac_igp_feed_node_move($nid, &$subqueue, $front, $index = 0) {
  if ($front) {
    $current_position = nodequeue_get_subqueue_position($subqueue->sqid, $nid);
    nodequeue_queue_front($subqueue, $current_position + $index);
  }
  else {
    // Get current nids in the queue by position. Apparently no API func for
    // this.
    $q = db_select('nodequeue_nodes', 'nn')
      ->fields('nn', array('nid'))
      ->condition('nn.sqid', $subqueue->sqid)
      ->orderBy('nn.position');
    $nids = $q->execute()->fetchCol();
    // Nodequeue positions are one-based, but our $nids array is zero-based.
    array_splice($nids, $index - 1, 0, $nid);
    // Put things in the order and format nodequeue_save_subqueue_order()
    // expects.
    $order = array();
    foreach (array_unique($nids) as $order_nid) {
      $order[] = array('nid' => $order_nid);
    }
    // Why is this function buried away in an admin include? Who knows.
    module_load_include('inc', 'nodequeue', 'includes/nodequeue.admin');
    nodequeue_save_subqueue_order($order, $subqueue->qid, $subqueue->sqid);
  }
}

/**
 * Add a node into a nodequeue subqueue
 * 
 * @params
 * (int)  $nid                  Node nid
 * (string) $subqueue_title     Title of the subqueue
 * (bool) $front                Push the node to the front of the queue
 *
 * @return
 *
 */
function slac_igp_feed_node_add($nid, $subqueue_title, $front, $index = 0) {
  $queue = slac_igp_feed_get_queue();
  $subqueue = slac_igp_feed_get_subqueue($subqueue_title);
  if (!empty($queue) && !empty($subqueue)) {
    nodequeue_subqueue_add($queue, $subqueue, $nid);
    slac_igp_feed_node_move($nid, $subqueue, $front, $index);
  }
}

/**
 * Remove a node from a subqueue
 * 
 * @params
 * (int) $nid                   Node nid
 * (string) $subqueue_title     Title of the subqueue, or an array of titles
 *
 * @return
 *
 */
function slac_igp_feed_node_remove($nid, $subqueue_title) {
  if (!is_array($subqueue_title)) {
    $titles = array($subqueue_title);
  }
  else {
    $titles = $subqueue_title;
  }
  
  foreach ($titles as $title) {
    $subqueue = slac_igp_feed_get_subqueue($title);
    if (!empty($subqueue)) {
      nodequeue_subqueue_remove_node($subqueue->sqid, $nid);    
    }     
  } 
}

/**
 * Retrieve a subqueue given the subqueue title
 * 
 * @params
 * (string) $subqueue_title     Title of the subqueue
 *
 * @return
 * (mixed) $subqueue            A subqueue object
 *
 */
function slac_igp_feed_get_subqueue($subqueue_title) {
  $subqueues = slac_igp_feed_get_subqueues_all();
  foreach ($subqueues as $key => $subqueue) {
    if ($subqueue->title == $subqueue_title) {
      return $subqueues[$key];
    }
  }
  return;  
}

/**
 * Retrieve a all subqueues from the main queu
 *
 * @return
 * (mixed) $subqueues           Subqueue objects
 *
 */
function slac_igp_feed_get_subqueues_all() {
  $queue = slac_igp_feed_get_queue();
  if (empty($queue)) {
    return;
  }
  $subqueues = array();
  $subqueues = nodequeue_load_subqueues_by_queue($queue->qid);
  return $subqueues;  
}

/**
 * Helper function retrives the main nodequeue
 * 
 * @return
 * (mixed) $queue               A nodequeue object
 *
 */
function slac_igp_feed_get_queue() {
  return nodequeue_load_queue_by_name('news_articles');
}