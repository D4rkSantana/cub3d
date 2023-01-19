/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:46:49 by esilva-s          #+#    #+#             */
/*   Updated: 2023/01/19 01:09:37 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	open_map(char *patch, int *fd)
{
	*fd = open(patch, O_RDONLY);
	if (*fd == -1)
	{
		printf("Error map\n");
		return (1);
	}
	return (0);
}

static int	load_map(int fd, t_map *map)
{
	int		count;
	char	*line;

	count = get_next_line(fd, &line);
	map->elements = ft_strdup(line);
	while (count)
	{
		count = get_next_line(fd, &line);
		map->elements = ft_strjoin_free2(map->elements, line, ft_strlen(line));
		map->elements = ft_strjoin_free2(map->elements, "\n", 1);
	}
	map->elements = ft_strjoin_free2(map->elements, "\0", 1);
	return (0);
}

int	read_map(t_map *map)
{
	int		fd;

	if (open_map(map->patch, &fd))
		return (1);
	load_map(fd, map);
	printf(":Map:\n%s\n", map->elements);
	close(fd);
	return (0);
}
