/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:20 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/03 00:03:07 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	start_mlx(t_data *data)
{
	t_image	*image;

	data->mlx = mlx_init();
	if (!data->mlx)
	{
		printf("Error\nNo graphical interface.\n");
		destroy(data);
		exit(0);
	}
	image = init_image(data, "coelho.xpm");
	data->win = mlx_new_window(data->mlx, data->width, data->height, "Cub3d");
	mlx_put_image_to_window(data->mlx, data->win, image->pont, 0, 0);
	mlx_hook(data->win, KEY_PRESS, 1L << 0, key_hook, data);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, destroy, data);
	destroy_image(image);
}

static void	print_matrix(char **matrix)
{
	int	index;

	index = 0;
	printf(":Map:\n");
	while (matrix[index] != NULL)
	{
		printf("%s\n", matrix[index]);
		index++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv))
		return (0);
	data = init(argv[1]);
	//read_map(data);
	
	if (build_map(data))
	{
		destroy(data);
		return (0);
	}
	print_matrix(data->map->map_matrix); 
	printf(" X \n");
	if (parse_map(data->map))
	{
		destroy(data);
		return (0);
	}
	// start_mlx(data);
	// mlx_loop(data->mlx);
	destroy(data);
	return (0);
}
