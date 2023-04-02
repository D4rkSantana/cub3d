/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:11:14 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/02 22:50:37 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_collision(double x, double y, t_data *data)
{
	int	i;
	int	j;

	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE);
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return (-1);
	if (data->map->map_matrix[i][j] == '1')
		return (1);
	else
		return (0);
}

void	horizontal_intersection(double ray_angle, t_data *data, t_ray *ray)
{
	int	intercep_x;
	int	intercep_y;
	
	if (ray->is_facing_down)
	{
		intercep_y = floor(data->player->pos_y / TILE_SIZE) * TILE_SIZE + 64;
		intercep_x = data->player->pos_x + ((data->player->pos_y - intercep_y) / tan(ray_angle));
		ray->y_hrz_step = TILE_SIZE;
		ray->x_hrz_step = TILE_SIZE / tan(ray_angle);
		/*
		if (ray->is_facing_left && ray->x_hrz_step > 0)
			ray->x_hrz_step *= -1;
		if (ray->is_facing_right && ray->x_hrz_step < 0)
			ray->x_hrz_step *= -1;
		*/

		
	}
	else if (ray->is_facing_up)
	{
		intercep_y = floor(data->player->pos_y / TILE_SIZE) * TILE_SIZE - 1;
		intercep_x = data->player->pos_x + ((data->player->pos_y - intercep_y) / tan(ray_angle));
		ray->y_hrz_step = TILE_SIZE;
		ray->x_hrz_step = TILE_SIZE / tan(ray_angle);
	
		// if (ray->is_facing_up)
		// 	ray->y_hrz_step *= -1;
		// if (ray->is_facing_left && ray->x_hrz_step > 0)
		// 	ray->x_hrz_step *= -1;
		// if (ray->is_facing_right && ray->x_hrz_step < 0)
		// 	ray->x_hrz_step *= -1;

	}
	// printf("interx:%d intery:%d\n", intercep_x, intercep_y);
	while (intercep_x >= 0 && intercep_x < (WIN_HEIGHT * TILE_SIZE) && intercep_y >= 0 && intercep_y < (WIN_WIDTH * TILE_SIZE))
	{
		if (wall_collision(intercep_x, intercep_y, data) == 1)
		{
			//encontrou parede -> ponto de colisão - hrz_wall_x - y
			ray->hrz_wall_x = intercep_x;
			ray->hrz_wall_y = intercep_y;
			ray->found_hrz_wall = 1;//encontrou a parede
			printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
			break ;
		}
		if (wall_collision(intercep_x, intercep_y, data) == -1)
			break ;
		intercep_x += ray->x_hrz_step;
		intercep_y += ray->y_hrz_step;
	}
}

void	vertical_intersection(double ray_angle, t_data *data, t_ray *ray)
{
	int	intercep_x;
	int	intercep_y;

	if (ray->is_facing_right)
	{
		intercep_x = floor(data->player->pos_x / TILE_SIZE) * TILE_SIZE + 64;
		intercep_y = data->player->pos_y + (data->player->pos_x - intercep_x) * tan(ray_angle);
		ray->x_vert_step = TILE_SIZE;
		ray->y_vert_step = TILE_SIZE * tan(ray_angle);
	}
	else if (ray->is_facing_left)
	{
		intercep_x = floor(data->player->pos_x / TILE_SIZE) * TILE_SIZE - 1;
		intercep_y = data->player->pos_y + (data->player->pos_x - intercep_x) * tan(ray_angle);
		ray->x_vert_step = TILE_SIZE;
		ray->y_vert_step = TILE_SIZE * tan(ray_angle);
	}


	//se left -> inverter o xstep para negativo para voltar e não ir para frente no grid.
	// if (ray->is_facing_left)
	// 	ray->x_vert_step *= -1;
	
	// if (ray->is_facing_up && ray->y_vert_step > 0)
	// 	ray->y_vert_step *= -1;
	// if (ray->is_facing_down && ray->y_vert_step < 0)
	// 	ray->y_vert_step *= -1;

	while (intercep_x >= 0 && intercep_x < (WIN_HEIGHT * TILE_SIZE) &&
			intercep_y >= 0 && intercep_y < (WIN_WIDTH * TILE_SIZE))
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