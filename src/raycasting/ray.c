/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:07:24 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/26 00:55:58 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ray(t_data *data)
{
	int	dist;

	dist = 0;
	printf("player cords\nX:%f Y%f\nAngle Rad:%f Angle Graus:%f\n",
			data->player->pos_x, data->player->pos_y, data->player->angle, data->player->angle * 180 / PI);
	
	return (dist);
}