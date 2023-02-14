/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:45:37 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/10 21:20:17 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(t_data *data)
{
	int i, j;

	i = 0;
	while (i < data->height / 2)
	{
		j = 0;
		while (j < data->width)
		{
			mlx_pixel_put(data->mlx, data->win, j, i, 0x00CC3300);
			j++;
		}
		i++;
	}
		while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			mlx_pixel_put(data->mlx, data->win, j, i, 0x00000033);
			j++;
		}
		i++;
	}
}

void	render(t_data *data)
{
	t_image	*person;
	t_image *coelho;

	person = init_image(data, "crossbow.xpm");
	coelho = init_image(data, "coelho.xpm");
	render_background(data);
	mlx_put_image_to_window(data->mlx, data->win, coelho->pont, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, person->pont, 200, 100);
	destroy_image(person);
	destroy_image(coelho);
}
