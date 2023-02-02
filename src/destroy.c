/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:14:01 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/02 23:32:00 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_map(t_map *map)
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

void	destroy(t_data *data)
{
	if (data == NULL)
		return ;
	destroy_map(data->map);
	free(data);
	data = NULL;
}
