/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 03:07:58 by jefernan          #+#    #+#             */
/*   Updated: 2023/04/04 03:12:11 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	normalize_angle(double angle)
{
	if (angle < 0)
		angle += (2 * PI);
	else if (angle > 2 * PI)
		angle -= (2 * PI);
	return (angle);
}