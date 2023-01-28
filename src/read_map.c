/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:46:49 by esilva-s          #+#    #+#             */
/*   Updated: 2023/01/28 19:10:15 by esilva-s         ###   ########.fr       */
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

void	print_matrix(char **matrix, int height)
{
	int	index;

	index = 0;
	printf(":Map:\n");
	while (matrix[index] != NULL)
	{
		printf("%s\n", matrix[index]);
		index++;
	}
	printf("height map: %d\n", height);
}

static int	load_map(int fd, t_map *map)
{
	int		count;
	char	*line;

	line = NULL;
	count = get_next_line(fd, &line);
	map->elements = ft_matrix_join(NULL, line);
	ft_strdel(&line);
	map->height = 1;
	while (count)
	{
		line = NULL;
		count = get_next_line(fd, &line);
		map->height += 1;
		map->elements = ft_matrix_join(map->elements, line);
		ft_strdel(&line);
	}
	//map->elements = ft_matrix_join(map->elements, "\0");
	return (0);
}

int	read_map(t_map *map)
{
	int		fd;

	if (open_map(map->patch, &fd))
		return (1);
	load_map(fd, map);
	close(fd);
	print_matrix(map->elements, map->height);
	return (0);
}
