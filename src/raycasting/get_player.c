/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:17:06 by jefernan          #+#    #+#             */
/*   Updated: 2023/03/10 19:20:11 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map_matrix[i])
	{
		j = 0;
		while (data->map->map_matrix[i][j])
		{
			if (data->map->map_matrix[i][j] == 'N' || data->map->map_matrix[i][j] == 'S'
				|| data->map->map_matrix[i][j] == 'E' || data->map->map_matrix[i][j] == 'W')
				init_player(data, j, i);
			j++;
		}
		i++;
	}
}

void	init_player(t_data *data, int x, int y)
{
	data->player->pos_x = x;
	data->player->pos_y = y;
	if (data->map->map_matrix[y][x] == 'N')
		set_value(0, -1, 0.66, 0);
	if (data->map->map_matrix[y][x] == 'S')
		set_value(0, 1, -0.66, 0);
	if (data->map->map_matrix[y][x] == 'E')
		set_value(1, 0, 0, 0.66);
	if (data->map->map_matrix[y][x] == 'W')
		set_value(-1, 0, 0, -0.66);
}

void	set_value(double dir_x, double dir_y, double pl_x, double pl_y)
{
	t_player	*player;

	player->dir_x = dir_x;
	player->dir_y = dir_y;
	player->plane_x = pl_x;
	player->plane_y = pl_y;
}
