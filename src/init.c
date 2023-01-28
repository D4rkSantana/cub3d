/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:15:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/01/28 19:54:04 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map *init_map(char *patch)
{
	t_map	*map;
	
	map = NULL;
	map = ft_calloc(sizeof(t_map), 1);
	map->patch = NULL;
	map->patch = ft_strdup(patch);
	map->elements = NULL;
	map->height = 0;
	map->col = 0;
	map->player = 0;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
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
	data->mlx = NULL;
	data->win = NULL;
	data->image = NULL;
	data->close_game = 0;
	return (data);
}