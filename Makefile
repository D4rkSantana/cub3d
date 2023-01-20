NAME = cub3d
CC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werro
LIBS = ./libft/libft.a
SRC = main.c check.c read_map.c
INCLUDES = -I cub3d.h

OBG = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBG) ./libft/libft.a
	$(CC) $(CFLAGS) $(OBG) $(LIBS) $(INCLUDES) 

$(OBG): $(SRC) 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC)

./libft/libft.a:
	@make -C libft

clean:
	@make clean -C libft
	$(RM) *.o

fclean:
	@make fclean -C libft
	$(RM) *.o
	$(RM) cub3d
	$(RM) a.out

re: fclean all

cclean: all clean
	clear