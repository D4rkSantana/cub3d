/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:42:50 by jefernan          #+#    #+#             */
/*   Updated: 2023/02/04 22:55:13 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(char *error_msg, t_data *data)
{
	printf("Error, %s\n", error_message);
	if (data != NULL)
		destroy(data);
	exit(1);
}