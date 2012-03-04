.PHONY: all build journal prez code clean

all: build

build: journal prez code

journal:
	make -C journal

prez:
	make -C prez

code:
	make -C code

clean:
	make -C journal clean
	make -C prez clean
	make -C code clean

dist: clean
	zip -r SSL_UnCAPTCHA *
