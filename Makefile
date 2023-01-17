CC = gcc
FLAGS = -Wall -Wextra -Werro
MAIN = main.c
HEAD = cub3d.h
SRC = check.c ft_strlen.c ft_memcmp.c ft_strrchr.c

all:
	$(CC) $(FLAGS) $(MAIN) $(HEAD) $(SRC)
