/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:46:49 by esilva-s          #+#    #+#             */
/*   Updated: 2023/01/18 00:13:21 by esilva-s         ###   ########.fr       */
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

	count = ft_get_next_line(fd, &line);
	map->elements = ft_strdup(line);
	while (count)
	{
		count = ft_get_next_line(fd, &line);
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
