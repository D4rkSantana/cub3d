/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:53 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/20 23:43:53 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"
# include "defines.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"

/* init.c */
t_image	*init_image_xpm(t_data *data, char *patch);
//t_image	*init_image(t_data *data);
t_map	*init_map(char *patch);
t_data	*init(char *patch);

int		render_loop(t_data **data);

/* destroy.c */
void	destroy_map(t_map *map);
int		destroy(t_data *data);
void	destroy_image(t_image *image);

/* check_color.c */
int		check_color(char *color);

/* check_content.c */
int		check_contents(char **elements);
int		check_extension(t_map *map);

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

/* minimap.c */
int		draw_minimap(t_data *data, t_image *img);

/* render.c */
void	draw_pixel_color(t_image *img, int x, int y, char *color);
void	render(t_data *data);

/* get_player*/
void	get_player(t_data *data);

#endif /* CUB3D_H */
