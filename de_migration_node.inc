<?php


/**
 * @file
 * DrupalEasy custom node migrations.
 */

class DrupalEasyBlogMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    /*
     * UID: Use user interface (with source migration). 
     * Main topic: use user interface for field (with source migration) and source_type, 
     *   DNM create_term and ignore_case.
     * Tags: use user interface for field (with source migration) and source_type, 
     *   DNM create_term and ignore_case.
     * Create new revision: use user interface.
     * Revision Log message: use user interface.
     * Modified (uid): use user interface.
     * daycount (source): DNM
     * timestamp (source): DNM
     * totalcount (source): DNM
     * field_file_attachment: use user interface (with source migration)
     * field_file_attachment:file_class: use user interface ('MigrateFileFid')
     * field_file_attachment:language: DNM
     * field_file_attachment:preserve_files: use user interface ('FALSE')
     * //field_file_attachment:destination_dir: use user interface ('public://')
     * //field_file_attachment:destination_file: DNM
     * //field_file_attachment:file_replace: use user interface ('FILE_EXISTS_REUSE')
     * //field_file_attachment:source_dir: use user inteface ('http://drupaleasy6.dev/sites/drupaleasy.com/files')
     * //field_file_attachment:urlencode: DNM
     * field_file_attachment:description: use user interface
     * field_file_attachment:display: use user interface
     */
  }
  
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    
    // Update body file paths
    $row->body = str_replace("src=\"http://drupaleasy.com/sites/drupaleasy.com/files/", "src=\"/sites/default/files/", $row->body);
    $row->teaser = str_replace("src=\"http://drupaleasy.com/sites/drupaleasy.com/files/", "src=\"/sites/default/files/", $row->teaser);
  }
}

