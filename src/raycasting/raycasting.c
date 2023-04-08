/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:54:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/08 03:18:32 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dist_between_points(double x1, double y1, double x2, double y2)
{
	double	ret;

	ret = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return (ret);
}

static void	calc_dist(t_data *data, double ray_angle, t_ray *ray)
{
	if (ray->found_hrz_wall)
		ray->hrz_dist = dist_between_points(data->player->pos_x,
				data->player->pos_y, ray->hrz_wall_x, ray->hrz_wall_y);
	else
		ray->hrz_dist = MAX_INT;
	if (ray->found_vert_wall)
		ray->vert_dist = dist_between_points(data->player->pos_x,
				data->player->pos_y, ray->vert_wall_x, ray->vert_wall_y);
	else
		ray->vert_dist = MAX_INT;
	if (ray->vert_dist < ray->hrz_dist)
	{
		ray->distance = ray->vert_dist * cos(normalize_angle(data->player->angle - ray_angle));
		ray->vertical_wall = 1;
	}
	else
	{
		ray->distance = ray->hrz_dist * cos(normalize_angle(data->player->angle - ray_angle));
		ray->vertical_wall = 0;
	}
		
}

void	raycasting(t_data *data)
{
	double	ray_angle;
	int		column_id;

	ray_angle = normalize_angle(data->player->angle + (FOV_ANGLE / 2));
	column_id = 0;
	while (column_id < NUM_RAYS)
	{
		project_rays(data, ray_angle, &data->rays[column_id]);
		calc_dist(data, ray_angle, &data->rays[column_id]);
		printf("ray[%d][%d] dist:%.2f h[%d]:%.2f v[%d]:%.2f\n", column_id,data->rays[column_id].vertical_wall , data->rays[column_id].distance, data->rays[column_id].found_hrz_wall,data->rays[column_id].hrz_dist, data->rays[column_id].found_vert_wall, data->rays[column_id].vert_dist);
		ray_angle = normalize_angle(ray_angle - FOV_ANGLE / NUM_RAYS);
		column_id++;
	}
	render_3d_projected_walls(data);
}
