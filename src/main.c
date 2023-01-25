/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:20 by esilva-s          #+#    #+#             */
/*   Updated: 2023/01/25 00:06:32 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (check_args(argc, argv))
		return (0);
	map = malloc(sizeof(t_map));
	map->patch = ft_strdup(argv[1]);
	read_map(map);
	// if (parse_map(map))
	// 	return (0);
	test_mlx();
	printf("Hello!\n");
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
