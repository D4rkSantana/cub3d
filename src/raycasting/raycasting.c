/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:54:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/05 23:58:46 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	where_is_looking(double ray_angle, t_ray *ray)
{
	ray->is_facing_up = (ray_angle >= 0 && ray_angle <= PI);
	ray->is_facing_down = !ray->is_facing_up;
	ray->is_facing_right = (ray_angle <= (PI / 2) || ray_angle >= (1.5 * PI));
	ray->is_facing_left = !ray->is_facing_right;
}

void	project_rays(t_data *data, double ray_angle, t_ray *ray)
{
	where_is_looking(ray_angle, ray);
	//intersecção horizontal
	horizontal_intersection(ray_angle, data, ray);
	//intersecção vertical
	vertical_intersection(ray_angle, data, ray);
}

double	dist_between_points(double x1, double y1, double x2, double y2)
{
	double	ret;

	ret = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (ret);	
}

void	calc_dist(t_data *data, double ray_angle, t_ray *ray)
{
	if (ray->found_hrz_wall)
		ray->hrz_dist = dist_between_points(data->player->pos_x,
			data->player->pos_y, ray->hrz_wall_x, ray->hrz_wall_y);
	else
		ray->hrz_dist = MAX_INT;
	if (ray->found_vert_wall)
		ray->vert_dist = dist_between_points(data->player->pos_x,
			data->player->pos_y, ray->vert_wall_x, ray->vert_wall_x);
	else
		ray->vert_dist = MAX_INT;
	// printf("v:%d h:%d\n", ray->found_vert_wall, ray->found_hrz_wall);
	//calculamos a menor distância entre a colisão vertical e horizontal e armazenamos os valores 
	//da menor delas, checando se a colisão foi vertical ou horizontal.
	if (ray->vert_dist < ray->hrz_dist)
	{
		ray->wall_hitx = ray->vert_wall_x;
		ray->wall_hity = ray->vert_wall_y;
		ray->distance = ray->vert_dist;
		ray->was_hit_vert = 1;
	}
	else
	{
		ray->wall_hitx = ray->hrz_wall_x;
		ray->wall_hity = ray->hrz_wall_y;
		ray->distance = ray->hrz_dist;
		ray->was_hit_vert = 0;
	}
	ray->ray_angle = ray_angle;
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
		ray_angle = normalize_angle(ray_angle - FOV_ANGLE / NUM_RAYS);
		column_id++;
	}
	render_3d_projected_walls(data);
}