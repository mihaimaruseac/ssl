#!/bin/bash
# Generate CAPTCHA examples for supervised learning

IMGDIR="examples"
SESSPATH="/tmp/sess_uncaptcha"

if [ -z "$1" ]; then
	# some random number of images
	NUM_IMGS=10
else
	NUM_IMGS=$1
fi

# cleanup previous data if it exists
rm -rf "$IMGDIR"
mkdir "$IMGDIR"

# generate data
for i in $(seq $NUM_IMGS); do
	php supervised-gen.php > "$IMGDIR"/"$i".png
	php supervised-get.php > "$IMGDIR"/"$i".txt
	rm "$SESSPATH"
done
