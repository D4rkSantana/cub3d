/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:39:33 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/01 22:49:30 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *extract_content(char *element, int size_key)
{
	int		index;
	int		size;
	char	*result;

	index = 0;
	size = ft_strlen(element);
	result = NULL;
	result = ft_calloc(sizeof(char), size - size_key + 1);
	while (index < size)
	{
		result[index] = element[index + size_key];
		index++;
	}
	result[index] = '\0';
	return (result);
}

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

char	**find_map(char **elements)
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
	return (result);
}

static int	find_long_line(char **elements)
{
	int	index;
	int	result;
	int	size_temp;
	
	index = 0;
	result = 0;
	size_temp = 0;
	while (elements[index] != NULL)
	{
		size_temp = ft_strlen(elements[index])
		if (size_temp > result)
			result = size_temp;
		index++;
	}
	return (result);
}

/*
	char	*patch
	char	**map_matrix; ok
	int		line; ok
	int		col; ok
	int		player;
	int		check_color;
	int		check_texture; 
	char	*no_path; ok
	char	*so_path; ok
	char	*we_path; ok
	char	*ea_path; ok
	char	*cl_floor; ok
	char	*cl_ceilling; ok
*/

int	configure_map(t_map *map, char **elements)
{
	map->no_path = find_content("NO", elements);
	map->so_path = find_content("SO", elements);
	map->we_path = find_content("WE", elements);
	map->ea_path = find_content("EA", elements);
	map->cl_floor = find_content("F", elements);
	map->cl_ceilling = find_content("C", elements)
	map->map_matrix = find_map(elements);
	map->line = find_long_line(map->map_matrix);
	map->col = ft_matrix_strlen(map->map_matrix);
}