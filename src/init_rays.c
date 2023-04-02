/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:34:26 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/02 14:50:22 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vertical(int index, t_data *data)
{
	data->rays[index].y_hrz_step = 0;
	data->rays[index].x_hrz_step = 0;
	data->rays[index].hrz_wall_x = 0;
	data->rays[index].hrz_wall_y = 0;
	data->rays[index].hrz_dist = 0;
	data->rays[index].found_hrz_wall = 0;
}

void	horizontal(int index, t_data *data)
{
	data->rays[index].x_vert_step = 0;
	data->rays[index].y_vert_step = 0;
	data->rays[index].vert_wall_x = 0;
	data->rays[index].vert_wall_y = 0;
	data->rays[index].vert_dist = 0;
	data->rays[index].found_vert_wall = 0;
}

void	init_rays(t_data *data)
{
	int	index;

	index = 0;
	while (index < NUM_RAYS)
	{
		data->rays[index].ray_angle = 0;
		data->rays[index].wall_hitx = 0;
		data->rays[index].wall_hity = 0;
		data->rays[index].distance = 0;
		data->rays[index].was_hit_vert = 0;
		data->rays[index].is_facing_down = 0;
		data->rays[index].is_facing_up = 0;
		data->rays[index].is_facing_right = 0;
		data->rays[index].is_facing_left = 0;
		vertical(index, data);
		horizontal(index, data);
		index++;
	}
}
