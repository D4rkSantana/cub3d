/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:53 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/02 23:56:08 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"

# define NO 1
# define KEY_ESC 65307
# define KEY_Q 113
# define KEY_PRESS 2
# define DESTROY_NOTIFY 17

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define PI 3.14159265

typedef struct s_image
{
	int		height;
	int		width;
	char	*patch;
	void	*pont;
}				t_image;

typedef struct s_map
{
	char	*patch;
	char	**map_matrix;
	int		line;
	int		col;
	int		player;
	int		check_color;
	int		check_texture;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*cl_floor;
	char	*cl_ceilling;
}			t_map;

/*
typedef struct s_map
{
	char	*patch;
	char	**elements;
	char	*map_array;
	int		line;
	int		col;
	int		player;
	int		check_color;
	int		check_texture;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*cl_floor;
	char	*cl_ceilling;
}			t_map;
*/


typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	t_map	*map;
	t_image	image;
	int		close_game;
}			t_data;

/* init.c */
t_image	*init_image(t_data *data, char *patch);
t_map	*init_map(char *patch);
t_data	*init(char *patch);

/* destroy.c */
void	destroy_map(t_map *map);
int		destroy(t_data *data);
void	destroy_image(t_image *image);

/* check.c */
int		check_args(int argc, char **argv);
int		check_texture(char *str, t_map *map);
int		verify_count_rgb(int i);

/*Build map*/
char	**read_map(t_data *data);
int	build_map(t_data *data);

/*parse_map.c*/
int		parse_map(t_map *map);
void	get_array_map(t_map *map, char *line);
int		check_line_map(t_map *map, char *map_line);
int		check_player(char *map_line, t_map *map);
int		is_char_valid(char c, char player);

/*get_texture.c*/
void	get_texture(char *str, t_map *map);
void	get_north(char *str, t_map *map);
void	get_south(char *str, t_map *map);
void	get_west(char *str, t_map *map);
void	get_east(char *str, t_map *map);

/* Color.c */
int		color(char *line, t_map *map);
void	check_color(char *line, t_map *map);
void	check_cl_floor(char *line, t_map *map, int i, int j);
void	check_cl_ceilling(char *line, t_map *map, int i, int j);
int		check_char(char *rgb, char c);

/* utils.c*/
void	get_color_floor(char *color, t_map *map);
void	get_color_ceilling(char *color, t_map *map);
int		check_quantity(t_map *map);

/* key_hook.c*/
int		key_hook(int key, t_data *data);

#endif /* CUB3D_H */
