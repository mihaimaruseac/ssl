<?php

// include securimage
include_once dirname(__FILE__) . '/securimage/securimage.php';

// open session file and decode it
$handle = fopen("/tmp/sess_uncaptcha", "r");
$sessiondata = fread($handle, 4096);
fclose($handle);

session_start();
session_decode($sessiondata);

// print the decoded data
//print_r($_SESSION);
fwrite(STDOUT, $_SESSION['securimage_code_value']['default']);
//fwrite(STDOUT, "\n");

?>

