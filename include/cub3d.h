/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:53 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/05 18:04:08 by esilva-s         ###   ########.fr       */
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

typedef struct s_map
{
	char	*patch;
	char	**elements;
	char	*map_array;
	int		height;
	int		col;
	int		player;
	int		check_color;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}			t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*image;
	int		h_teste;
	int		w_teste;
	t_map	*map;
	int		close_game;
}			t_data;

# define NO 1

/* init.c */
t_map	*init_map(char *patch);
t_data	*init(char *patch);

/* destroy.c */
void	destroy_map(t_map *map);
void	destroy(t_data *data);

/* check.c */
int		check_args(int argc, char **argv);

/*Read map*/
int		read_map(t_map *map);

/*parse_map.c*/
int		parse_map(t_map *map);
int		check_texture(char *str, t_map *map);
int		check_walls(t_map *map);
int		check_chars(t_map *map);
int		is_char_valid(t_map *map, int i, int j, char player);
void	get_array_map(t_map *map, char *line);

/*get_texture.c*/
void	get_texture(char *str);

void	get_north(char *str, t_map *map);
void	get_south(char *str, t_map *map);
void	get_west(char *str, t_map *map);
void	get_east(char *str, t_map *map);

/* Color.c */
int		color(char *line);
void	check_color(char *line);
int		verify_count_rgb(int i);
int		check_char(char *rgb, char c);
int		check_cl_floor(char *line, t_map *map, int i, int j);
int		check_cl_ceilling(char *line, t_map *map, int i, int j);

void	test_mlx(void);

#endif /* CUB3D_H */
