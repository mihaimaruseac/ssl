.PHONY: all clean gen

all: svm gen

clean:
	@make --no-print-directory -C gen clean
	@make --no-print-directory -C svm clean

gen: svm
	@make --no-print-directory -C gen

svm:
	@make --no-print-directory -C svm
