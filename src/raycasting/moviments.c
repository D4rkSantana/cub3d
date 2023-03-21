/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:19:43 by jefernan          #+#    #+#             */
/*   Updated: 2023/03/22 00:12:08 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moviments(t_data *data, int key)
{
	if (key == UP)
	{
		data->player->pos_x -= cos(data->player->angle) * MOVE_SPEED;
		data->player->pos_y += sin(data->player->angle) * MOVE_SPEED;
	}
	if (key == DOWN)
	{
		data->player->pos_x += cos(data->player->angle) * MOVE_SPEED;
		data->player->pos_y -= sin(data->player->angle) * MOVE_SPEED;
	}
	if (key == LEFT)
	{
		data->player->pos_x -= sin(data->player->angle) * MOVE_SPEED;
		data->player->pos_y -= cos(data->player->angle) * MOVE_SPEED;
	}
	if (key == RIGHT)
	{
		data->player->pos_x += sin(data->player->angle) * MOVE_SPEED;
		data->player->pos_y += cos(data->player->angle) * MOVE_SPEED;
	}
}

void	rotate(t_data *data, int key)
{
	if (key == KEY_LEFT)
		data->player->angle += PI / 180;
	if (key == KEY_RIGHT)
		data->player->angle -= PI / 180;
}