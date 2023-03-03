/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:52:11 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/04 00:09:38 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ----------------------------------
// ---------- Content part
// ----------------------------------

// check

int	check_cont(char **elements, char *key)
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

// extract

char *extraction(char *element, int size_key)
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

char	*extract_cont(char **elements, char *key)
{	
	int	index;
	int count;
	int	size;
	char *result;

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
				result = extraction(elements[index], size);
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

// ----------------------------------
// ---------- Map part
// ----------------------------------

// checa o mapa bruto

static int	is_line_map(char *element)
{
	int	index;

	index = 0;
	while (element[index] == ' ')
		index++;
	if (element[index] == '1')
		return (1);
	return (0);
}

int	check_integrity_map(char **elements)
{
	int	index;
	int	map_active;
	int	map_break;
	int	line_map;

	index = 0;
	map_active = 0;
	map_break = 0;
	while (elements[index] != NULL)
	{
		line_map = is_line_map(elements[index]);
		if (map_active == 0 && line_map == 1)
			map_active = 1;
		else if (map_active == 1 && line_map == 0)
			map_break = 1;
		else if (map_break == 1 && line_map == 1)
			return (1);
		index++;
	}
	if (map_active == 1)
		return (0);
	return (1);
}

// extract map

void	extract_map(t_data *data, char **elements)
{
	int		index;
	int		find;
	char	**result;

	index = 0;
	find = 0;
	result = NULL;
	while (elements[index] != NULL)
	{
		if (is_line_map(elements[index]))
		{
			if (find == 0)
				find = 1;
			result = ft_matrix_join(result, elements[index]);
		}
		else if (find == 1)
			break ;
		index++;
	}
	data->map->map_matrix = result;
}

static void	print_matrix(char **matrix)
{
	int	index;

	index = 0;
	printf(":Map:\n");
	while (matrix[index] != NULL)
	{
		printf("[%d]%s\n", index, matrix[index]);
		index++;
	}
}

// checagem mapa refinado

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

// ----------------------------------
// ---------- BUILD MAP
// ----------------------------------



static void	print_contents(t_map *map)
{
	printf("NO: %s\n", map->no_path);
	printf("SO: %s\n", map->so_path);
	printf("WE: %s\n", map->we_path);
	printf("EA: %s\n", map->ea_path);
	printf("C: %s\n", map->cl_ceilling);
	printf("F: %s\n", map->cl_floor);
}

int	build_map(t_data *data)
{
	char	**elements;

	elements = read_map(data);
	if (elements == NULL)
		return (1);
	if (check_contents(elements))
	{
		ft_matrix_strdel(elements);
		return (1);
	}
	extract_contents(data, elements);	
	if (check_integrity_map(elements))
	{
		ft_matrix_strdel(elements);
		return (1);
	}
	extract_map(data, elements);
	if (check_walls(data->map))
	{
		ft_matrix_strdel(elements);
		return (1);
	}
	if (check_spaces(data->map))
	{
		ft_matrix_strdel(elements);
		return (1);
	}
	//print_contents(data->map);
	//print_matrix(data->map->map_matrix);
	ft_matrix_strdel(elements);
	return (0);
}