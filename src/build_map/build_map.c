/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:52:11 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/05 17:09:49 by esilva-s         ###   ########.fr       */
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

/*
void	configure_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map_matrix[i])
	{
		j = 0;
		while (data->map->map_matrix[i][j])
		{
			if (data->map->map_matrix[i][j] == 'N'
					|| data->map->map_matrix[i][j] == 'W'
					|| data->map->map_matrix[i][j] == 'E'
					|| data->map->map_matrix[i][j] == 'S')
			{
				if (data->map->map_matrix[i][j] == 'N')
					data->player->angle = PI / 2;
				if (data->map->map_matrix[i][j] == 'W')
					data->player->angle = PI;
				if (data->map->map_matrix[i][j] == 'E')
					data->player->angle = 0;
				if (data->map->map_matrix[i][j] == 'S')
					data->player->angle = PI * 1.5;
				data->map->map_matrix[i][j] = '0';
				data->player->pos_x = (j * TILE_SIZE) + 2;
				data->player->pos_y = (i * TILE_SIZE) + 2;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	configure_aux(t_data *data)
{
	int	index;
	int	width;
	int	temp;

	index = 0;
	temp = 0;
	width = 0;
	data->map->height_px = data->map->nb_lines * TILE_SIZE;
	while (data->map->map_matrix[index])
	{
		temp = ft_strlen(data->map->map_matrix[index]);
		if (temp > width)
			width = temp;
		index++;
	}
	data->map->width_px = width * TILE_SIZE;
	configure_player(data);
}
*/

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
	print_matrix(data->map->map_matrix);
	//configure_aux(data);
	ft_matrix_strdel(elements);
	return (0);
}
