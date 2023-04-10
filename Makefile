NAME		= cub3D

CC			= gcc
RM			= rm -rf
MKDIR		= mkdir -p

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHT			:=	\033[1;37m
EOC			:=	\033[1;0m

vpath %.c src ./src/build_map ./src/key_hook ./src/raycasting

FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Imlx -lX11 -lXext -lm

MINILIBX_PATH = ./libs/minilibx
MINILIBX = ${MINILIBX_PATH}/libmlx_Linux.a

LIBFT_PATH = ./libs/libft
LIBFT = ${LIBFT_PATH}/libft.a

HEAD = -I./include
SRC =	main.c read_map.c build_map.c extract_content.c check_content.c extract_map.c destroy.c \
		init.c new_parse_map.c check_player.c render.c key_hook.c check_color.c \
		get_player.c moviments.c raycasting.c intersection.c render_3d.c ray_tools.c project_rays.c\
		texture.c \

OBJ_DIR	 =	obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: ${NAME}

${NAME}: ${MINILIBX} $(OBJ) ${OBJ_DIR} ${LIBFT}
		@ $(CC) $(OBJ) ${LIBFT} ${MINILIBX} $(FLAGS) ${MLXFLAGS} -no-pie -o ${NAME}
		@ echo "\e[0;34m"
		@ echo "=========================="
		@ echo "  Compiled successfully!"
		@ echo "=========================="
		@ echo "\033[1;0m"

$(MINILIBX):
		@ make -C ${MINILIBX_PATH}

${LIBFT}:
		@ make -C ${LIBFT_PATH}

$(OBJ_DIR)/%.o: %.c
	@ ${MKDIR} $(OBJ_DIR)
	@ $(CC) $(CFLAGS) $(HEAD) -c $< -o $@

norm:
	@norminette ./src ./include | grep "Error" | cat

clean:
		@ ${RM} ${OBJ_DIR}
		@make clean -C $(MINILIBX_PATH)
		@make clean -C $(LIBFT_PATH)
		@ echo "\e[0;32m  Objects removed. \033[1;0m"

fclean:		clean
			@${RM} ${NAME}
			@ echo " \e[0;32m Program has been cleaned!\033[1;0m"

re:			fclean all

.PHONY: 	all clean fclean re