/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:15:07 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/08 18:36:59 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_sky(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->render->wall_top_pixel)
	{
		draw_pixel_color(data->image, x, y, data->map->color_sky);
		y++;
	}
}

static void	draw_wall(t_data *data, int x, int vert)
{
	int	y;

	y = data->render->wall_top_pixel;
	while (y < data->render->wall_bottom_pixel)
	{
		if (vert)
			draw_pixel_color(data->image, x, y, convert_hex("0,0,0"));
		else
			draw_pixel_color(data->image, x, y, convert_hex("0,255,0"));
		/*
        if (color_buffer[(WIN_WIDTH * y) + i] = data->rays[i].was_hit_vert)
            color_buffer = 0xFFFFFFFF;
        else
            color_buffer = 0xFFCCCCCC;
		*/
		
		y++;
	}
}

static void	draw_bottom(t_data *data, int x)
{
	int	y;

	y = data->render->wall_bottom_pixel;
	while (y < WIN_HEIGHT)
	{
		draw_pixel_color(data->image, x, y, data->map->color_floor);
		y++;
	}
}

static void	calcule_columns(t_data *data, int x)
{
	data->render->wall_top_pixel = (WIN_HEIGHT / 2) - (data->render->proj_wall_height / 2);
	
	if (data->render->wall_top_pixel < 0)
		data->render->wall_top_pixel = 0;

	data->render->wall_bottom_pixel = (WIN_HEIGHT / 2) + (data->render->proj_wall_height / 2);

	if (data->render->wall_bottom_pixel > WIN_HEIGHT)
		data->render->wall_bottom_pixel = WIN_HEIGHT;
}

void	render_3d_projected_walls(t_data *data)
{
	int	x;
	int	y;
	int	color_buffer;

	x = 0;
	while (x < NUM_RAYS)
	{
		// data->render->perp_dist = ; RETIRAR DA STRUCT
		 
		data->render->proj_wall_height = (TILE_SIZE / data->rays[x].distance) * data->render->dist_proj_plane;
		//data->render->wall_strip_height = (int)data->render->proj_wall_height;
		calcule_columns(data, x);
		draw_sky(data, x);
		draw_wall(data, x, data->rays[x].vertical_wall);
		draw_bottom(data, x);
		x++;
	}
}
