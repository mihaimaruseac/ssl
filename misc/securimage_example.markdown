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

Using PHP sessions for supervised data
--------------------------------------

To generate data for supervised learning using Securimage we need to obtain
the actual CAPTCHA text using PHP scripts. This is usually done through
server-side PHP sessions, as explained in the [quickstart guide] [3].
We're not using an HTTP server so we will have to override the default
behaviour of the `securimage_show_example2.php` script in the Securimage
distribution.

For that we must modify the generation script to write the current session
in a pre-established file. This is done via the PHP `session_` functions.
Thus we will set the session path and the session ID to something
deterministic before starting the session:

	// set session parameters
	session_save_path("/tmp");
	session_id("uncaptcha");
	session_start();

Securimage's `show()` function calls `exit()`, so we can't obtain this
data from the current script in an elegant manner. We must create a
getter script that decodes the session file and prints the CAPTCHA text:


	// open session file and decode it
	$handle = fopen("/tmp/sess_uncaptcha", "r");
	$sessiondata = fread($handle, 4096);
	fclose($handle);

	session_start();
	session_decode($sessiondata);

`session_decode()` will populate the PHP `$_SESSION` variable with all the
data contained within the session. From there we can go and get the text
associated to the previously generated image.

[1]: http://www.phpcaptcha.org/download/
[2]: http://www.phpcaptcha.org/documentation/customizing-securimage/#charset
[3]: http://www.phpcaptcha.org/documentation/quickstart-guide/
