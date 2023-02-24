/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:45:37 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/17 19:29:03 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
typedef struct	s_image
{
	int		height;
	int		width;
	char	*patch;
	void	*pont;
}				t_image;


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
*/

void	draw_pixel(t_image *img, int x, int y)
{
	int	pos;

	pos = (x * 4) + (img->size_line * y);
	img->patch[pos] = 0;
	img->patch[pos + 1] = 255;
	img->patch[pos + 2] = 0;
	
}

void	render_background(t_data *data, t_image *img)
{
	int	index_y;
	int	index_x;

	index_y = 0;
	while (index_y < img->height)
	{
		index_x = 0;
		while (index_x < img->width)
		{
			draw_pixel(img, index_x, index_y);
			index_x++;
		}
		index_y++;
	}
}

t_image	*init_img(t_data *data)
{
	t_image	*image;

	if (data == NULL)
		return (NULL);
	if (data->mlx == NULL)
		return (NULL);
	image = NULL;
	image = ft_calloc(sizeof(t_image), 1);
	if (image == NULL)
		return (NULL);
	image->width = data->width;
	image->height = data->height;
	image->pont = mlx_new_image(data->mlx, data->width, data->height);
	image->patch = mlx_get_data_addr(image->pont, &image->bpp, &image->size_line, &image->endian);
	return (image);
}

void	render(t_data *data)
{
	t_image	*img;
	t_image	*person;
	//t_image *coelho;

	img = init_img(data);
	person = init_image(data, "crossbow.xpm");
	//coelho = init_image(data, "coelho.xpm");
	//render_background(data);
	
	
	render_background(data, img);
	mlx_put_image_to_window(data->mlx, data->win, img->pont, 0, 0);
	printf("Dados imagem\n bpp: %d size_line: %d endian: %d\n", person->bpp, person->size_line, person->endian);
	int i = 0;
	while (i < 8000)
	{
		printf("%d", (int)person->data_img[i]);
		i++;
	}
	//mlx_put_image_to_window(data->mlx, data->win, coelho->pont, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, person->pont, 200, 100);
	//destroy_image(person);
	//destroy_image(coelho);
}
