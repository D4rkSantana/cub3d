/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:49:39 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/14 01:39:36 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*extraction(char *element, int size_key)
{
	int		index;
	int		size;
	char	*result;

	index = 0;
	size = ft_strlen(element);
	result = NULL;
	result = ft_calloc(sizeof(char), size - size_key + 1);
	while (index < size -1)
	{
		result[index] = element[index + size_key];
		index++;
	}
	result[index] = '\0';
	return (result);
}

static char	*extract_cont(char **elements, char *key)
{	
	int		index;
	int		count;
	int		size;
	char	*result;

	index = 0;
	size = ft_strlen(key);
	result = NULL;
	while (elements[index] != NULL)
	{
		count = 0;
		if (size + 1 < ft_strlen(elements[index]))
		{
			while (key[count] == elements[index][count] && count < size)
				count++;
			if (count == size && elements[index][count] == ' ')
			{
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
	data->map->no_path = extract_cont(elements, "NO");
	data->map->so_path = extract_cont(elements, "SO");
	data->map->we_path = extract_cont(elements, "WE");
	data->map->ea_path = extract_cont(elements, "EA");
	data->map->cl_ceilling = extract_cont(elements, "C");
	data->map->cl_floor = extract_cont(elements, "F");
}
