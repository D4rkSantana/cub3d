/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:20 by esilva-s          #+#    #+#             */
/*   Updated: 2023/03/17 01:26:57 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	start_mlx(t_data *data)
{
	t_image	*image;

	data->mlx = mlx_init();
	if (!data->mlx)
	{
		printf("Error\nNo graphical interface.\n");
		destroy(data);
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, data->width, data->height, "Cub3d");
	mlx_hook(data->win, KEY_PRESS, 1L << 0, key_hook, data);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, destroy, data);
	return (0);
}

static int	check_args(int argc, char **argv)
{
	int		len;
	char	*str;

	if (argc < 2)
	{
		printf("Wrong numbers of arguments\n");
		return (1);
	}
	else
	{
		len = 0;
		str = ft_strrchr(argv[1], '.');
		if (str)
		{
			len = ft_strlen(str);
			if (!ft_memcmp(str, ".cub", len))
				return (0);
		}
		printf("Error\nInvalid map extension. Use .cub\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv))
		return (0);
	data = init(argv[1]);
	if (build_map(data))
	{
		destroy(data);
		return (0);
	}
	if (start_mlx(data))
		return (0);
	render(data);
	mlx_loop(data->mlx);
	destroy(data);
	return (0);
}
