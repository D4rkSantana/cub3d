/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:22:57 by jefernan          #+#    #+#             */
/*   Updated: 2023/02/08 12:44:43 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_map(t_map *map)
{
	int		i;

	i = 0;
	while (map->elements[i] != (void *)0)
	{
		if (map->elements[i][0] == 'N' || map->elements[i][0] == 'S'
			|| map->elements[i][0] == 'W' || map->elements[i][0] == 'E')
			if (check_texture(map->elements[i], map))
				return (1);
		if (map->elements[i][0] == 'F' || map->elements[i][0] == 'C')
			if (color(map->elements[i], map))
				return (1);
		if (map->elements[i][0] == '1' || map->elements[i][0] == ' ')
			get_array_map(map, map->elements[i]);
		i++;
	}
	// if (map->check_color != 2)
	// 	return (1);
	if (check_array_map(map, map->map_array))
		return (1);
	return (0);
}

void	get_array_map(t_map *map, char *line)
{
	char	*temp;

	temp = ft_strdup(map->map_array);
	free(map->map_array);
	map->map_array = ft_strjoin(temp, line);
	ft_strdel(&temp);
}

int	check_array_map(t_map *map, char *map_array)
{
	char	**map_split;
	int		i;

	i = 0;
	map_split = ft_split(map_array, '\n');
	while (map_split[i])
	{
		check_chars(map_split[i], map);
		i++;
	}
	ft_strdel(map_split);
	if (map->player != 1)
	{
		printf("Error\nInvalid number of player\n");
		return (1);
	}
	return (0);
}

int	check_chars(char *map_line, t_map *map)
{
	char	player;
	int		i;

	i = 0;
	while (map_line[i] != '\0')
	{
		if (map_line[i] == 'N' || map_line[i] == 'S' || map_line[i] == 'E'
			|| map_line[i] == 'W')
		{
			map->player++;
			player = map_line[i];
		}
		if (is_char_valid(map_line[i], i, player))
			return (1);
		i++;
	}
	return (0);
}

int	is_char_valid(char c, int i, char player)
{
	if (c != '1' && c != '0' && c != ' ' && c != player)
	{
		printf("Error\nInvalid character on map\n");
		return (1);
	}
	return (0);
}
