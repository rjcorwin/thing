<?php
/**
 * @file
 * thing.features.inc
 */

/**
 * Implements hook_node_info().
 */
function thing_node_info() {
  $items = array(
    'thing' => array(
      'name' => t('Thing'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
