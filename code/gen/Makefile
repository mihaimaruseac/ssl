NUM_EXAMPLES = 1000
.PHONY: all clean gen

all: gen

clean:
	@$(RM) -r examples

gen:
	@echo -n "Generating images..."
	@./supervised-gen.bash $(NUM_EXAMPLES)
	@echo "done"
	@echo -ne "Preparing for svm..."
	@./svm-prepare.bash;
	@echo "done"
