/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:59:52 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/02 15:44:37 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_cont(char **elements, char *key)
{
	int	index;
	int	find;
	int	size;
	int	count;

	index = 0;
	find = 0;
	size = ft_strlen(key);
	while (elements[index] != NULL)
	{
		count = 0;
		if (ft_strlen(elements[index]) > 0)
		{
			while (key[count] == elements[index][count] && count < size)
				count++;
			if (count == size)
				find++;
		}
		index++;
	}
	if (find == 1)
		return (0);
	return (1);
}

int	check_contents(char **elements)
{
	if (check_cont(elements, "NO"))
		return (1);
	if (check_cont(elements, "SO"))
		return (1);
	if (check_cont(elements, "WE"))
		return (1);
	if (check_cont(elements, "EA"))
		return (1);
	if (check_cont(elements, "F"))
		return (1);
	if (check_cont(elements, "C"))
		return (1);
	return (0);
}

static int	check_path(char *path)
{
	if (!(ft_strncmp(path, "./textures/", 11) == 0))
	{
		printf("Error\nInvalid texture dir\n");
		return (1);
	}
	if (!(ft_strncmp(path + ft_strlen(path) - 4, ".xpm", 4) == 0))
	{
		printf("Error\nInvalid texture extension\n");
		return (1);
	}
	return (0);
}

int	check_extension(t_map *map)
{
	int	status;

	status = 0;
	status += check_path(map->no_path);
	status += check_path(map->so_path);
	status += check_path(map->we_path);
	status += check_path(map->ea_path);
	status += check_color(map->cl_ceilling);
	status += check_color(map->cl_floor);
	if (status != 0)
		return (1);
	return (0);
}
