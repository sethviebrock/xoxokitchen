<?php
// $Id$

/**
 * Implements hook_drush_command().
 */
function symfony_drush_command() {
  $items['symfony-download'] = array(
    'description' => 'Download the Symfony library.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_ROOT, // No site or config needed.
    'arguments' => array(
      'version' => dt('Optional. A version number for Symfony. Should be in the form "2.0.0". Defaults to "2.0.7".'),
      'path' => dt('Optional. A path to the download folder. If omitted Drush will use the default location (sites/all/libraries/symfony).'),
    ),
  );
  return $items;
}

/**
 * Checkout Symfony and vendors from git.
 */
function drush_symfony_download() {
  $args = func_get_args();

  // Check the version number.
  $version = ($args[0]) ? $args[0] : '2.0.7';
  // Construct the path.
  $path = ($args[1]) ? $args[1] : drush_get_context('DRUSH_DRUPAL_ROOT') . '/sites/all/libraries/symfony';

  // Checkout the latest from Symfony, only if the directory doesn't exist yet.
  drush_log(dt('Installing Symfony... Please wait.'), 'success');
  if (!is_dir($path)) {
    if (drush_shell_exec('git clone http://github.com/symfony/symfony.git ' . escapeshellarg($path))) {
      drush_log(dt('Installed Symfony to @path.', array('@path' => $path)), 'success');
    }
    else {
      drush_log(dt('Failed to install Symfony to @path.', array('@path' => $path)), 'success');
      return;
    }
  }

  // If the directory exists, try to checkout the specific version.
  if (is_dir($path)) {
    drush_log(dt('Checking out version @version.', array('@path' => $path, '@version' => $version)), 'success');
    if (drush_shell_exec('cd ' . escapeshellarg($path) . ' && git fetch origin && git reset --hard ' . escapeshellarg('v' . $version))) {
      drush_log(dt('Version @version successfully checked out.', array('@version' => $version)), 'success');
    }
    else {
      drush_log(dt('Version @version failed to install.', array('@version' => $version)), 'error');
      return;
    }

    // Install the vendors.
    drush_log(dt('Installing vendor dependencies.'), 'success');
    require_once($path . '/vendors.php');

    // Install Symfony as a vendor.
    drush_log(dt('Installing Symfony as a vendor.'), 'success');
    if (!is_dir($path . '/vendor/symfony')) {
      drush_shell_exec('git clone ' . escapeshellarg('http://github.com/symfony/symfony.git') . ' ' . escapeshellarg($path . '/vendor/symfony'));
    }
    // Checkout the specific tag.
    drush_shell_exec('cd ' . escapeshellarg($path . '/vendor/symfony') . ' && git fetch origin && git reset --hard v' . escapeshellarg($version));

    // Create the debs file for version infomation.
    $contents .= "[symfony]\n";
    $contents .= "   git=http://github.com/symfony/symfony.git\n";
    $contents .= "   version=v$version\n\n";
    if (file_put_contents($path . '/deps', $contents)) {
      drush_log(dt('Version information written in the deps file.'), 'success');
    }
    else {
      drush_log(dt('Failed to write deps file for version information.'), 'warning');
    }
  }
  else {
    drush_log(dt('Drush was unable to find Symfony at @path.', array('@path' => $path, '@version' => $version)), 'error');
  }
}
