/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:22:57 by jefernan          #+#    #+#             */
/*   Updated: 2023/01/25 02:23:52 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_map(t_map *map)
{
	char	*line;
	int		fd;
	int		ret;
	
	fd = open(map->patch, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line1(fd);
	while (line)
	{
		if (check_texture(line))
			printf("Invalid texture");
		line = get_next_line1(fd);
	}
	close(fd);
	// if (check_walls(map))
	// 	return (1);
	// if (check_chars(map))
	// 	return (1);
	// if (map->player != 1)
	// {
	// 	printf("Error\nInvalid number of player\n");
	// 	return (1);
	// }
	return (0);
}

int	check_texture(char *str)
{
	if (ft_strncmp(str, "NO ", 3) || ft_strncmp(str, "SO ", 3)
		|| ft_strncmp(str, "WE ", 3) || ft_strncmp(str, "EA ", 3))
		return (1);
	else if (ft_strncmp(str, "./textures/", 10))
		return (1);
	else if (ft_strncmp(str, ".xpm", 4))
		return (1);
	else
		get_texture(str);
	return (0);	
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	map->col = ft_strlen(map->elements[0]);
	i = 0;
	while (map->elements[i])
	{
		j = 0;
		while (map->elements[i][j])
		{
			if (map->elements[i][map->col - 1] != '1'
				|| map->elements[i][0] != '1'
				|| map->elements[map->height - 1][j] != '1'
				|| map->elements[0][j] != '1')
			{
				printf("Error\nThe map is not surrounded by walls\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_chars(t_map *map)
{
	int		i;
	int		j;
	char	player;

	i = 0;
	while (map->elements[i])
	{
		j = 0;
		while (map->elements[i][j])
		{
			if (map->elements[i][j] == 'N' || map->elements[i][j] == 'S'
				|| map->elements[i][j] == 'E' || map->elements[i][j] == 'W')
			{
				map->player++;
				player = map->elements[i][j];
			}
			if (is_char_valid(map, i, j, player))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_char_valid(t_map *map, int i, int j, char player)
{
	if (map->elements[i][j] != '1' && map->elements[i][j] != '0'
		&& map->elements[i][j] != player)
	{
		printf("Error\nInvalid character on map\n");
		return (1);
	}
	return (0);
}

