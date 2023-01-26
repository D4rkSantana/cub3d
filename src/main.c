/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:20 by esilva-s          #+#    #+#             */
/*   Updated: 2023/01/26 19:09:13 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map *init_map(char *patch)
{
	t_map	*map;
	
	map = NULL;
	map = ft_calloc(sizeof(t_map), 1);
	map->patch = NULL;
	map->patch = ft_strdup(patch);
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
	map = init_map(argv[1]);
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
