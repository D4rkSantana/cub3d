/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:15:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/04 22:46:13 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_image	*init_image(void)
{
	t_image	*image;

	image = NULL;
	image = ft_calloc(sizeof(t_image), 1);
	if (image == NULL)
		return (NULL);
	image->pont = NULL;
	image->patch = NULL;
	return (image);
}

static t_map	*init_map(char *patch)
{
	t_map	*map;

	map = NULL;
	map = ft_calloc(sizeof(t_map), 1);
	map->patch = NULL;
	if (patch != NULL)
		map->patch = ft_strdup(patch);
	map->map_matrix = NULL;
	map->nb_lines = 0;
	map->nb_columns = 0;
	map->height_px = 0;
	map->width_px = 0;
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->cl_floor = NULL;
	map->cl_ceilling = NULL;
	return (map);
}

static t_player	*init_player(void)
{
	t_player	*player;

	player = NULL;
	player = ft_calloc(sizeof(t_player), 1);
	if (player == NULL)
		return (NULL);
	player->pos_x = 0;
	player->pos_y = 0;
	player->angle = 0;
	player->turn_speed = (PI / 180);
	return (player);
}

static t_render	*init_render(void)
{
	t_render	*render;

	render = NULL;
	render = ft_calloc(sizeof(t_render), 1);
	if (render == NULL)
		return (NULL);
	render->perp_dist = 0;
	render->dist_proj_plane = 0;
	render->proj_wall_height = 0;
	render->wall_strip_height = 0;
	render->wall_bottom_pixel = 0;
	render->wall_top_pixel = 0;
	return (render);
}

static void	init_rays(t_data *data)
{
	int	index;

	index = 0;
	while (index < NUM_RAYS)
	{
		data->rays[index].ray_angle = 0;
		data->rays[index].hrz_wall_x = 0;
		data->rays[index].hrz_wall_y = 0;
		data->rays[index].y_hrz_step = 0;
		data->rays[index].x_hrz_step = 0;
		data->rays[index].x_vert_step = 0;
		data->rays[index].y_vert_step = 0;
		data->rays[index].vert_wall_x = 0;
		data->rays[index].vert_wall_y = 0;
		data->rays[index].hrz_dist = 0;
		data->rays[index].vert_dist = 0;
		data->rays[index].wall_hitx = 0;
		data->rays[index].wall_hity = 0;
		data->rays[index].distance = 0;
		data->rays[index].was_hit_vert = 0;
		data->rays[index].found_vert_wall = 0;
		data->rays[index].found_hrz_wall = 0;
		data->rays[index].is_facing_down = 0;
		data->rays[index].is_facing_up = 0;
		data->rays[index].is_facing_right = 0;
		data->rays[index].is_facing_left = 0;
		index++;
	}
}

t_data	*init(char *patch)
{
	t_data	*data;

	data = NULL;
	data = ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		return (NULL);
	data->map = init_map(patch);
	data->image = init_image();
	data->player = init_player();
	data->render = init_render();
	init_rays(data);
	data->mlx = NULL;
	data->win = NULL;
	data->close_game = 0;
	return (data);
}
