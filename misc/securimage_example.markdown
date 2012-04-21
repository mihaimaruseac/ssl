Running Securimage to generate CAPTCHAs
=======================================

1. Download securimage from the [official site] [1] and extract the archive;
2. Make sure you have the following installed: php (the base language) and
   php-gd. Also make sure PHP uses gd (in /etc/php/php.ini the line
   extension=gd.so needs to be uncommented);
3. Take a look at `securimage_show_example.php`. That one contains some basic
   customization of image parameters. There's more in the Securimage
   [documentation] [2] related to that;
4. Run `php securimage_show_example.php > image.png`. This will give us
   an example to work with;
5. **TODO**: See where the CAPTCHA text is stored to use it for generation of
   supervised learning examples. It seems to want to use either an SQLite or
   a HTTP server session backend for that. This one requires a bit of
   investigation.

[1]: http://www.phpcaptcha.org/download/
[2]: http://www.phpcaptcha.org/documentation/customizing-securimage/#charset
