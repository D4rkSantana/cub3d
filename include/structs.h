/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:10:56 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/09 00:12:50 by esilva-s         ###   ########.fr       */
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

#endif /* CUB3D_H */
