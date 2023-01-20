/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:46:49 by esilva-s          #+#    #+#             */
/*   Updated: 2023/01/20 14:53:54 by jefernan         ###   ########.fr       */
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

int		ft_matrix_strlen(char **matrix)
{
	int	len;

	len = 0;
	if (matrix == NULL)
		return (-1);
	while (matrix[len] != NULL)
		len++;
	return (len);		
}

void	ft_matrix_strdel(char **matrix)
{
	int	index;
	int	size;

	index = 0;
	if (matrix == NULL)
		return ;
	size = ft_matrix_strlen(matrix);
	while (index < size)
	{
		ft_strdel(&matrix[index]);
		index++;
	}
	free(matrix);
}

char	**ft_matrix_strdup(char **matrix)
{
	char	**result;
	int		size;
	int		index;

	if (matrix == NULL)
		return (NULL);
	size = ft_matrix_strlen(matrix);
	result = ft_calloc(sizeof(char *), size);
	while (index < size)
	{
		result[index] = ft_strdup(matrix[index]);
		index++;
	}
	return (result);
}

char	**matrix_join(char **matrix, char *str)
{
	char	**result;
	int		size;
	int		index;

	if (matrix == NULL && str != NULL)
	{
		result = ft_calloc(sizeof(char *), 1);
		result[0] = ft_strdup(str);
		return (result);
	}
	else if (str == NULL)
		return (NULL);
	index = 0;
	size = ft_matrix_strlen(matrix);
	result = ft_calloc(sizeof(char *), size + 2);
	while (index < size)
	{
		result[index] = ft_strdup(matrix[index]);
		index++;
	}
	result[index] = ft_strdup(str);
	ft_matrix_strdel(matrix);
	return (result);
	
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

	count = get_next_line(fd, &line);
	map->elements = matrix_join(NULL, line);
	map->height = 1;
	while (count)
	{
		count = get_next_line(fd, &line);
		map->height += 1;
		map->elements = matrix_join(map->elements, line);
	}
	//map->elements = matrix_join(map->elements, "\0");
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
