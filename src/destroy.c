/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:14:01 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/14 01:28:00 by esilva-s         ###   ########.fr       */
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
	ft_matrix_strdel(map->map_matrix);
	free(map);
	map = NULL;
}

int	destroy(t_data *data)
{
	if (data == NULL)
		return (1);
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->image->pont)
	{
		mlx_destroy_image(data->mlx, data->image->pont);
		ft_strdel(&data->image->patch);
		free (data->image);
	}
	destroy_map(data->map);
	free(data);
	data = NULL;
	exit (0);
	return (0);
}
