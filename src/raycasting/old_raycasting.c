/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:46:07 by jefernan          #+#    #+#             */
/*   Updated: 2023/03/31 01:13:48 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// Pq usar radiano? 1 radiano (o arco) tem o mesmo tamanho do raio, facilitando alguns cálculos.
void	raycasting(t_data *data)
{
	double	ray_angle;
	int		column_id;
	
	// Calcula o ângulo do primeiro raio subtraindo metade do FOV
	ray_angle = data->player->angle - (FOV_ANGLE / 2);
	column_id = 0;
	while (column_id < NUM_RAYS)// coluna menor que 320 ou largura da tela
	//incrementar até encontrar uma intersecção com parede
	{
		//função que projeta o raio
		project_rays(ray_angle, data, column_id);
		// o próximo raio é o raio atual incrementado
        // pelo FOV_ANGLE / NUM_RAYS
		ray_angle += FOV_ANGLE / NUM_RAYS;
		column_id++;
	}
}

void	project_rays(double ray_angle, t_data *data, int column_id)
{
	if (ray_angle >= 2 * PI)
		ray_angle -= 2 * PI;
	if (ray_angle < 0)
		ray_angle += 2 * PI; 
	where_is_looking(ray_angle, data);
	//intersecção horizontal
	horizontal_intersection(ray_angle, data);
	//intersecção vertical
	vertical_intersection(ray_angle, data);
}

void	where_is_looking(double ray_angle, t_data *data)
{
	// descobrir se esta olhando para baixo ou cima
	data->rays->is_facing_down = (ray_angle > 0 && ray_angle < PI);
	data->rays->is_facing_up = !is_facing_down;
	// descobrir se esta olhando para direita ou esquerda
	data->rasy->is_facing_right = (ray_angle < (0.5 * PI) || ray_angle > (1.5 * PI));
	data->rays->is_facing_left = !data->rays->is_facing_right;
}

void	horizontal_intersection(double ray_angle, t_data *data)
{
	double	intercep_x;//intersecção x, linhas
	double	intercep_y;//intersecção y, colunas
	
	intercep_y = (data->player->pos_y / TILE_SIZE) * TILE_SIZE;
	intercep_x = data->player->pos_x + (intercep_y - data->player->pos_y) / tan(ray_angle);
	if (data->rays->is_facing_down)// pular a linha horizontal atual que está atrás do player e ir para a próxima.
		intercep_y += TILE_SIZE;
	// x step = valor do incremento para proxima intersecção horizontal
	data->rays->y_hrz_step = TILE_SIZE;
	data->rays->x_hrz_step = TILE_SIZE / tan(ray_angle);
	if (data->rays->is_facing_up)//vamos inverter o ystep para negativo para subir e não descer no grid.
		data->rays->y_hrz_step *= -1;
	//vamos inverter o xstep para negativo para ir para a esquerda e não para a direita no grid.
	if (data->rays->is_facing_left && data->rays->x_hrz_step > 0)
		data->rays->x_hrz_step *= -1;
	if (data->rays->is_facing_right && data->rays->x_hrz_step < 0)
		data->rays->x_hrz_step *= -1;
	while (intercep_x >= 0 && intercep_x < (data->height * TILE_SIZE) &&
			intercep_y >= 0 && intercep_y < (data->width * TILE_SIZE))
	{
		if (data->rays->is_facing_up)
			intercep_y -= 1;
		//verificar se não há colisão com uma parede nos lados horizontais
		if (wall_collision(intercep_x, intercep_y, data))
		{
			//encontrou parede -> ponto de colisão - hrz_wall_x - y
			data->rays->hrz_wall_x = intercep_x;
			data->rays->hrz_wall_y = intercep_y;
			data->rays->found_hrz_wall = true;//encontrou a parede
			break ;
		}
		intercep_x += data->rays->x_hrz_step;
		intercep_y += data->rays->y_hrz_step;
	}
}

void	vertical_intersection(double ray_angle, t_data *data)
{
	double	intercep_x;
	double	intercep_y;

	intercep_x = (data->player->pos_x / TILE_SIZE) * TILE_SIZE;
	//para pular a linha vertical atual que está atrás do player e ir para a próxima.
	if (data->rays->is_facing_right)
		intercep_x += TILE_SIZE;
	intercep_y = data->player->pos_y + (intercep_x - data->player->pos_x) * tan(ray_angle);
	// y step = valor de incremento para verificar a próxima intersecção vertical
	data->rays->x_vert_step = TILE_SIZE;
	//se left -> inverter o xstep para negativo para voltar e não ir para frente no grid.
	if (data->rays->is_facing_left)
		data->rays->x_vert_step *= -1;
	data->rays->y_vert_step = TILE_SIZE * tan(ray_angle);
	if (data->rays->is_facing_up && data->rays->y_vert_step > 0)
		data->rays->y_vert_step *= -1;
	if (data->rays->is_facing_down && data->rays->y_vert_step < 0)
		data->rays->y_vert_step *= -1;
	while (intercep_x >= 0 && intercep_x < (data->height * TILE_SIZE) &&
			intercep_y >= 0 && intercep_y < (data->width * TILE_SIZE))
	{
		//diminuir 1 pixel para garantir que o ponto de verificação esteja dentro da matriz.
		if (data->rays->is_facing_left)
			data->rays->intercep_x -= 1;
		if (wall_collision(intercep_x, intercep_y, data))
		{
			data->rays->vert_wall_x = intercep_x;
			data->rays->vert_wall_y = intercep_y;
			data->rays->found_vert_wall = true;
			break ;
		}
		intercep_x += data->rays->x_vert_step;
		intercep_y += data->rays->y_vert_step;
	}

}

//teorema de pitágoras
double	dist_between_points(double x1, double y1, double x2, double y2)
{
	double ret;
	
	ret = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (ret);	
}

//-> Vamos calcular ambas as distâncias, vertical e horizontal a partir do player até o ponto de colisão, 
//caso não haja colisão atribuímos o valor da distância para o MAX_INT para garantir que seja sempre maior que a outra distância comparada.
void	calc_dist(t_data *data, double ray_angle, int column_id)
{
	if (data->rays->found_hrz_wall)
		data->rays->hrz_dist = dist_between_points(data->player->pos_x, data->player->pos_y, data->rays->hrz_wall_x, data->rays->hrz_wall_y);
	else
		data->rays->hrz_dist = MAX_INT;
	if (data->rays->found_vert_wall)
		data->rays->vert_dist = dist_between_points(data->player->pos_x, data->player->pos_y, data->rays->vert_wall_x, data->rays->vert_wall_x);
	else
		data->rays->vert_dist = MAX_INT;
	//calculamos a menor distância entre a colisão vertical e horizontal e armazenamos os valores 
	//da menor delas, checando se a colisão foi vertical ou horizontal.
	if (data->rays->vert_dist < data->rays->hrz_dist)
	{
		data->rays[column_id]->wall_hitx = data->ray->vert_wall_x;
		data->rays[column_id]->wall_hity = data->ray->vert_wall_y;
		data->rays[column_id]->distance = data->ray->vert_dist;
		data->rays[column_id]->was_hit_vert = true;
	}
	else
	{
		data->rays[column_id]->wall_hitx = data->ray->hrz_wall_x;
		data->rays[column_id]->wall_hity = data->ray->hrz_wall_y;
		data->rays[column_id]->distance = data->ray->hrz_dist;
		data->rays[column_id]->was_hit_vert = false;
	}
	data->rays[column_id]->ray_angle = ray_angle;
}

int	wall_collision(double x, double y, t_data *data)
{
	int	i;
	int	j;

	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE );
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || WINDOW_HEIGHT)
		return (-1);
	return (data->map->map_matrix[j][i]);
}

void	init_ray(t_data *data)
{
	data->rays->found_vert_wall = false;
	data->rays->found_hrz_wall = false;
	data->rays->hrz_wall_x = 0;
	data->rays->hrz_wall_y = 0;
	data->rays->vert_wall_x = 0;
	data->rays->vert_wall_y = 0;
}

//Calculando a distância do player até o plano de projeção:
distanceProjPlane = (WINDOW_WIDTH / 2) / Math.tan(FOV_ANGLE / 2);
//Calculando altura da faixa da parede a ser projetada:
wallStripeHeight = (TILE_SIZE / ray.distance) * distanceProjPlane;

void	render_3d_projected_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		data->render->correct_wall_dist = data->rays[i].distance * cos(data->rays[i].ray_angle - data->player->angle);
		data->render->dist_proj_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		data->render->wall_stripe_height = (TILE_SIZE / data->render->correct_wall_dist) * data->render->dist_proj_plane;
		
		i++;
	}
}