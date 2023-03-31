/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:10:56 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/31 01:35:22 by esilva-s         ###   ########.fr       */
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
	double	turn_speed;
	float	angle;
}	t_player;

typedef struct s_ray
{
	double	ray_angle;
	double	hrz_wall_x;
	double	hrz_wall_y;
	double	y_hrz_step;
	double	x_hrz_step;
	double	x_vert_step;
	double	y_vert_step;
	double	vert_wall_x;
	double	vert_wall_y;
	double	hrz_dist;
	double	vert_dist;
	double	wall_hitx;
	double	wall_hity;
	double	distance;
	int		was_hit_vert;
	int		found_vert_wall;
	int		found_hrz_wall;
	int		is_facing_down;
	int		is_facing_up;
	int		is_facing_right;
	int		is_facing_left;
}	t_ray;

typedef struct s_render
{
	double	correct_wall_dist;
	double	dist_proj_plane;
	double	wall_stripe_height;
}	t_render;

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
	//corrigir para NUM_RAY
	t_ray		rays[320];
}	t_data;

#endif /* CUB3D_H */
