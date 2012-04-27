PDF = $(addsuffix .pdf, $(BASENAME))
TEX = $(addsuffix .tex, $(BASENAME))
PDFLATEX = pdflatex
BIBTEX = bibtex
OUT_DIR = texfiles
STY_DIR = template

.PHONY: clean all $(PDF)

all: $(PDF)

$(PDF): $(TEX)
	@test -d $(OUT_DIR) || mkdir $(OUT_DIR)
	@TEXINPUTS=$(STY_DIR)//: $(PDFLATEX) -output-directory $(OUT_DIR) $<
	@$(BIBTEX) $(OUT_DIR)/$(BASENAME)
	@TEXINPUTS=$(STY_DIR)//: $(PDFLATEX) -output-directory $(OUT_DIR) $<
	@TEXINPUTS=$(STY_DIR)//: $(PDFLATEX) -output-directory $(OUT_DIR) $<
	@test -h $(PDF) || ln -s $(OUT_DIR)/$(PDF) .

clean:
	@$(RM) -r $(OUT_DIR)
	@$(RM) $(PDF)

