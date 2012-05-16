.PHONY: all clean

CC = gcc
CFLAGS = -Wall -Wextra -I../utils -g
OBJS = gen2svm.o
TARGET=gen2svm

all: $(TARGET)

gen2svm: $(OBJS)

clean:
	@$(RM) $(OBJS) $(TARGET)
