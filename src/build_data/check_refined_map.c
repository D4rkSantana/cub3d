/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_refined_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:36:45 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 16:38:53 by jefernan         ###   ########.fr       */
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

static int	check_spaces(t_map *map)
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

static int	check_walls_aux(char **map)
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

static int	check_walls(t_map *map)
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
			return (1);
		x++;
	}
	len = ft_strlen(map->map_matrix[size_map - 1]);
	while (x < len)
	{
		if (ft_strchr("NSEW0", map->map_matrix[size_map - 1][x]))
			return (1);
		x++;
	}
	return (0);
}

int	check_refined_map(t_data *data)
{
	if (check_walls(data->map))
	{
		printf("Error\nMap walls are wrong\n");
		return (1);
	}
	if (check_spaces(data->map))
	{
		printf("Error\nThe walls of the map are not correctly closed\n");
		return (1);
	}
	if (check_player(data->map->map_matrix))
	{
		printf("Error\nThe player is wrong\n");
		return (1);
	}
	return (0);
}
