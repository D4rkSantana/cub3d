/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:51:55 by jefernan          #+#    #+#             */
/*   Updated: 2023/02/04 21:06:19 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color(char *line)
{
	if (!(ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0))
	{
		printf("Error, invalid color\n");
		return (1);
	}
	if (ft_strchr(line, ','))
		check_color(line);
	else
	{
		printf("Error, invalid color\n");
		return (1);
	}
	return (0);
}

void	check_color(char *line)
{
	t_map	*map;
	int		j;
	int		i;

	i = -1;
	j = 0;
	map = init_map(NULL);
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
	destroy_map(map);
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
		j = 0;
		while (j < ft_strlen(rgb_color[i]))
		{
			if (check_char(rgb_color[i], rgb_color[i][j]))
			{
				ft_matrix_strdel(rgb_color);
				return (1);
			}
			j++;
		}
	}
	ft_matrix_strdel(rgb_color);
	if (verify_count_rgb(i))
		return (1);
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
		j = 0;
		while (j < ft_strlen(rgb_color[i]))
		{
			if (check_char(rgb_color[i], rgb_color[i][j]))
			{
				ft_matrix_strdel(rgb_color);
				return (1);
			}
			j++;
		}
	}
	ft_matrix_strdel(rgb_color);
	if (verify_count_rgb(i))
		return (1);
	return (0);
}

int	check_char(char *rgb, char c)
{
	if (c != '\0')
	{
		if (!ft_isdigit(c))
		{
			printf("Error, color is not a number\n");
			return (1);
		}
		if (ft_atoi(rgb) < 0 || ft_atoi(rgb) > 255)
		{
			printf("Error, color < 0 or > 255\n");
			return (1);
		}
	}
	else
		return (1);
	return (0);
}
