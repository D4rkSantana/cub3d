CC = gcc
FLAGS = -Wall -Wextra -Werror
MAIN = main.c
HEAD = cub3d.h
SRC = check.c

all:
	$(CC) $(FLAGS) $(MAIN) $(HEAD) $(SRC)
