<?php

/**
 * @file
 * API documentation for the Symfony module.
 */

/**
 * Allows modules to register their own namespaces for the auto-loader.
 *
 * @param $library
 *   The Symfony library array from Libraries API.
 * @param $loader
 *   The Symfony loader object.
 */
function hook_symfony_register($library, $loader) {
  // Register the Symfony namespace.
  $loader->registerNamespace('Symfony', $library['library path'] . '/Symfony/vendor/symfony/src');
}
