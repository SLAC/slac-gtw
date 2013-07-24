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
function slac_igp_feed_node_move($nid, &$subqueue, $front) {
  if ($front) {
    $position = nodequeue_get_subqueue_position($subqueue->sqid, $nid);
    nodequeue_queue_front($subqueue, $position);    
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
function slac_igp_feed_node_add($nid, $subqueue_title, $front) {
  $queue = slac_igp_feed_get_queue();
  $subqueue = slac_igp_feed_get_subqueue($subqueue_title);
  if (!empty($queue) && !empty($subqueue)) {
    nodequeue_subqueue_add($queue, $subqueue, $nid);
    slac_igp_feed_node_move($nid, $subqueue, $front);
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