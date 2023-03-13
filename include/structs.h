/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:10:56 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/14 00:31:52 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_image
{
<<<<<<< HEAD
	int			height;
	int			width;
	char		*patch;
	void		*pont;
=======
	int		height;
	int		width;
	char	*patch;
	void	*pont;
	int		bpp;
    int		size_line;
    int		endian;
	char	*data_img;
>>>>>>> origin/minimap
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

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}		t_player;

typedef struct s_data
{
<<<<<<< HEAD
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	t_map		*map;
	t_image		image;
=======
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	t_map	*map;
	t_image	*image;
>>>>>>> origin/minimap
	t_player	*player;
	int			close_game;
}			t_data;

<<<<<<< HEAD
typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}			t_player;

=======
>>>>>>> origin/minimap
#endif /* CUB3D_H */
