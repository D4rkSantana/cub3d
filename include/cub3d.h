/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:53 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/08 01:40:19 by esilva-s         ###   ########.fr       */
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

/* check_color.c */
int	check_color (char *color);

/* check_content.c */
int		check_contents(char **elements);
int		check_extencion(t_map *map);

/* extract_content.c */
void	extract_contents(t_data *data, char **elements);

/* extract_map.c */
int		check_integrity_map(char **elements);
void	extract_map(t_data *data, char **elements);

/* check_player.c */
int		check_player(char **map);
int		check_map(char **map);

/* new_parse_map.c */
int		check_spaces(t_map *map);
int		check_walls(t_map *map);

/*Build map*/
char	**read_map(t_data *data);
int		build_map(t_data *data);

/* key_hook.c*/
int		key_hook(int key, t_data *data);

#endif /* CUB3D_H */
