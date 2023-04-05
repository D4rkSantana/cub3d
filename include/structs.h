/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:10:56 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/05 23:13:52 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_image
{
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
	int		nb_lines;
	int		nb_columns;
	int		height_px;
	int		width_px;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*cl_floor;//retirar
	int		color_floor;
	int		color_sky;
	char	*cl_ceilling;//retirar
}	t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	turn_speed;
	double	angle;
}	t_player;

typedef struct s_ray
{
	double	ray_angle;
	double	hrz_wall_x;
	double	hrz_wall_y;
	int		y_hrz_step;
	int		x_hrz_step;
	int		x_vert_step;
	int		y_vert_step;
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
	double	is_facing_down;
	double	is_facing_up;
	double	is_facing_right;
	double	is_facing_left;
}	t_ray;

typedef struct s_render
{
	double	perp_dist;
	double	dist_proj_plane;
	double	proj_wall_height;
	int		wall_strip_height;
	int		wall_bottom_pixel;
	int		wall_top_pixel;
}	t_render;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			close_game;
	t_render	*render;
	t_map		*map;
	t_image		*image;
	t_player	*player;
	//corrigir para NUM_RAY
	t_ray		rays[320];
}	t_data;

#endif /* CUB3D_H */
