/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:45:37 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/02 21:26:42 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*creat_color(void)
{
	char	*color;

	color = ft_calloc(sizeof(char), 4);
	color[0] = (char)154;
	color[1] = (char)205;
	color[2] = (char)50;
	return (color);
}

void	draw_pixel_color(t_image *img, int x, int y, char *color)
{
	int	pos;

	pos = (y * 4) + (img->size_line * x);
	img->patch[pos] = color[0];
	img->patch[pos + 1] = color[1];
	img->patch[pos + 2] = color[2];
}

/*
static void	render_player(t_data *data, t_image *img)
{
	int		i;
	int		j;
	char	*color;

	i = 0;
	color = creat_color();
	while (i < PROP)
	{
		j = 0;
		while (j < PROP)
		{
			draw_pixel_color(img, data->player->pos_y * PROP + j,
					data->player->pos_x * PROP + i, color);
			j++;
		}
		i++;
	}
}*/

void	render(t_data *data)
{

	int	x;
	int	y;

	x = data->player->pos_x /  TILE_SIZE;
	y = data->player->pos_y /  TILE_SIZE;
	//printf("px:%f py:%f angle:%f\n", data->player->pos_x,
			//data->player->pos_y, data->player->angle * (180 / PI));
	//printf("mx:%d my:%d\n", x, y);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image->pont, 0, 0);
}
