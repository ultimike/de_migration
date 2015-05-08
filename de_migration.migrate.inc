<?php

/**
 * Implement hook_migrate_api().
 *
 * API must be set to "2" for the 7.x-2.x branch of Migrate.
 */
function de_migration_migrate_api() {
  $common_arguments = array(
    'source_connection' => 'drupaleasy6', //Configured in settings.php
    'source_version' => 6,
  );

  $api = array(
    'api' => 2,
    'groups' => array(
      'decustom' => array(
        'title' => t('DrupalEasy custom migrations'),
      ),
    ),
    'migrations' => array(
      'DrupalEasyBlog' => $common_arguments + array(
        'class_name' => 'DrupalEasyBlogMigration',
        'source_type' => 'blog',
        'destination_type' => 'blog',
        'group_name' => 'decustom',
        'description' => 'Custom migration for blogs',
        'dependencies' => array(
          '9c1355fc7User',
          '9c1355fc7File',
          '9c1355fc7Term2',
          '9c1355fc7Term3',
        ),
      ),
    ),
  );
  return $api;
}
