.PHONY: all clean gen

all: gen

clean:
	@$(RM) -r examples

gen:
	@echo -n "Generating images..."
	@./supervised-gen.bash 2000
	@echo "done"
	@echo -ne "Preparing for svm..."
	@./svm-prepare.bash;
	@echo "done"
