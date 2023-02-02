/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:20 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/02 18:42:10 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

static void	start_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		printf("Error\nNo graphical interface.\n");
		destroy(data);
		exit(0);
	}
	data->win = mlx_new_window(data->mlx, data->map->col * 50, data->map->height * 50, "Cub3d");
	data->image = mlx_xpm_file_to_image(data->mlx, "coelho.xpm", &data->h_teste, &data->w_teste);
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	
	if (check_args(argc, argv))
		return (0);
	data = init(argv[1]);
	read_map(data->map);
	if (parse_map(data->map))
	{
		destroy(data);
		return (0); 
	}
	//start_mlx(data);
	//mlx_loop(data->mlx);
	destroy(data);
	return (0);
}
