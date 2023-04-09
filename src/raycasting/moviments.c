/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:19:43 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/10 00:35:33 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moviments_up_down(t_data *data, int key)
{
	double	new_x;
	double	new_y;

	if (key == UP)
	{
		//new_y = data->player->pos_y - 10;
		new_x = data->player->pos_x + cos(data->player->angle) * MOVE_SPEED;
		new_y = data->player->pos_y - sin(data->player->angle) * MOVE_SPEED;
	}
	if (key == DOWN)
	{
		//new_y = data->player->pos_y + 10;
		new_x = data->player->pos_x - cos(data->player->angle) * MOVE_SPEED;
		new_y = data->player->pos_y + sin(data->player->angle) * MOVE_SPEED;
	}
	//new_x = data->player->pos_x;
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
		//new_x = data->player->pos_x - 10;
		new_x = data->player->pos_x - sin(data->player->angle) * MOVE_SPEED;
		new_y = data->player->pos_y - cos(data->player->angle) * MOVE_SPEED;
	}
	if (key == RIGHT)
	{
		//new_x = data->player->pos_x + 10;
		new_x = data->player->pos_x + sin(data->player->angle) * MOVE_SPEED;
		new_y = data->player->pos_y + cos(data->player->angle) * MOVE_SPEED;
	}
	//new_y = data->player->pos_y;
	if (check_player_position(data, new_x, new_y) != 1)
	{
		data->player->pos_x = new_x;
		data->player->pos_y = new_y;
	}
}

void	rotate(t_data *data, int key)
{
	if (key == KEY_LEFT)
		data->player->angle = normalize_angle(data->player->angle + (MOVE_SPEED * (PI / 180)));
	if (key == KEY_RIGHT)
		data->player->angle = normalize_angle(data->player->angle - (MOVE_SPEED * (PI / 180)));
}

int	check_player_position(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x / TILE_SIZE;
	map_y = (int)y / TILE_SIZE;
	if (data->map->map_matrix[map_y][map_x] == '1'
		|| data->map->map_matrix[map_y][map_x] == ' ')
		return (1);
	return (0);
}
