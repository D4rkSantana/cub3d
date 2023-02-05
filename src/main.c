/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:20 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/05 19:33:12 by esilva-s         ###   ########.fr       */
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
	data->win = mlx_new_window(data->mlx, data->width, data->height, "Cub3d");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv))
		return (0);
	data = init(argv[1]);
	read_map(data);
	if (parse_map(data->map))
	{
		destroy(data);
		return (0);
	}
	start_mlx(data);
	render(data);
	mlx_loop(data->mlx);
	
	destroy(data);
	return (0);
}
