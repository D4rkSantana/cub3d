NAME = cub3d
CC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werro
LIBS = -I ./libft/libft.a
SRC = main.c check.c read_map.c

OBG = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBG)

$(OBG): $(SRC) ./libft/libft.a
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

re: fclean all

cclean: all clean
	clear