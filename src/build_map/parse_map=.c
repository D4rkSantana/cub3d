/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:22:57 by jefernan          #+#    #+#             */
/*   Updated: 2023/03/02 23:58:16 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_map(t_map *map)
{
	int		i;

	i = 0;
	while (map->map_matrix[i] != (void *)0)
	{
		if (map->map_matrix[i][0] == 'N' || map->map_matrix[i][0] == 'S'
			|| map->map_matrix[i][0] == 'W' || map->map_matrix[i][0] == 'E')
			if (check_texture(map->map_matrix[i], map))
				return (1);
		if (map->map_matrix[i][0] == 'F' || map->map_matrix[i][0] == 'C')
			if (color(map->map_matrix[i], map))
				return (1);
		if (map->map_matrix[i][0] == '1' || map->map_matrix[i][0] == ' ')
			check_line_map(map, map->map_matrix[i]);
		i++;
	}
	if (check_quantity(map))
		return (1);
	return (0);
}

int	check_line_map(t_map *map, char *map_line)
{
	if (check_player(map_line, map))
		return (1);
	return (0);
}

int	check_player(char *map_line, t_map *map)
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
		if (is_char_valid(map_line[i], player))
			return (1);
		i++;
	}
	return (0);
}

int	is_char_valid(char c, char player)
{
	if (c != '1' && c != '0' && c != ' ' && c != player)
	{
		printf("Error\nInvalid character on map\n");
		return (1);
	}
	return (0);
}
