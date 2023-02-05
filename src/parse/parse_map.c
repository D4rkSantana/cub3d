/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:22:57 by jefernan          #+#    #+#             */
/*   Updated: 2023/02/05 21:06:55 by jefernan         ###   ########.fr       */
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
			if (color(map->elements[i]))
				return (1);
		if (map->elements[i][0] == '1' || map->elements[i][0] == ' ')
			get_array_map(map, map->elements[i]);
		// // if (check_walls(line, map))
		// 	return (1);
		i++;
	}
	// if (map->check_color != 2)
	// 	return (1);
	if (check_array_map(map))
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

int	check_texture(char *str, t_map *map)
{
	char	*swap;
	char	*temp;

	temp = ft_strrchr(str, '.');
	swap = ft_strrchr(str, ' ');
	if (!(ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0
			|| ft_strncmp(str, "WE ", 3) == 0
			|| ft_strncmp(str, "EA ", 3) == 0))
	{
		printf("Error, invalid texture\n");
		return (1);
	}
	if (!(ft_strncmp(swap, " ./textures/", 12) == 0
			&& ft_strncmp(temp, ".xpm", 4) == 0))
	{
		printf("Error, invalid texture\n");
		return (1);
	}
	get_texture(str);
	return (0);
}

// int	check_walls(char *line, t_map *map)
// {
// 	int	i;
// 	int	len;

// 	len = ft_strlen(line);
// 	i = 0;
// 	while (i < len)
// 	{
// 		if (i == 0 || i == len - 1)
// 		{
// 			if (line[i] != "1" || line[i] != " ")
// 		}
// 		while (map->elements[i][j])
// 		{
// 			if (map->elements[i][map->col - 1] != '1'
// 				|| map->elements[i][0] != '1'
// 				|| map->elements[map->height - 1][j] != '1'
// 				|| map->elements[0][j] != '1')
// 			{
// 				printf("Error\nThe map is not surrounded by walls\n");
// 				return (1);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	check_array_map(t_map *map)
{
	char	**map_split;
	int		i;

	i = 0;
	map_split = ft_split(map->map_array, '\n');
	while (map_split[i])
	{
		check_chars(map_split[i], map);
		i++;
	}
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
