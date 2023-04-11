/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:15:07 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 16:53:44 by jefernan         ###   ########.fr       */
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

static void	draw_wall(t_data *data, t_ray *ray, int x)
{
	int	y;
	int	off_y;
	int	off_x;

	y = ray->render->wall_top_pixel;
	off_x = calculate_off_x(data, ray);
	while (y < ray->render->wall_bottom_pixel)
	{
		off_y = calculate_off_y(y, ray->render->proj_wall_height, ray);
		if (ray->is_facing_up == 1)
		{
			if (ray->vertical_wall == 0)
				draw_pixel_color(data->image, x, y,
					copycolor(data->n_texture, off_x, off_y));
			else
			{
				if (ray->is_facing_right == 1)
					draw_pixel_color(data->image, x, y,
						copycolor(data->e_texture, off_x, off_y));
				else
					draw_pixel_color(data->image, x, y,
						copycolor(data->w_texture, off_x, off_y));
			}
		}
		else
		{
			if (ray->vertical_wall == 0)
				draw_pixel_color(data->image, x, y,
					copycolor(data->s_texture, off_x, off_y));
			else
			{
				if (ray->is_facing_right == 0)
					draw_pixel_color(data->image, x, y,
						copycolor(data->w_texture, off_x, off_y));
				else
					draw_pixel_color(data->image, x, y,
						copycolor(data->e_texture, off_x, off_y));
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

static void	calculate_columns(t_data *data, t_ray *ray, int x)
{
	ray->render->wall_top_pixel = (WIN_HEIGHT / 2)
		- (ray->render->proj_wall_height / 2);
	if (ray->render->wall_top_pixel < 0)
		ray->render->wall_top_pixel = 0;
	ray->render->wall_bottom_pixel = (WIN_HEIGHT / 2)
		+ (ray->render->proj_wall_height / 2);
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
		ray->render->proj_wall_height = (TILE_SIZE / ray->distance)
			* data->dist_proj_plane;
		ray->render->wall_strip_height = ceil(ray->render->proj_wall_height);
		calculate_columns(data, ray, x);
		draw_sky(data, ray, x);
		draw_wall(data, ray, x);
		draw_bottom(data, ray, x);
		x++;
	}
}
