.PHONY: all clean gen

all: svm gen gen2svm

clean:
	@make --no-print-directory -C gen clean
	@make --no-print-directory -C svm clean
	@make --no-print-directory -C gen2svm clean

gen: svm gen2svm
	@make --no-print-directory -C gen

svm:
	@make --no-print-directory -C svm

gen2svm:
	@make --no-print-directory -C gen2svm
