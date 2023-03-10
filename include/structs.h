/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:10:56 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/09 20:59:42 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_image
{
	int			height;
	int			width;
	char		*patch;
	void		*pont;
}				t_image;

typedef struct s_map
{
	char		*patch;
	char		**map_matrix;
	int			line;
	int			col;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*cl_floor;
	char		*cl_ceilling;
}			t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	t_map		*map;
	t_image		image;
	t_player	*player;
	int			close_game;
}			t_data;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}			t_player;

#endif /* CUB3D_H */
