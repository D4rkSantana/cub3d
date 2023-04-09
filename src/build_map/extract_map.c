/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:53:29 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/10 01:31:05 by esilva-s         ###   ########.fr       */
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

int	check_position_map(char **elements)
{
	int	index;
	int	map;

	index = 0;
	map = 0;
	while (elements[index] != NULL)
	{
		if (is_line_map(elements[index]))
			map = 1;
		else if (map == 1)
		{
			printf("Error\nThe map is not at the end of the file\n");
			return (1);
		}
		index++;
	}
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
	if (check_position_map(elements))
		return (1);
	if (map_active == 1)
		return (0);
	return (1);
}

static char	*complet_line(int columns, char *element)
{
	int		index;
	int		size_element;
	char	*result;

	index = 0;
	size_element = ft_strlen(element);
	result = NULL;
	result = ft_calloc(sizeof(char), columns + 1);
	while (index < columns)
	{
		if (index < size_element)
			result[index] = element[index];
		else
			result[index] = ' ';
		index++;
	}
	result[index] = '\0';
	return (result);
}

static void	map_size(t_data *data, char **elements)
{
	int	index;
	int	lines;
	int	columns;

	index = 0;
	lines = 0;
	columns = 0;
	while (elements[index] != NULL)
	{
		if (is_line_map(elements[index]))
		{
			if (columns < ft_strlen(elements[index]))
				columns = ft_strlen(elements[index]);
			lines++;
		}
		index++;
	}
	data->map->nb_columns = columns;
	data->map->nb_lines = lines;
	data->map->height_px = lines * TILE_SIZE;
	data->map->width_px = columns * TILE_SIZE;
}

void	extract_map(t_data *data, char **elements)
{
	int		index;
	char	*temp;
	char	**result;

	index = 0;
	result = NULL;
	temp = NULL;
	map_size(data, elements);
	while (elements[index] != NULL)
	{
		if (is_line_map(elements[index]))
		{
			temp = complet_line(data->map->nb_columns, elements[index]);
			result = ft_matrix_join(result, temp);
			ft_strdel(&temp);
			temp = NULL;
		}
			
		index++;
	}
	data->map->map_matrix = result;
}
