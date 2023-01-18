NAME		= cub3d

CC			= gcc
RM			= rm -rf
MKDIR		= mkdir -p

FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Imlx -lX11 -lXext

MINILIBX_PATH = ./libs/minilibx
MINILIBX = ${MINILIBX_PATH}/libmlx_Linux.a

HEAD = -I cub3d.h
SRC =  main.c check.c ft_strlen.c ft_memcmp.c ft_strrchr.c 

OBG = $(SRC:.c=.o)

all: ${NAME} 


${NAME}: ${MINILIBX} $(OBG)
				$(CC) $(FLAGS) $(OBG) ${MINILIBX} ${MLXFLAGS} -o ${NAME}

$(MINILIBX):
			make -C ${MINILIBX_PATH}

$(OBG): $(SRC) 
	$(CC) $(CFLAGS) $(HEAD) -c $(SRC)

clean:
		${RM} *.o
			

fclean:		clean
			make clean -C $(MINILIBX_PATH)
			${RM} *.o
			${RM} cub3d
			
re:			fclean all

.PHONY: 	all clean fclean re 