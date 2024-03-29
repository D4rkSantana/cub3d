NAME		= cub3D

CC			= gcc
RM			= rm -rf
MKDIR		= mkdir -p

vpath %.c src ./src/build_map ./src/key_hook ./src/raycasting

FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Imlx -lX11 -lXext -lm

MINILIBX_PATH = ./libs/minilibx
MINILIBX = ${MINILIBX_PATH}/libmlx_Linux.a

LIBFT_PATH = ./libs/libft
LIBFT = ${LIBFT_PATH}/libft.a

HEAD = -I./include
SRC =	main.c read_map.c build_map.c extract_content.c check_content.c extract_map.c destroy.c \
		init.c init_rays.c new_parse_map.c check_player.c render.c key_hook.c check_color.c \
		get_player.c moviments.c raycasting.c intersection.c render_3d.c ray_tools.c project_rays.c\

OBJ_DIR	 =	obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: ${NAME}

${NAME}: ${MINILIBX} $(OBJ) ${OBJ_DIR} ${LIBFT}
		@ $(CC) $(OBJ) ${LIBFT} ${MINILIBX} $(FLAGS) ${MLXFLAGS} -no-pie -o ${NAME}

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
		@ echo "Objects removed."

fclean:		clean
			@${RM} ${NAME}
			@ echo "Program has been cleaned!"

re:			fclean all

.PHONY: 	all clean fclean re