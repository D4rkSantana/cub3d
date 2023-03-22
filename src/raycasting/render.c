/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:45:37 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/22 22:55:58 by esilva-s         ###   ########.fr       */
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

//Não concluida
static void	render_background(t_data *data, t_image *img)
{
	int		index_y;
	int		index_x;
	char	*color;

	color = ft_calloc(sizeof(char), 4);
	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
	index_y = 0;
	while (index_y < img->height)
	{
		index_x = 0;
		while (index_x < img->width)
		{
			draw_pixel_color(img, index_x, index_y, color);
			index_x++;
		}
		index_y++;
	}
	ft_strdel(&color);
}

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
}

void	render(t_data *data)
{
	//printf("x:%f y:%f angle:%f\n", data->player->pos_x, data->player->pos_y, data->player->angle);
	draw_minimap(data, data->image);
	render_player(data, data->image);
	mlx_put_image_to_window(data->mlx, data->win, data->image->pont, 0, 0);
}
