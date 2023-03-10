/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:15:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/14 00:25:38 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	*init_image_xpm(t_data *data, char *patch)
{
	t_image	*image;

	if (patch == NULL)
		return (NULL);
	if (data == NULL)
		return (NULL);
	if (data->mlx == NULL)
		return (NULL);
	image = NULL;
	image = ft_calloc(sizeof(t_image), 1);
	if (image == NULL)
		return (NULL);
	image->patch = ft_strdup(patch);
	image->pont = mlx_xpm_file_to_image(data->mlx,
			patch, &image->height, &image->width);
	return (image);
}

static t_image	*init_image(void)
{
	t_image	*image;

	image = NULL;
	image = ft_calloc(sizeof(t_image), 1);
	if (image == NULL)
		return (NULL);
	image->width = 0;
	image->height = 0;
	image->pont = NULL;
	image->patch = NULL;
	return (image);
}

t_map	*init_map(char *patch)
{
	t_map	*map;

	map = NULL;
	map = ft_calloc(sizeof(t_map), 1);
	map->patch = NULL;
	if (patch != NULL)
		map->patch = ft_strdup(patch);
	map->map_matrix = NULL;
	map->line = 0;
	map->col = 0;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->cl_floor = NULL;
	map->cl_ceilling = NULL;
	return (map);
}

t_data	*init(char *patch)
{
	t_data	*data;

	data = NULL;
	data = ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		return (NULL);
	data->map = init_map(patch);
	data->image = init_image();
	data->mlx = NULL;
	data->win = NULL;
	data->height = 0;
	data->width = 0;
	data->close_game = 0;
	return (data);
}
