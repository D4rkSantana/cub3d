/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:17:06 by jefernan          #+#    #+#             */
/*   Updated: 2023/03/14 11:15:29 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player(t_data *data)
{
	int	i;
	int	j;

	y = 0;
	while (data->map->map_matrix[y])
	{
		x = 0;
		while (data->map->map_matrix[y][x])
		{
			if (ft_strchr("NSWE", data->map.map[y][x]))
			{
				data->player->pos_x = x * SPRITE + SPRITE / 2;
				data->player->pos_y = y * SPRITE + SPRITE / 2;
			}
			if (data->map->map_matrix[y][x] == 'N')
				data->player->angle = PI / 2;
			if (data->map->map_matrix[y][x] == 'S')
				data->player->angle = (PI * 3) / 2;
			if (data->map->map_matrix[y][x] == 'E')
				data->player->angle = 0;
			if (data->map->map_matrix[y][x] == 'W')
				data->player->angle = PI;
			x++;
		}
		y++;
	}
}
