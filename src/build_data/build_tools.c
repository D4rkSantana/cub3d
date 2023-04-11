/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:34:06 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/10 23:23:19 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Verifica se a string é linha valida de um mapa

int	is_line_map(char *element)
{
	int	index;

	index = 0;
	while (element[index] == ' ')
		index++;
	if (element[index] == '1')
		return (1);
	return (0);
}

int	convert_hex(char *color)
{
	char	**rgb_color;
	int		rgb[3];
	int		i;

	rgb_color = ft_split(color, ',');
	i = -1;
	while (rgb_color[++i])
		rgb[i] = ft_atoi(rgb_color[i]);
	ft_matrix_strdel(rgb_color);
	return ((rgb[0] << 16) + (rgb[1] << 8) + (rgb[2] << 0));
}
