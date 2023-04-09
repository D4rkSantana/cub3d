/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:15:07 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/09 20:25:04 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_sky(t_data *data, t_ray *ray, int x)
{
	int	y;

	y = 0;
	while (y < ray->render->wall_top_pixel)
	{
		draw_pixel_color(data->image, x, y, data->map->color_sky);
		y++;
	}
}

static void	draw_wall(t_data *data,t_ray *ray, int x)
{
	int	y;
	int	off_y;
	int	off_x;

	y = ray->render->wall_top_pixel;
	off_x = calcule_off_x(data, ray);
	while (y < ray->render->wall_bottom_pixel)
	{
		off_y = calcule_off_y(y - ray->render->wall_top_pixel, ray->render->proj_wall_height, ray);
		//printf("x:%d y:%d\n", off_x, off_y);
		if (ray->is_facing_up == 1)
		{
			if (ray->vertical_wall == 0)
				draw_pixel_color(data->image, x, y, copycolor(data->n_texture, off_x, off_y)); //NORTE
			else 
			{
				if (ray->is_facing_right == 1)
					draw_pixel_color(data->image, x, y, copycolor(data->e_texture, off_x, off_y));//LESTE
				else
					draw_pixel_color(data->image, x, y, copycolor(data->w_texture, off_x, off_y)); //OESTE
			}
		}
		else
		{
			if (ray->vertical_wall == 0)
				draw_pixel_color(data->image, x, y, copycolor(data->s_texture, off_x, off_y)); //SUL
			else 
			{
				if (ray->is_facing_right == 0)
					draw_pixel_color(data->image, x, y, copycolor(data->w_texture, off_x, off_y));//Oeste
				else
					draw_pixel_color(data->image, x, y, copycolor(data->e_texture, off_x, off_y)); //LESTE
			}
		}
		y++;
	}
}

static void	draw_bottom(t_data *data, t_ray *ray, int x)
{
	int	y;

	y = ray->render->wall_bottom_pixel;
	while (y < WIN_HEIGHT)
	{
		draw_pixel_color(data->image, x, y, data->map->color_floor);
		y++;
	}
}

static void	calcule_columns(t_data *data, t_ray *ray, int x)
{
	ray->render->wall_top_pixel = (WIN_HEIGHT / 2) - (ray->render->proj_wall_height / 2);
	
	if (ray->render->wall_top_pixel < 0)
		ray->render->wall_top_pixel = 0;

	ray->render->wall_bottom_pixel = (WIN_HEIGHT / 2) + (ray->render->proj_wall_height / 2);

	if (ray->render->wall_bottom_pixel > WIN_HEIGHT)
		ray->render->wall_bottom_pixel = WIN_HEIGHT;
}

void	render_3d_projected_walls(t_data *data)
{
	int		x;
	int		y;
	t_ray	*ray;

	x = 0;
	while (x < NUM_RAYS)
	{
		ray = &data->rays[x];
		// ray->render->perp_dist = ; RETIRAR DA STRUCT
		//ray->render->proj_wall_height = TILE_SIZE * WIN_HEIGHT / data->rays[x].distance;
		//if (ray->render->proj_wall_height > WIN_HEIGHT)
		//	ray->render->proj_wall_height = WIN_HEIGHT;
		ray->render->proj_wall_height = (TILE_SIZE / ray->distance) * data->dist_proj_plane;
		ray->render->wall_strip_height = (int)ray->render->proj_wall_height;
		//data->rays[x].wall_strip_height = (int)ray->render->proj_wall_height;
		calcule_columns(data,ray, x);
		draw_sky(data,ray, x);
		draw_wall(data,ray, x);
		draw_bottom(data,ray, x);
		x++;
	}
}
