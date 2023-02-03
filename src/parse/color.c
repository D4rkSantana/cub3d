/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:51:55 by jefernan          #+#    #+#             */
/*   Updated: 2023/02/04 00:37:02 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_color(char *line)
{
	t_map	*map;

	if (!(ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0))
	{
		printf("Error, invalid color");
		return (1);
	}
	if (ft_strchr(line, ','))
		get_color(line, map);
	else
	{
		printf("Error, color\n");
		return (1);
	}
	return (0);
}

void	get_color(char *line, t_map *map)
{
	int		j;
	int		i;

	i = -1;
	j = 0;
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		check_cl_floor(line, map, i, j);
		map->check_color++;
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		check_cl_ceilling(line, map, i, j);
		map->check_color++;
	}
}

int	check_cl_floor(char *line, t_map *map, int i, int j)
{
	char	**rgb_color;
	char	*temp;
	int		rgb;

	temp = ft_strtrim(line, "F \n");
	rgb_color = ft_split(temp, ',');
	free(temp);
	while (rgb_color[++i] != NULL)
	{
		if (ft_atoi(rgb_color[i]) < 0 || ft_atoi(rgb_color[i]) > 255)
		{
			printf("Error, color is not a number\n");
			ft_matrix_strdel(rgb_color);
			return (1);
		}
		j = 0;
		while (j < ft_strlen(rgb_color[i]))
		{
			if (!ft_isdigit(rgb_color[i][j]))
			{
				printf("Error,wrong character\n");
				ft_matrix_strdel(rgb_color);
				return (1);
			}
			j++;
		}
	}
	ft_matrix_strdel(rgb_color);
	return (0);
}

int	check_cl_ceilling(char *line, t_map *map, int i, int j)
{
	char	**rgb_color;
	char	*temp;

	temp = ft_strtrim(line, "C \n");
	rgb_color = ft_split(temp, ',');
	free(temp);
	while (rgb_color[++i] != NULL)
	{
		if (ft_atoi(rgb_color[i]) < 0 || ft_atoi(rgb_color[i]) > 255)
		{
			printf("Error, color is not a number\n");
			ft_matrix_strdel(rgb_color);
			return (1);
		}
		j = 0;
		while (j < ft_strlen(rgb_color[i]))
		{
			if (!ft_isdigit(rgb_color[i][j]))
			{
				printf("Error,wrong character\n");
				ft_matrix_strdel(rgb_color);
				return (1);
			}
			j++;
		}
	}
	ft_matrix_strdel(rgb_color);
	return (0);
}
