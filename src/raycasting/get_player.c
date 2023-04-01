/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:17:06 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/01 03:38:09 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_angle(t_data *data, int y, int x)
{
	if (data->map->map_matrix[y][x] == 'N')
		data->player->angle = PI / 2;
	if (data->map->map_matrix[y][x] == 'S')
		data->player->angle = (PI * 3) / 2;
	if (data->map->map_matrix[y][x] == 'E')
		data->player->angle = 0;
	if (data->map->map_matrix[y][x] == 'W')
		data->player->angle = PI;
}

void	get_player(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map->map_matrix[y])
	{
		x = 0;
		while (data->map->map_matrix[y][x])
		{
			if (ft_strchr("NSWE", data->map->map_matrix[y][x]))
			{
				data->player->pos_x = x * TILE_SIZE + TILE_SIZE / 2;
				data->player->pos_y = y * TILE_SIZE + TILE_SIZE / 2;
				set_angle(data, y, x);
				data->map->map_matrix[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}
