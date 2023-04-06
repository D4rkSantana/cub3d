/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:52:11 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/06 00:32:04 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* REMOVER ANTES DE FINALIZAR O PROJETO !!!! */
static void	print_matrix(char **matrix)
{
	int	index;

	index = 0;
	printf(":Map:\n");
	while (matrix[index] != NULL)
	{
		printf("[%d]%s|\n", index, matrix[index]);
		index++;
	}
}

/* REMOVER ANTES DE FINALIZAR O PROJETO !!!! */
static void	print_contents(t_map *map)
{
	printf(":Contents:\n");
	printf("NO:%s|\n", map->no_path);
	printf("SO:%s|\n", map->so_path);
	printf("WE:%s|\n", map->we_path);
	printf("EA:%s|\n", map->ea_path);
	printf("C:%s|\n", map->cl_ceilling);
	printf("F:%s|\n", map->cl_floor);
	print_matrix(map->map_matrix);
}

static int	check_refined_map(t_data *data)
{
	if (check_walls(data->map) || check_spaces(data->map)
		|| check_player(data->map->map_matrix)
		|| check_map(data->map->map_matrix))
	{
		return (1);
	}
	return (0);
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
	if (check_extension(data->map) || check_integrity_map(elements))
	{
		ft_matrix_strdel(elements);
		return (1);
	}
	extract_map(data, elements);
	if (check_refined_map(data))
	{
		ft_matrix_strdel(elements);
		return (1);
	}
	//configure_aux(data);
	ft_matrix_strdel(elements);
	return (0);
}
