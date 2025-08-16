# Compiler
CC = gcc
CFLAGS = -Wall -O2

# Output program name
TARGET = sha256_test

# Source files
SRCS = main.c sha256.c
OBJS = $(SRCS:.c=.o)

# Default build rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET)
