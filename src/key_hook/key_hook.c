/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:10:19 by jefernan          #+#    #+#             */
/*   Updated: 2023/03/21 01:44:07 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	moviments(t_data *data, int key)
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
	if (key == LEFT)
		data->player->angle += PI / 180;
	if (key == RIGHT)
		data->player->angle -= PI / 180;
}

int	key_hook(int key, t_data *data)
{
	if (key == KEY_W)
		moviments(data, UP);
	if (key == KEY_S)
		moviments(data, DOWN);
	if (key == KEY_A)
		moviments(data, LEFT);
	if (key == KEY_D)
		moviments(data, RIGHT);
	if (key == KEY_LEFT)
		rotate(data, LEFT);
	if (key == KEY_RIGHT)
		rotate(data, RIGHT);
	if (key == KEY_ESC || key == KEY_Q)
		destroy(data);
	return (0);
}
