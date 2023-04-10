/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:59:52 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/10 20:31:51 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int    check_space(char **elements, char *key)
{
    int    size;
    int    index;

    index = 0;
    size = ft_strlen(key);
    if (elements[index][size] != ' ')
    {
        printf("Error\nInvalid: %s\n", elements[index]);
        return (1);
    }
    return (0);
}

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

int    check_contents(char **elements)
{
    if (check_cont(elements, "NO") || check_space(elements, "NO"))
        return (1);
    if (check_cont(elements, "SO") || check_space(elements, "SO"))
        return (1);
    if (check_cont(elements, "WE") || check_space(elements, "WE"))
        return (1);
    if (check_cont(elements, "EA") || check_space(elements, "EA"))
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
	status += check_color(map->str_sky);
	status += check_color(map->str_floor);
	if (status != 0)
		return (1);
	return (0);
}
