/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:14:01 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/14 23:14:16 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_image(t_image *image)
{
	ft_strdel(&image->patch);
	free (image);
}

void	destroy_map(t_map *map)
{
	if (map == NULL)
		return ;
	ft_strdel(&map->patch);
	ft_strdel(&map->no_path);
	ft_strdel(&map->so_path);
	ft_strdel(&map->we_path);
	ft_strdel(&map->ea_path);
	ft_strdel(&map->cl_floor);
	ft_strdel(&map->cl_ceilling);
	ft_matrix_strdel(map->map_matrix);
	free(map);
	map = NULL;
}

int	destroy(t_data *data)
{
	if (data == NULL)
		return (1);
	destroy_map(data->map);
	if (data->image->pont)
		mlx_destroy_image(data->mlx, data->image->pont);
	if (data->image)
		free (data->image);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free (data->mlx);
	}
	free(data);
	data = NULL;
	exit (0);
	return (0);
}
