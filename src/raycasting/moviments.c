/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:19:43 by jefernan          #+#    #+#             */
/*   Updated: 2023/03/30 01:07:27 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moviments_up_down(t_data *data, int key)
{
	double	new_x;
	double	new_y;

	if (key == UP)
	{
		new_x = data->player->pos_x - sin(data->player->angle) * MOVE_SPEED;
		new_y = data->player->pos_y - cos(data->player->angle) * MOVE_SPEED;
	}
	if (key == DOWN)
	{
		new_x = data->player->pos_x + sin(data->player->angle) * MOVE_SPEED;
		new_y = data->player->pos_y + cos(data->player->angle) * MOVE_SPEED;
	}
	if (check_player_position(data, new_x, new_y) != 1)
	{
		data->player->pos_x = new_x;
		data->player->pos_y = new_y;
	}
}

void	moviments_left_right(t_data *data, int key)
{
	double	new_x;
	double	new_y;

	if (key == LEFT)
	{
		new_x = data->player->pos_x - cos(data->player->angle) * MOVE_SPEED;
		new_y = data->player->pos_y + sin(data->player->angle) * MOVE_SPEED;
	}
	if (key == RIGHT)
	{
		new_x = data->player->pos_x + cos(data->player->angle) * MOVE_SPEED;
		new_y = data->player->pos_y - sin(data->player->angle) * MOVE_SPEED;
	}
	if (check_player_position(data, new_x, new_y) != 1)
	{
		data->player->pos_x = new_x;
		data->player->pos_y = new_y;
	}
}

void	rotate(t_data *data, int key)
{
	float	new_angle;

	if (key == KEY_LEFT)
	{
		new_angle = data->player->angle + PI / 180;
		if (new_angle > 360)
			new_angle = 0;
		data->player->angle = new_angle;
	}
	if (key == KEY_RIGHT)
	{
		new_angle = data->player->angle - PI / 180;
		if (new_angle < 0)
			new_angle = 2 * PI;
		data->player->angle = new_angle;
	}	
}

int	check_player_position(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (data->map->map_matrix[map_y][map_x] == '1')
		return (1);
	return (0);
}
