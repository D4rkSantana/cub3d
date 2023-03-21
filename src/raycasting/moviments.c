/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:19:43 by jefernan          #+#    #+#             */
/*   Updated: 2023/03/21 23:54:35 by esilva-s         ###   ########.fr       */
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
	if (key == LEFT)
		data->player->angle += PI / 180;
	if (key == RIGHT)
		data->player->angle -= PI / 180;
}