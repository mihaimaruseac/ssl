.PHONY: all clean gen svm gen2svm

all: gen2svm svm gen

clean:
	@make --no-print-directory -C gen clean
	@make --no-print-directory -C svm clean
	@make --no-print-directory -C gen2svm clean
	@$(RM) tset*

gen:
	@make --no-print-directory -C gen
	@./train.bash

svm:
	@make --no-print-directory -C svm

gen2svm:
	@make --no-print-directory -C gen2svm
