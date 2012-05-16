<?php

/**
 * Script based on securimage_show_example2.php in the securimage distro.
 */

require_once dirname(__FILE__) . '/securimage/securimage.php';

// set session parameters
session_save_path("/tmp");
session_id("uncaptcha");
session_start();

$img = new Securimage();

//Change some settings
$img->code_length     = rand(1,1); // random code length
$img->case_sensitive  = true;
$img->perturbation    = 0;      // high level of distortion
$img->image_bg_color  = new Securimage_Color("#ffffff");
$img->num_lines       = 0;
$img->noise_level     = 0;
$img->text_color      = new Securimage_Color("#000000");
$img->noise_color     = $img->text_color;
$img->line_color      = new Securimage_Color("#cccccc");

$img->show();

?>
