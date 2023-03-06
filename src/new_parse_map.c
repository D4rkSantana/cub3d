/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:57:37 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/06 21:58:05 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_spaces(t_map *map)
{
	int	i;
    int	j;

    i = 0;
    while (map->map_matrix[i])
    {
        j = 0;
        while (map->map_matrix[i][j])
        {
                // verifica ao redor do espaço se tem caractere invalido 'NSEW0'
            if (map->map_matrix[i][j] == ' ')
            {
                if (map->map_matrix[i][j + 1] && ft_strchr("NSEW0", map->map_matrix[i][j + 1])) // lado direito do ' '
                    return (1);
                if ((j > 0)  && ft_strchr("NSEW0", map->map_matrix[i][j - 1])) //lado esquerdo do ' ' 
                    return (1);
                if (map->map_matrix[i + 1] != NULL && map->map_matrix[i + 1][j] && ft_strchr("NSEW0", map->map_matrix[i + 1][j])) // embaixo do ' '
                    return (1);
                if ((i > 0) && ft_strchr("NSEW0", map->map_matrix[i - 1][j])) // em cima do ' '
                	return (1);
            }
            j++;
        }
        i++;
    }
	return (0);
}

int	check_walls(t_map *map)
{
	int	i;
    int	j;
    int	len;

    i = 0;
    while (map->map_matrix[i])
    {
		len = ft_strlen(map->map_matrix[i]);
		// verifica se 1º coluna e ultima coluna tem '1'
        if (ft_strchr("NSEW0", map->map_matrix[i][0]) || ft_strchr("NSEW0", map->map_matrix[i][len - 1]))
            return (1);
        i++;
    }
    len = ft_strlen(map->map_matrix[0]);
    while (j < len)
    {
        // verifica se primeira linha só tem '1'
        if (ft_strchr("NSEW0", map->map_matrix[0][j]))
            return (1);
        j++;
    }
    len = ft_strlen(map->map_matrix[i - 1]);
    while (j < len)
    {
        // verifica se ultima linha só tem '1'
        if (ft_strchr("NSEW0", map->map_matrix[i - 1][j]))
            return (1);
        j++;
    }
	return (0);
}
