/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:29:59 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/02 15:44:31 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_node(char *node)
{
	int	count;
	int	size;

	count = 0;
	size = ft_strlen(node);
	if (size < 0 || size > 3)
		return (1);
	while (count < size)
	{
		if (!ft_isdigit(node[count]))
			return (1);
		count++;
	}
	return (0);
}

int	check_color(char *color)
{
	char	**rgb_color;
	int		index;
	int		nb;

	index = 0;
	rgb_color = ft_split(color, ',');
	if (ft_matrix_strlen(rgb_color) != 3)
	{
		printf("Error\nInvalid RGB color\n");
		ft_matrix_strdel(rgb_color);
		return (1);
	}
	while (index < 3)
	{
		nb = ft_atoi(rgb_color[index]);
		if (!(nb > -1 && nb < 256) || check_node(rgb_color[index]))
		{
			printf("Error\nInvalid RGB color\n");
			ft_matrix_strdel(rgb_color);
			return (1);
		}
		index++;
	}
	ft_matrix_strdel(rgb_color);
	return (0);
}
