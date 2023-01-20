NAME		= cub3d

CC			= gcc
RM			= rm -rf
MKDIR		= mkdir -p

vpath %.c src

FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Imlx -lX11 -lXext

MINILIBX_PATH = ./libs/minilibx
MINILIBX = ${MINILIBX_PATH}/libmlx_Linux.a

HEAD = -I./include
SRC =  main.c check.c ft_strlen.c ft_memcmp.c ft_strrchr.c 

OBJ_DIR	 =	obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: ${NAME} 

${NAME}: ${MINILIBX} $(OBJ) ${OBJ_DIR}
		@ $(CC) $(FLAGS) $(OBJ) ${MINILIBX} ${MLXFLAGS} -o ${NAME}

$(MINILIBX):
		@ make -C ${MINILIBX_PATH}

$(OBJ_DIR)/%.o: %.c
	@ ${MKDIR} $(OBJ_DIR)
	@ $(CC) $(CFLAGS) $(HEAD) -c $< -o $@

norm:
	@norminette ./src ./include | grep "Error" | cat

clean:
		@ ${RM} ${OBJ_DIR}
		@ echo "Objects removed."


fclean:		clean
			@make clean -C $(MINILIBX_PATH)
			@${RM} ${NAME}
			@ echo "Program has been cleaned!"
			
re:			fclean all

.PHONY: 	all clean fclean re 