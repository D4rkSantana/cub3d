/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:15:07 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/05 17:36:03 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//funções creat_color somente para testes

static char	*creat_color1(void)
{
	char	*color;

	color = ft_calloc(sizeof(char), 4);
	color[0] = (char)255;
	color[1] = 0;
	color[2] = 0;
	return (color);
}

static char	*creat_color2(void)
{
	char	*color;

	color = ft_calloc(sizeof(char), 4);
	color[0] = (char)255;
	color[1] = (char)255;
	color[2] = (char)50;
	return (color);
}

static char	*creat_color3(void)
{
	char	*color;

	color = ft_calloc(sizeof(char), 4);
	color[0] = (char)50;
	color[1] = (char)50;
	color[2] = (char)50;
	return (color);
}

static void	draw_top(t_data *data, int x, char *color)
{
	int	y;

	y = 0;
    while (y < data->render->wall_top_pixel)
    {
        //color_buffer[(WIN_WIDTH * y) + i] = 0xFF333333;
		draw_pixel_color(data->image, y, x, color);
        y++;
    }
}

static void	draw_wall(t_data *data, int x, char *color)
{
	int	y;

	y = data->render->wall_top_pixel;
    while (y < data->render->wall_bottom_pixel)
       {
		/*
        if (color_buffer[(WIN_WIDTH * y) + i] = data->rays[i].was_hit_vert)
            color_buffer = 0xFFFFFFFF;
        else
            color_buffer = 0xFFCCCCCC;
		*/
		draw_pixel_color(data->image,y, x, color);
        y++;
    }
}

static void	draw_bottom(t_data *data, int x, char *color)
{
	int	y;
	
	y = data->render->wall_bottom_pixel;
    while (y < WIN_HEIGHT)
    {
		//color_buffer[(WIN_WIDTH * y) + i] = 0xFF777777;
		draw_pixel_color(data->image,y, x, color);
        y++;
	}
}

static void	calcule_columns(t_data *data, int x)
{
    data->render->wall_top_pixel = (WIN_HEIGHT / 2) - (data->render->wall_strip_height / 2);

	if (data->render->wall_top_pixel < 0)
        data->render->wall_top_pixel = 0;
	data->render->wall_bottom_pixel = (WIN_HEIGHT / 2) + (data->render->wall_strip_height);
    if (data->render->wall_bottom_pixel > WIN_HEIGHT)
        data->render->wall_bottom_pixel = WIN_HEIGHT;
}

void    render_3d_projected_walls(t_data *data)
{
    int    x;
    int    y;
    int    color_buffer;
	char	*color1 = creat_color1();
	char	*color2 = creat_color2();
	char	*color3 = creat_color3();

    x = 0;
    while (x < NUM_RAYS)
    {
		data->render->perp_dist = data->rays[x].distance * cos(data->rays[x].ray_angle - data->player->angle);
		if (tan(FOV_ANGLE / 2) != 0)
			data->render->dist_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANGLE / 2);
		else
			data->render->dist_proj_plane = 0;
		
    	data->render->proj_wall_height = (TILE_SIZE / data->render->perp_dist);
    	data->render->wall_strip_height = (int)data->render->proj_wall_height;
        calcule_columns(data, x);
        draw_top(data, x, color1);
		draw_wall(data, x, color3);
		draw_bottom(data, x, color2);
        x++;
    }
}