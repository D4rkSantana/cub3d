/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:14:01 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/08 17:50:54 by jefernan         ###   ########.fr       */
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
	ft_strdel(&map->map_array);
	ft_matrix_strdel(map->elements);
	free(map);
	map = NULL;
}

int	destroy(t_data *data)
{
	if (data == NULL)
		return (1);
	// mlx_destroy_image(data->mlx, data->image.pont);
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	destroy_map(data->map);
	free(data);
	data = NULL;
	exit (0);
	return (0);
}
