PROJ_NAME=main

CC = gcc
CFLAGS = -ggdb -O0 -std=c99 -fstack-protector-all -Werror=implicit-function-declaration
LDFLAGS=-O0 -g

SRCDIR = ./sorts ./princ

SRC = $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.c))

OBJ = $(SRC:.c=.o)

EXEC = main

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)