/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:22:57 by jefernan          #+#    #+#             */
/*   Updated: 2023/02/02 00:54:02 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_map(t_map *map)
{
	char	*line;
	int		fd;
		
	fd = open(map->patch, O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line1(fd);
		if (!line)
			break ;
		if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
			|| line[0] == 'E')
		{
			if (check_texture(line, map))
				break ;	
		}
		if (line[0] == 'F' || line[0] == 'C')
		{
			if (check_color(line))
				break ;
		}
		if (line[0] == '1' || line[0] == ' ')
			get_array_map(map, line);
		// // if (check_walls(line, map))
		// 	return (1);
		free(line);
	}
	free(line);
	close(fd);
	// if (check_chars(map))
	// 	return (1);
	// if (map->player != 1)
	// {
	// 	printf("Error\nInvalid number of player\n");
	// 	return (1);
	// }
	return (0);
}

void	get_array_map(t_map *map, char *line)
{

	char	*temp;

	temp = ft_strdup(map->map_array);
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
		|| ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0))
	{
		printf("Error, invalid texture");
		// ft_matrix_strdel(split);
		return (1);
	}
	if (!(ft_strncmp(swap, "./textures/", 11) == 0)
		|| !(ft_strncmp(temp, ".xpm", 4) == 0))
	{
		printf("Error, invalid texture");
		// ft_matrix_strdel(split);	
		return (1);
	}
	get_texture(str);
	// ft_matrix_strdel(split);
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

