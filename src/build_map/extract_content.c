/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:49:39 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/10 20:33:43 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	convert_hex(char *color)
{
	char	**rgb_color;
	int		rgb[3];
	int		i;

	rgb_color = ft_split(color, ',');
	i = -1;
	while (rgb_color[++i])
		rgb[i] = ft_atoi(rgb_color[i]);
	ft_matrix_strdel(rgb_color);
	return ((rgb[0] << 16) + (rgb[1] << 8) + (rgb[2] << 0));
}

static char	*extraction(char *element, int size_key)
{
	int		index;
	int		size;
	char	*result;

	index = 0;
	size = ft_strlen(element);
	result = NULL;
	result = ft_calloc(sizeof(char), size - size_key + 2);
	while (index < size -1 && index + size_key < size)
	{
		result[index] = element[index + size_key];
		index++;
	}
	result[index] = '\0';
	return (result);
}

static char    *extract_cont(char **elements, char *key, int i)
{    
    int        index;
    int        count;
    int        size;
    char    *result;

    index = 0;
    size = ft_strlen(key);
    result = NULL;
    while (elements[index] != NULL)
    {
        count = 0;
        i = size;
        if (size + 1 < ft_strlen(elements[index]))
        {
            while (key[count] == elements[index][count] && count < size)
                count++;
            while (elements[index][i + 1] == ' ')
                i++;
            if (count == size && elements[index][count] == ' ')
            {
                if (i > size)
                    result = extraction(elements[index], (size + i) - 1);
                else
                    result = extraction(elements[index], size + 1);
                break ;
            }
        }
        index++;
    }
    return (result);
}

void	extract_contents(t_data *data, char **elements)
{
	int	i;

	i = 0;
	data->map->no_path = extract_cont(elements, "NO", 1);
	data->map->so_path = extract_cont(elements, "SO", 1);
	data->map->we_path = extract_cont(elements, "WE", 1);
	data->map->ea_path = extract_cont(elements, "EA", 1);
	data->map->str_sky = extract_cont(elements, "C", 1);
	data->map->str_floor = extract_cont(elements, "F", 1);
}
