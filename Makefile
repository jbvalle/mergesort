CC=gcc

CFLAGS=-g -Wall -Wextra -pedantic -O0

SRCS=$(wildcard *.c)

BINS=$(SRCS:%.c=%)

TARGET=main


all: clean $(TARGET) run


$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

run:
	./$(TARGET)

debug: $(SRCS)
	ulimit -c unlimited
	$(CC) $(CFLAGS) -o $(TARGET) $^ -lm
	gdb $(TARGET) core

clean:
	rm -rf $(TARGET) *.o .*swo .*swp



