/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:10:19 by jefernan          #+#    #+#             */
/*   Updated: 2023/03/22 00:12:30 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int key, t_data *data)
{
	if (key == KEY_W)
		moviments(data, UP);
	if (key == KEY_S)
		moviments(data, DOWN);
	if (key == KEY_A)
		moviments(data, LEFT);
	if (key == KEY_D)
		moviments(data, RIGHT);
	if (key == KEY_LEFT)
		rotate(data, KEY_LEFT);
	if (key == KEY_RIGHT)
		rotate(data, KEY_RIGHT);
	if (key == KEY_ESC || key == KEY_Q)
		destroy(data);
	return (0);
}
