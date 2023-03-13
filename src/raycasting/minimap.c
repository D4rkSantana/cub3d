/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:10:36 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/13 22:49:59 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*creat_color(char element)
{
	char	*color;

	color = ft_calloc(sizeof(char), 4);
	if (element == '1')
	{
		color[0] = (char)255;
		color[1] = 0;
		color[2] = 0;
	}
	else if (element == '0')
	{
		color[0] = (char)255;
		color[1] = (char)255;
		color[2] = (char)255;
	}
	else
	{
		color[0] = (char)255;
		color[1] = (char)255;
		color[2] = 0;
	}
	return (color);
}

static void	draw_element(t_image *img, char element, int index, int count)
{
	int		x;
	int		y;
	int		i;
	int		j;
	char	*color;

	x = index * PROP;
	y = count * PROP;
	i = 0;
	color = creat_color(element);
	while (i < PROP)
	{
		j = 0;
		while (j < PROP)
		{
			draw_pixel_color(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
	ft_strdel(&color);
}

//esse index serve para orientar qual a altura da linha do mapa
static void	draw_line_map(char *line, t_image *img, int index)
{
	int	count;
	int	size;

	count = 0;
	size = ft_strlen(line);
	while (count < size)
	{
		draw_element(img, line[count], index, count);
		count++;
	}
}

int	draw_minimap(t_data *data, t_image *img)
{
	int	index;

	index = 0;
	while (data->map->map_matrix[index] != NULL)
	{
		draw_line_map(data->map->map_matrix[index], img, index);
		index++;
	}
	return (0);
}
