/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:20 by esilva-s          #+#    #+#             */
/*   Updated: 2023/01/25 20:04:15 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map *init_map(void)
{
	t_map	*map;
	
	map = NULL;
	map = ft_calloc(sizeof(t_map), 1);
	map->patch = NULL;
	map->elements = NULL;
	map->height = 0;
	map->col = 0;
	map->player = 0;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	return (map);
}

static int		ft_matrix_strlen(char **matrix)
{
	int	len;

	len = 0;
	if (matrix == NULL)
		return (-1);
	while (matrix[len] != NULL)
		len++;
	return (len);		
}

static void	ft_matrix_strdel(char **matrix)
{
	int	index;
	int	size;

	index = 0;
	if (matrix == NULL)
		return ;
	size = ft_matrix_strlen(matrix);
	while (index < size)
	{
		ft_strdel(&matrix[index]);
		index++;
	}
	free(matrix);
}

static void	destroy_all(t_map *map)
{
	ft_strdel(&map->patch);
	ft_strdel(&map->no_path);
	ft_strdel(&map->so_path);
	ft_strdel(&map->we_path);
	ft_strdel(&map->ea_path);
	ft_matrix_strdel(map->elements);
	free(map);
	map = NULL;
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (check_args(argc, argv))
		return (0);
	map = init_map();
	map->patch = ft_strdup(argv[1]);
	read_map(map);
	//test_mlx();
	printf("Hello!\n");
	destroy_all(map);
	return (0);
}

void	test_mlx(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
	{
		printf("Error\nNo graphical interface.\n");
		exit(0);
	}
	win = mlx_new_window(mlx, 640, 360, "Cub3d");
	mlx_loop(mlx);
}
