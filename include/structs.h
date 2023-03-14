/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:10:56 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/14 11:22:41 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_image
{
	int		height;
	int		width;
	char	*patch;
	void	*pont;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data_img;
}	t_image;

typedef struct s_map
{
	char	*patch;
	char	**map_matrix;
	int		line;
	int		col;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*cl_floor;
	char	*cl_ceilling;
}	t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	float	angle;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	int			close_game;
	t_map		*map;
	t_image		*image;
	t_player	*player;
}	t_data;

#endif /* CUB3D_H */
