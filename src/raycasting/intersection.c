/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:11:14 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/07 03:04:31 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_collision(double x, double y, t_data *data)
{
	int	i;
	int	j;

	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE);

	if (x >= data->map->width_px || y >= data->map->height_px)
		return (-1);
	if (x < 0 || i >= data->map->nb_columns || y < 0 || j >= data->map->nb_lines)
		return (-1);
	if (data->map->map_matrix[j][i] == '1')
		return (1);
	else
		return (0);
}

static void	search_hrz_wall(double x, double y, t_data *data, t_ray *ray)
{
	double	intercep_x;
	double	intercep_y;

	intercep_x = x;
	intercep_y = y;
	while (intercep_x < data->map->width_px && intercep_y < data->map->height_px)
	{
		if (wall_collision(intercep_x, intercep_y, data) == 1)
		{
			ray->hrz_wall_x = intercep_x;
			ray->hrz_wall_y = intercep_y;
			ray->found_hrz_wall = 1;
			break ;
		}
		if (wall_collision(intercep_x, intercep_y, data) == -1)
			break ;
		intercep_x += ray->x_hrz_step;
		intercep_y += ray->y_hrz_step;
	}
}

static void	search_vert_wall(double x, double y, t_data *data, t_ray *ray)
{
	double	intercep_x;
	double	intercep_y;

	intercep_x = x;
	intercep_y = y;
	while (intercep_x < data->map->width_px
		&& intercep_y < data->map->height_px)
	{
		if (wall_collision(intercep_x, intercep_y, data) == 1)
		{
			ray->vert_wall_x = intercep_x;
			ray->vert_wall_y = intercep_y;
			ray->found_vert_wall = 1;
			break ;
		}
		if (wall_collision(intercep_x, intercep_y, data) == -1)
			break ;
		intercep_x += ray->x_vert_step;
		intercep_y += ray->y_vert_step;
	}
}

void	horizontal_intersection(double ray_angle, t_data *data, t_ray *ray)
{
	double	intercep_x;
	double	intercep_y;

	if (ray->is_facing_down)
	{
		intercep_y = floor(data->player->pos_y / TILE_SIZE) * TILE_SIZE + 64;
		ray->y_hrz_step = TILE_SIZE;
	}
	else if (ray->is_facing_up)
	{
		intercep_y = floor(data->player->pos_y / TILE_SIZE) * TILE_SIZE -1;
		ray->y_hrz_step = TILE_SIZE * -1;
	}
	intercep_x = data->player->pos_x + (data->player->pos_y - intercep_y) / tan(ray_angle);
	ray->x_hrz_step = TILE_SIZE / tan(ray_angle);
	search_hrz_wall(intercep_x, intercep_y, data, ray);
}

void	vertical_intersection(double ray_angle, t_data *data, t_ray *ray)
{
	double	intercep_x;
	double	intercep_y;

	if (ray->is_facing_right)
	{
		intercep_x = floor(data->player->pos_x / TILE_SIZE) * TILE_SIZE + 64;
		ray->x_vert_step = TILE_SIZE;
	}
	else if (ray->is_facing_left)
	{
		intercep_x = floor(data->player->pos_x / TILE_SIZE) * TILE_SIZE - 1;
		ray->x_vert_step = TILE_SIZE * -1;
	}
	intercep_y = data->player->pos_y + (data->player->pos_x - intercep_x)
		* tan(ray_angle);
	ray->y_vert_step = TILE_SIZE * tan(ray_angle);
	search_vert_wall(intercep_x, intercep_y, data, ray);
}
