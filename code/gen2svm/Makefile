.PHONY: all clean

CC = gcc
CFLAGS = -Wall -Wextra -I../utils -g
OBJS = gen2svm.o svm2out.o
TARGET=gen2svm svm2out

all: $(TARGET)

gen2svm: gen2svm.o

svm2out: svm2out.o

clean:
	@$(RM) $(OBJS) $(TARGET)
