/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:46:37 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/02 00:12:37 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>



int	break_line(t_map *map)
{
    int	i;

    i = 0;
    // verifica se tem linha vazia no mapa
    while (map->map_matrix[i])
    {
        if (map->map_matrix[i] == '\n' && map->map_matrix[i + 1] == '\n')
            return (1);
        i++;
    }
	return (0);
}

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
                if ((ft_strchr("NSEW0", map->map_matrix[i][j + 1])) && map->map_matrix[i][j + 1]) // lado direito do ' '
                    return (1);
                if ((ft_strchr("NSEW0", map->map_matrix[i][j - 1])) && (j > 0)) //lado esquerdo do ' ' 
                    return (1);
                if ((ft_strchr("NSEW0", map->map_matrix[i + 1][j])) && map->map_matrix[i + 1][j]) // embaixo do ' '
                    return (1);
                if ((ft_strchr("NSEW0", map->map_matrix[i - 1][j])) && (i > 0)) // em cima do ' '
                    return (1);
            }
            j++
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
		len = ft_strlen(map->map_matrix[i])
		// verifica se 1º coluna e ultima coluna tem '1'
        if (ft_strchr("NSEW0", map->map_matrix[i][0]) || ft_strchr("NSEW0", map->map_matrix[i][len - 1]))
            return (1);
        i++;
    }
    len = ft_strlen(map->map_matrix[0]);
    while (j < len)
    {
        // verifica se primeira linha só tem '1'
        if ((ft_strchr("NSEW0", map->map_matrix[0][j]))
            return (1);
        j++;
    }
    len = ft_strlen(map->map_matrix[i - 1]);
    while (j < len)
    {
        // verifica se ultima linha só tem '1'
        if ((ft_strchr("NSEW0", map->map_matrix[i - 1][j]))
            return (1);
        j++;
    }
	return (0);
}