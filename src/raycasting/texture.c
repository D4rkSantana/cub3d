/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:17:05 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/10 00:33:29 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	calcule_off_x(t_data *data, t_ray *ray)
{
	int	offset_x;

	if (ray->vertical_wall == 1)
		offset_x = (int)floor(ray->vert->wall_y) % TILE_SIZE;
	else
		offset_x = (int)floor(ray->hrz->wall_x) % TILE_SIZE;
	return (offset_x);
}

int	calcule_off_y(int y, double wall_height, t_ray *ray)
{
	int	offset_y;
	int	distance_top;
	

	if (wall_height <= 0)
		return(0);
	distance_top = y + (wall_height / 2) - (WIN_HEIGHT / 2);

	offset_y = distance_top * (TILE_SIZE / wall_height);
	return (offset_y);
}

/*

// calculate the distance to the projection plane
distanceProjectionPlane = (WINDOW_WIDTH / 2) / Math.tan(FOV_ANGLE / 2);

        // projected wall height
        var wallStripeHeight = (TILE_SIZE / correctWallDistance) * distanceProjectionPlane;

*/

t_image	*load_xpm(t_data *data, char *path)
{
	t_image *result;
	int w;
	int h;

	result = NULL;
	result = ft_calloc(sizeof(t_image), 1);
	result->pont = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (result->pont == NULL)
	{
		printf("Textura error\n");
		return (NULL);
	}
	result->data_img = mlx_get_data_addr(result->pont,
			&result->bpp, &result->size_line, &result->endian);
	if (result->data_img == NULL)
	{
		printf("data image error\n");
		return (NULL);
	}
	return (result);
}

void	load_textures(t_data *data)
{
	data->n_texture = load_xpm(data, data->map->no_path);
	data->s_texture = load_xpm(data, data->map->so_path);
	data->e_texture = load_xpm(data, data->map->ea_path);
	data->w_texture = load_xpm(data, data->map->we_path);
}