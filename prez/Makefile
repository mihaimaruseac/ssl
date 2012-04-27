.PHONY: all clean stage1 stage2 stage3 stage4

all: stage1 stage2 stage3 stage4

stage1:
	@make --no-print-directory -C stage1

stage2:
	@make --no-print-directory -C stage2

stage3:
	@make --no-print-directory -C stage3

stage4:
	@make --no-print-directory -C stage4

clean:
	@make --no-print-directory -C stage1 clean
	@make --no-print-directory -C stage2 clean
	@make --no-print-directory -C stage3 clean
	@make --no-print-directory -C stage4 clean


