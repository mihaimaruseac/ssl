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

prez1:
	@make --no-print-directory -C prez stage1

prez2:
	@make --no-print-directory -C prez stage2

prez3:
	@make --no-print-directory -C prez stage3

prez4:
	@make --no-print-directory -C prez stage4

code:
	@make --no-print-directory -C code

clean:
	@make --no-print-directory -C journal clean
	@make --no-print-directory -C prez clean
	@make --no-print-directory -C code clean

dist: clean
	@$(RM) $(ARCHIVE)
	@$(ZIP) $(ARCHIVE) *

zip_stage1: clean journal prez1
	@$(RM) $(ARCHIVE)
	@$(ZIPJ) $(ARCHIVE) journal/journal.pdf prez/stage1/stage1.pdf

zip_stage2: clean journal prez2
	@$(RM) $(ARCHIVE)
	@$(ZIPJ) $(ARCHIVE) journal/journal.pdf prez/stage2/stage2.pdf

zip_stage3: clean journal prez3
	@$(RM) $(ARCHIVE)
	@$(ZIPJ) $(ARCHIVE) journal/journal.pdf prez/stage3/stage3.pdf

zip_stage4: clean journal prez4
	@$(RM) $(ARCHIVE)
	@$(ZIPJ) $(ARCHIVE) journal/journal.pdf prez/stage4/stage4.pdf
