/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:11:14 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/01 22:59:49 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_collision(double x, double y, t_data *data)
{
	int	i;
	int	j;

	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE);
	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT)
		return (-1);
	if (data->map->map_matrix[i][j] == '1')
		return (1);
	else
		return (0);
}

void	horizontal_intersection(double ray_angle, t_data *data, t_ray *ray)
{
	int	intercep_x;
	int	intercep_y;
	
	intercep_y = data->player->pos_y / TILE_SIZE;
	intercep_y = intercep_y * TILE_SIZE;
	intercep_x = data->player->pos_x + ((data->player->pos_y - intercep_y) / tan(ray_angle));

	if (ray->is_facing_down)// pular a linha horizontal atual que está atrás do player e ir para a próxima.
		intercep_y += TILE_SIZE;
	
	// x step = valor do incremento para proxima intersecção horizontal
	ray->y_hrz_step = TILE_SIZE;
	ray->x_hrz_step = TILE_SIZE / tan(ray_angle);

	if (ray->is_facing_up)//vamos inverter o ystep para negativo para subir e não descer no grid.
		ray->y_hrz_step *= -1;

	//vamos inverter o xstep para negativo para ir para a esquerda e não para a direita no grid.
	if (ray->is_facing_left && ray->x_hrz_step > 0)
		ray->x_hrz_step *= -1;
	if (ray->is_facing_right && ray->x_hrz_step < 0)
		ray->x_hrz_step *= -1;

	while (intercep_x >= 0 && intercep_x < (WIN_HEIGHT * TILE_SIZE) &&
			intercep_y >= 0 && intercep_y < (WIN_WIDTH * TILE_SIZE))
	{
		if (ray->is_facing_up)
			intercep_y -= 1;
		//verificar se não há colisão com uma parede nos lados horizontais
		if (wall_collision(intercep_x, intercep_y, data) == 1)
		{
			//encontrou parede -> ponto de colisão - hrz_wall_x - y
			ray->hrz_wall_x = intercep_x;
			ray->hrz_wall_y = intercep_y;
			ray->found_hrz_wall = 1;//encontrou a parede
			break ;
		}
		intercep_x += ray->x_hrz_step;
		intercep_y += ray->y_hrz_step;
	}
}

void	vertical_intersection(double ray_angle, t_data *data, t_ray *ray)
{
	int	intercep_x;
	int	intercep_y;

	intercep_x = data->player->pos_x / TILE_SIZE;
	intercep_x = intercep_x * TILE_SIZE;
	//para pular a linha vertical atual que está atrás do player e ir para a próxima.
	if (ray->is_facing_right)
		intercep_x += TILE_SIZE;
	intercep_y = data->player->pos_y + (intercep_x - data->player->pos_x) * tan(ray_angle);

	// y step = valor de incremento para verificar a próxima intersecção vertical
	ray->x_vert_step = TILE_SIZE;
	//se left -> inverter o xstep para negativo para voltar e não ir para frente no grid.
	if (ray->is_facing_left)
		ray->x_vert_step *= -1;
	ray->y_vert_step = TILE_SIZE * tan(ray_angle);
	if (ray->is_facing_up && ray->y_vert_step > 0)
		ray->y_vert_step *= -1;
	if (ray->is_facing_down && ray->y_vert_step < 0)
		ray->y_vert_step *= -1;

	while (intercep_x >= 0 && intercep_x < (WIN_HEIGHT * TILE_SIZE) &&
			intercep_y >= 0 && intercep_y < (WIN_WIDTH * TILE_SIZE))
	{
		//diminuir 1 pixel para garantir que o ponto de verificação esteja dentro da matriz.
		if (ray->is_facing_left)
			intercep_x -= 1;
		if (wall_collision(intercep_x, intercep_y, data) == 1)
		{
			ray->vert_wall_x = intercep_x;
			ray->vert_wall_y = intercep_y;
			ray->found_vert_wall = 1;
			break ;
		}
		intercep_x += ray->x_vert_step;
		intercep_y += ray->y_vert_step;
	}
}