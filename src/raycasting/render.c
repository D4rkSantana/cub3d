/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:45:37 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/14 00:25:44 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	make_image(t_data *data)
{
	if (data == NULL)
		return (1);
	if (data->mlx == NULL)
		return (1);
	if (data->image == NULL)
		return (1);
	data->image->width = data->width;
	data->image->height = data->height;
	data->image->pont = mlx_new_image(data->mlx, data->width, data->height);
	data->image->patch = mlx_get_data_addr(data->image->pont, &data->image->bpp,
			&data->image->size_line, &data->image->endian);
	return (0);
}

void	draw_pixel_color(t_image *img, int x, int y, char *color)
{
	int	pos;

	pos = (x * 4) + (img->size_line * y);
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

void	render(t_data *data)
{
	make_image(data);
	draw_minimap(data, data->image);
	mlx_put_image_to_window(data->mlx, data->win, data->image->pont, 0, 0);
}
