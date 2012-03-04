.PHONY: all build journal prez code clean zip_stage1

ARCHIVE = SSL_UnCAPTCHA.zip
ZIP = zip -r
ZIPJ = zip -j

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
	$(RM) $(ARCHIVE)
	$(ZIP) $(ARCHIVE) *

zip_stage1: clean journal prez
	$(RM) $(ARCHIVE)
	$(ZIPJ) $(ARCHIVE) journal/journal.pdf prez/stage1/stage1.pdf
