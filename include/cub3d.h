/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:53 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/05 21:56:16 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"

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
}			t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	t_map	*map;
	int		close_game;
}			t_data;

# define NO 1

/* init.c */
t_image	*init_image(t_data *data, char *patch);
t_map	*init_map(char *patch);
t_data	*init(char *patch);

/* destroy.c */
void	destroy_map(t_map *map);
void	destroy(t_data *data);
void	destroy_image(t_image *image);

/* check.c */
int		check_args(int argc, char **argv);
int		check_texture(char *str, t_map *map);
int		verify_count_rgb(int i);

/*Read map*/
int		read_map(t_data *data);

/*parse_map.c*/
int		parse_map(t_map *map);
void	get_array_map(t_map *map, char *line);
int		check_array_map(t_map *map);
int		check_chars(char *map_line, t_map *map);
int		is_char_valid(char c, int i, char player);

/*get_texture.c*/
void	get_texture(char *str);
void	get_north(char *str, t_map *map);
void	get_south(char *str, t_map *map);
void	get_west(char *str, t_map *map);
void	get_east(char *str, t_map *map);

/* Color.c */
int		color(char *line);
void	check_color(char *line);
int		check_cl_floor(char *line, t_map *map, int i, int j);
int		check_cl_ceilling(char *line, t_map *map, int i, int j);
int		check_char(char *rgb, char c);

#endif /* CUB3D_H */
