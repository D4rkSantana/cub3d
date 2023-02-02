/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:53 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/02 00:21:55 by jefernan         ###   ########.fr       */
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
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}			t_map;

# define NO 1

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
int		check_color(char *line);
int		check_cl_floor(char *line, t_map *map, int i, int j);
int 	check_cl_ceilling(char *line, t_map *map, int i, int j);

void	test_mlx(void);

#endif /* CUB3D_H */
