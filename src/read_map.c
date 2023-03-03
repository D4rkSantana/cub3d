/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:46:49 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/02 23:59:23 by esilva-s         ###   ########.fr       */
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

static char	**load_map(int fd)
{
	int		count;
	char	*line;
	char	**elements;

	line = NULL;
	elements = NULL;
	count = get_next_line(fd, &line);
	elements = ft_matrix_join(NULL, line);
	ft_strdel(&line);
	while (count)
	{
		line = NULL;
		count = get_next_line(fd, &line);
		elements = ft_matrix_join(elements, line);
		ft_strdel(&line);
	}
	return (elements);
}

char	**read_map(t_data *data)
{
	int		fd;
	char	**elements;

	elements = NULL;
	if (open_map(data->map->patch, &fd))
		return (NULL);
	elements = load_map(fd);
	close(fd);
	return (elements);
}
