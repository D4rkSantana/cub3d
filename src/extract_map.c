/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:53:29 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/06 21:58:10 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_line_map(char *element)
{
	int	index;

	index = 0;
	while (element[index] == ' ')
		index++;
	if (element[index] == '1')
		return (1);
	return (0);
}

int	check_integrity_map(char **elements)
{
	int	index;
	int	map_active;
	int	map_break;
	int	line_map;

	index = 0;
	map_active = 0;
	map_break = 0;
	while (elements[index] != NULL)
	{
		line_map = is_line_map(elements[index]);
		if (map_active == 0 && line_map == 1)
			map_active = 1;
		else if (map_active == 1 && line_map == 0)
			map_break = 1;
		else if (map_break == 1 && line_map == 1)
			return (1);
		index++;
	}
	if (map_active == 1)
		return (0);
	return (1);
}

void	extract_map(t_data *data, char **elements)
{
	int		index;
	int		find;
	char	**result;

	index = 0;
	find = 0;
	result = NULL;
	while (elements[index] != NULL)
	{
		if (is_line_map(elements[index]))
		{
			if (find == 0)
				find = 1;
			result = ft_matrix_join(result, elements[index]);
		}
		else if (find == 1)
			break ;
		index++;
	}
	data->map->map_matrix = result;
}
