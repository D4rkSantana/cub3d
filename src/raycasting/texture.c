/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:17:05 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 16:46:10 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calcule_off_x(t_data *data, t_ray *ray)
{
	int	offset_x;

	if (ray->vertical_wall == 1)
		offset_x = (int)floor(ray->vert->wall_y) % TILE_SIZE;
	else
		offset_x = (int)floor(ray->hrz->wall_x) % TILE_SIZE;
	return (offset_x);
}

int	calcule_off_y(int y, double wall_height, t_ray *ray)
{
	int	offset_y;
	int	distance_top;

	if (wall_height <= 0)
		return (0);
	distance_top = y + (wall_height / 2) - (WIN_HEIGHT / 2);
	offset_y = distance_top * (TILE_SIZE / wall_height);
	return (offset_y);
}
