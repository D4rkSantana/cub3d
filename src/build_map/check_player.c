/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 01:00:46 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/02 15:45:35 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_line(char *line)
{
	int	index;
	int	result;

	index = 0;
	result = 0;
	while (line[index] != '\0')
	{
		if (line[index] == 'N' || line[index] == 'S'
			|| line[index] == 'E' || line[index] == 'W')
			result++;
		index++;
	}
	return (result);
}

int	check_player(char **map)
{
	int	index;
	int	qt_persons;

	index = 0;
	qt_persons = 0;
	while (map[index] != NULL)
	{
		qt_persons += check_line(map[index]);
		index++;
	}
	if (qt_persons != 1)
	{
		printf("Error\nInvalid number of player\n");
		return (1);
	}
	return (0);
}

int	check_map(char **map)
{
	int	index;
	int	count;

	index = 0;
	while (map[index] != NULL)
	{
		count = 0;
		while (map[index][count] != '\0')
		{
			if (!(map[index][count] == '1' || map[index][count] == '0'
				|| map[index][count] == ' ' || map[index][count] == 'N'
				|| map[index][count] == 'S' || map[index][count] == 'W'
				|| map[index][count] == 'E'))
				return (1);
			count++;
		}
		index++;
	}
	return (0);
}
