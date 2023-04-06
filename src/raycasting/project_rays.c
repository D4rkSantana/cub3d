/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 00:49:24 by esilva-s          #+#    #+#             */
/*   Updated: 2023/04/06 17:20:19 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	where_is_looking(double ray_angle, t_ray *ray)
{
	ray->is_facing_up = (ray_angle >= 0 && ray_angle <= PI);
	ray->is_facing_down = !ray->is_facing_up;
	ray->is_facing_right = (ray_angle <= (PI / 2) || ray_angle >= (1.5 * PI));
	ray->is_facing_left = !ray->is_facing_right;
}

void	project_rays(t_data *data, double ray_angle, t_ray *ray)
{
	where_is_looking(ray_angle, ray);
	horizontal_intersection(ray_angle, data, ray);
	vertical_intersection(ray_angle, data, ray);
}
