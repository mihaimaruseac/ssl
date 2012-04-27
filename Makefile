.PHONY: all build journal prez code clean zip_stage1 zip_stage2

ARCHIVE = SSL_UnCAPTCHA.zip
ZIP = zip -r
ZIPJ = zip -j

all: build

build: journal prez code

journal:
	@make --no-print-directory -C journal

prez:
	@make --no-print-directory -C prez

code:
	@make --no-print-directory -C code

clean:
	@make --no-print-directory -C journal clean
	@make --no-print-directory -C prez clean
	@make --no-print-directory -C code clean

dist: clean
	@$(RM) $(ARCHIVE)
	@$(ZIP) $(ARCHIVE) *

zip_stage1: clean journal prez
	@$(RM) $(ARCHIVE)
	@$(ZIPJ) $(ARCHIVE) journal/journal.pdf prez/stage1/stage1.pdf

zip_stage2: clean journal prez
	@$(RM) $(ARCHIVE)
	@$(ZIPJ) $(ARCHIVE) journal/journal.pdf prez/stage2/stage2.pdf

zip_stage3: clean journal prez
	@$(RM) $(ARCHIVE)
	@$(ZIPJ) $(ARCHIVE) journal/journal.pdf prez/stage3/stage3.pdf

zip_stage4: clean journal prez
	@$(RM) $(ARCHIVE)
	@$(ZIPJ) $(ARCHIVE) journal/journal.pdf prez/stage4/stage4.pdf
