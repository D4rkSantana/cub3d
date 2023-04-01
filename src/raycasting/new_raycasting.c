/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:54:38 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/01 03:18:05 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//OK
void	where_is_looking(double ray_angle, t_ray *ray)
{
	ray->is_facing_down = (ray_angle > 0 && ray_angle < PI);
	ray->is_facing_up = !ray->is_facing_down;
	ray->is_facing_right = (ray_angle < (PI / 2) || ray_angle > (1.5 * PI));
	ray->is_facing_left = !ray->is_facing_right;
}


int	wall_collision(double x, double y, t_data *data)
{
	int	i;
	int	j;

	i = floor(x / TILE_SIZE);
	j = floor(y / TILE_SIZE);
	if (x < 0 || x > data->width || y < 0 || y > data->height)
		return (-1);
	if (data->map->map_matrix[i][j] == '1')
		return (1);
	else
		return (0);
}

void	horizontal_intersection(double ray_angle, t_data *data, t_ray *ray)
{
	double	intercep_x;//intersecção x, linhas
	double	intercep_y;//intersecção y, colunas
	
	intercep_y = (data->player->pos_y / TILE_SIZE) * TILE_SIZE;
	intercep_x = data->player->pos_x + (intercep_y - data->player->pos_y) / tan(ray_angle);

	
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

	while (intercep_x >= 0 && intercep_x < (data->height * TILE_SIZE) &&
			intercep_y >= 0 && intercep_y < (data->width * TILE_SIZE))
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
	double	intercep_x;
	double	intercep_y;

	intercep_x = (data->player->pos_x / TILE_SIZE) * TILE_SIZE;
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

	while (intercep_x >= 0 && intercep_x < (data->height * TILE_SIZE) &&
			intercep_y >= 0 && intercep_y < (data->width * TILE_SIZE))
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

void	project_rays(t_data *data, double ray_angle, t_ray *ray)
{
	if (ray_angle >= 2 * PI)
		ray_angle -= 2 * PI;
	if (ray_angle < 0)
		ray_angle += 2 * PI; 
	where_is_looking(ray_angle, ray);
	//intersecção horizontal
	horizontal_intersection(ray_angle, data, ray);
	//intersecção vertical
	vertical_intersection(ray_angle, data, ray);
}

double	dist_between_points(double x1, double y1, double x2, double y2)
{
	double ret;
	
	ret = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (ret);	
}

void	calc_dist(t_data *data, double ray_angle, t_ray *ray)
{
	printf("vert x:%.2f y:%.2f \nhoriz x:%.2f y:%.2f\n", ray->vert_wall_x, ray->vert_wall_y, ray->hrz_wall_x, ray->hrz_wall_x);
	printf("vert_c:%d horiz_c:%d\n", wall_collision(ray->vert_wall_x, ray->vert_wall_y, data), wall_collision(ray->hrz_wall_x, ray->hrz_wall_y, data));
	if (ray->found_hrz_wall)
		ray->hrz_dist = dist_between_points(data->player->pos_x, data->player->pos_y, ray->hrz_wall_x, ray->hrz_wall_y);
	else
		ray->hrz_dist = MAX_INT;
	if (ray->found_vert_wall)
		ray->vert_dist = dist_between_points(data->player->pos_x, data->player->pos_y, ray->vert_wall_x, ray->vert_wall_x);
	else
		ray->vert_dist = MAX_INT;
	//calculamos a menor distância entre a colisão vertical e horizontal e armazenamos os valores 
	//da menor delas, checando se a colisão foi vertical ou horizontal.
	if (ray->vert_dist < ray->hrz_dist)
	{
		ray->wall_hitx = ray->vert_wall_x;
		ray->wall_hity = ray->vert_wall_y;
		ray->distance = ray->vert_dist;
		ray->was_hit_vert = 1;
	}
	else
	{
		ray->wall_hitx = ray->hrz_wall_x;
		ray->wall_hity = ray->hrz_wall_y;
		ray->distance = ray->hrz_dist;
		ray->was_hit_vert = 0;
	}
	ray->ray_angle = ray_angle;
}

static char	*creat_color(void)
{
	char	*color;

	color = ft_calloc(sizeof(char), 4);
	color[0] = (char)154;
	color[1] = (char)205;
	color[2] = (char)50;
	return (color);
}

static char	*creat_color1(void)
{
	char	*color;

	color = ft_calloc(sizeof(char), 4);
	color[0] = (char)255;
	color[1] = 0;
	color[2] = 0;
	return (color);
}

static char	*creat_color2(void)
{
	char	*color;

	color = ft_calloc(sizeof(char), 4);
	color[0] = (char)255;
	color[1] = (char)255;
	color[2] = (char)50;
	return (color);
}

static char	*creat_color3(void)
{
	char	*color;

	color = ft_calloc(sizeof(char), 4);
	color[0] = (char)50;
	color[1] = (char)50;
	color[2] = (char)50;
	return (color);
}

void	draw_lines(t_data *data)
{
	int	teste;
	int	index;
	int	j;
	char *color;


	teste = 0;

	index = 0;
	color = creat_color();

	double step_1;
	double step_2;
	double size_total;

	while (index < NUM_RAYS)
	{
		j = 0;
		step_1 = data->height / 4;
		size_total = data->height - data->height / 2;
		step_2 = size_total + step_1;
		//printf("altura:%d dist:%f dist_total:%f s1:%f s2:%f \n", data->height, data->rays[index].distance, size_total, step_1, step_2);
		while (j < step_1)
			j++;
		while (j < step_2)
		{
			draw_pixel_color(data->image, j, index, color);
			j++;
		}
		index++;
	}
	/*
	while (index < NUM_RAYS)
	{
		j = 0;
		step_1 = (data->rays[index].distance * 5) / 2;
		size_total = data->height - (data->rays[index].distance * 5);
		step_2 = size_total + step_1;
		printf("altura:%d dist:%f dist_total:%f s1:%f s2:%f \n", data->height, data->rays[index].distance, size_total, step_1, step_2);
		while (j < step_1)
			j++;
		while (j < step_2)
		{
			draw_pixel_color(data->image, index, j, color);
			j++;
		}
		index++;
	}
	*/
	ft_strdel(&color);
}

void    render_3d_projected_walls(t_data *data)
{
    int    x;
    int    y;
    int    color_buffer;
	char	*color1 = creat_color1();
	char	*color2 = creat_color2();
	char	*color3 = creat_color3();

    x = 0;
    while (x < NUM_RAYS)
    {

        data->render->perp_dist = data->rays[x].distance * cos(data->rays[x].ray_angle - data->player->angle);

		if (tan(FOV_ANGLE / 2) != 0)
        	data->render->dist_proj_plane = (data->width / 2) / tan(FOV_ANGLE / 2);

        data->render->proj_wall_height = (TILE_SIZE / data->render->perp_dist);
        data->render->wall_strip_height = (int)data->render->proj_wall_height;
		
        data->render->wall_top_pixel = (data->height / 2) - (data->render->wall_strip_height);

        if (data->render->wall_top_pixel < 0)
            data->render->wall_top_pixel = 0;
        data->render->wall_bottom_pixel = (data->height / 2) + (data->render->wall_strip_height);
        if (data->render->wall_bottom_pixel > data->height)
            data->render->wall_bottom_pixel = data->height;

		printf("Win W:%d H%d\n", data->width, data->height);
		printf("Image W:%d H:%d\n", data->image->width, data->image->height);
        // desenha o céu a partir da posição 0 até a posição wallTopPixel
        y = 0;
        while (y < data->render->wall_top_pixel )
        {
            //color_buffer[(data->width * y) + i] = 0xFF333333;
			draw_pixel_color(data->image, y, x, color1);
            y++;
        }
        // desenha a parede da posição wallTopPixel até a posição wallBottomPixel
        y = data->render->wall_top_pixel;
        while (y < data->render->wall_bottom_pixel)
        {
			/*
            if (color_buffer[(data->width * y) + i] = data->rays[i].was_hit_vert)
                color_buffer = 0xFFFFFFFF;
            else
                color_buffer = 0xFFCCCCCC;
			*/
			draw_pixel_color(data->image,y, x, color3);
            y++;
        }
        // desenha o piso da posição wallBottomPixel até a posição data->height
        y = data->render->wall_bottom_pixel;

        while (y < data->height)
        {
            //color_buffer[(data->width * y) + i] = 0xFF777777;
			draw_pixel_color(data->image,y, x, color2);
            y++;
        }

        x++;
    }
}

void	raycasting(t_data *data)
{
	double	ray_angle;
	int		column_id;
	
	ray_angle = data->player->angle - (FOV_ANGLE / 2);
	column_id = 0;
	while (column_id < NUM_RAYS)
	{

		if (ray_angle < 0)
			ray_angle = 2 * PI - ray_angle;
		if (ray_angle > 2 * PI)
			ray_angle = 0;
		project_rays(data, ray_angle, &data->rays[column_id]);
		calc_dist(data, ray_angle, &data->rays[column_id]);
		//printf("angle: %f ", ray_angle);
		ray_angle += FOV_ANGLE / NUM_RAYS;
		//printf("new angle: %f em graus %f \n", ray_angle, ray_angle * (180 / PI));
		column_id++;
	}
	//render_3d_projected_walls(data);

	//draw_lines(data);
	
	//teste
/*
	double temp;

	column_id = 0;
	printf("inicio\n");
	while (column_id < NUM_RAYS)
	{
		temp = data->rays[column_id].distance;
		printf("ray[%d] dist: %f\n",column_id, temp);
		column_id++;
	}
	printf("\nFim\n");
*/
	close(1);

	//fim teste
}