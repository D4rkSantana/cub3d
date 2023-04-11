/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:20 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/11 02:48:38 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_image	*load_xpm(t_data *data, char *path)
{
	t_image	*result;
	int		w;
	int		h;

	result = NULL;
	result = ft_calloc(sizeof(t_image), 1);
	result->pont = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (result->pont == NULL)
	{
		printf("Error\ntexture file is wrong\n");
		free(result);
		return (NULL);
	}
	result->data_img = mlx_get_data_addr(result->pont,
			&result->bpp, &result->size_line, &result->endian);
	if (result->data_img == NULL)
	{
		printf("Error\nMlx data image error\n");
		mlx_destroy_image(data->mlx, result->pont);
		free(result);
		return (NULL);
	}
	return (result);
}

static int	load_textures(t_data *data)
{
	data->n_texture = load_xpm(data, data->map->no_path);
	if (data->n_texture == NULL)
		return (1);
	data->s_texture = load_xpm(data, data->map->so_path);
	if (data->s_texture == NULL)
		return (1);
	data->e_texture = load_xpm(data, data->map->ea_path);
	if (data->e_texture == NULL)
		return (1);
	data->w_texture = load_xpm(data, data->map->we_path);
	if (data->w_texture == NULL)
		return (1);
	return (0);
}

int	render_loop(t_data **data)
{
	render(*data);
	return (0);
}

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
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	if (!data->win)
	{
		printf("Error\nNo graphical interface.\n");
		destroy(data);
		exit(1);
	}
	data->image->pont = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->image->patch = mlx_get_data_addr(data->image->pont, &data->image->bpp,
			&data->image->size_line, &data->image->endian);
	if (load_textures(data))
	{
		destroy(data);
		exit(1);
	}
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

static int	close_game(t_data *data)
{
	mlx_loop_end(data->mlx);
	destroy(data);
	return (0);
}

/*
Main

check args
init data
build data
build mlx
destroy

*/

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv))
		return (0);
	data = init(argv[1]);
	if (build_data(data))
	{
		destroy(data);
		return (0);
	}
	get_player(data);
	if (start_mlx(data))
		return (0);
	mlx_hook(data->win, KEY_PRESS, 1L << 0, key_hook, data);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, close_game, data);
	mlx_loop_hook(data->mlx, &render_loop, &data);
	mlx_loop(data->mlx);
	destroy(data);
	return (0);
}
