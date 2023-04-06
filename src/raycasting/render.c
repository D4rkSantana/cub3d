/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:45:37 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/06 00:48:18 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_pixel_color(t_image *img, int x, int y, int color)
{
	char	*tmp;

	tmp = img->patch + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *) tmp = color;
}

void	render(t_data *data)
{

	int	x;
	int	y;

	x = data->player->pos_x /  TILE_SIZE;
	y = data->player->pos_y /  TILE_SIZE;
	// printf("px:%f py:%f angle:%f\n", data->player->pos_x,
			// data->player->pos_y, data->player->angle * (180 / PI));
	// printf("mx:%d my:%d\n", x, y);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image->pont, 0, 0);
}
