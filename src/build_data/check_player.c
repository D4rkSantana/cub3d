/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:51:42 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 02:32:44 by esilva-s         ###   ########.fr       */
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
		return (1);
	return (0);
}
