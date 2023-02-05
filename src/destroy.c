/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:14:01 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/05 18:52:02 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_image(t_image *image)
{
	if (image == NULL)
		return ;
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

void	destroy(t_data *data)
{
	if (data == NULL)
		return ;
	destroy_map(data->map);
	destroy_image(data->person->sprite);
	if (data->person != NULL)
		free(data->person);
	free(data);
	data = NULL;
}
