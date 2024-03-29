/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:57:37 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/07 01:48:17 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_spaces_aux(char **map, int i)
{
	int	index;

	index = 0;
	while (map[i][index])
	{
		if (map[i][index] == ' ')
		{
			if (map[i][index + 1] && ft_strchr("NSEW0", map[i][index + 1]))
				return (1);
			if ((index > 0) && ft_strchr("NSEW0", map[i][index - 1]))
				return (1);
			if (map[i + 1] != NULL && map[i + 1][index]
					&& ft_strchr("NSEW0", map[i + 1][index]))
				return (1);
			if ((i > 0) && ft_strchr("NSEW0", map[i - 1][index]))
				return (1);
		}
		index++;
	}
	return (0);
}

int	check_spaces(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_matrix[i])
	{
		if (check_spaces_aux(map->map_matrix, i))
		{
			printf("Error\nInvalid map: Not surrounded by walls");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_walls_aux(char **map)
{
	int	index;
	int	len;

	index = 0;
	while (map[index])
	{
		len = ft_strlen(map[index]);
		if (ft_strchr("NSEW0", map[index][0])
				|| ft_strchr("NSEW0", map[index][len - 1]))
		{
			printf("Error\nInvalid map: Not surrounded by walls");
			return (1);
		}
		index++;
	}
	return (0);
}

int	check_walls(t_map *map)
{
	int	x;
	int	len;
	int	size_map;

	x = 0;
	size_map = ft_matrix_strlen(map->map_matrix);
	if (check_walls_aux(map->map_matrix))
		return (1);
	len = ft_strlen(map->map_matrix[0]);
	while (x < len)
	{
		if (ft_strchr("NSEW0", map->map_matrix[0][x]))
		{
			printf("Error\nInvalid map: Not surrounded by walls");
			return (1);
		}
		x++;
	}
	len = ft_strlen(map->map_matrix[size_map - 1]);
	while (x < len)
	{
		if (ft_strchr("NSEW0", map->map_matrix[size_map - 1][x]))
		{
			printf("Error\nInvalid map: Not surrounded by walls");
			return (1);
		}
		x++;
	}
	return (0);
}
