/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:47:35 by jefernan          #+#    #+#             */
/*   Updated: 2023/02/08 17:51:22 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_color_floor(char *color, t_map *map)
{
	char	*temp;

	temp = ft_strtrim(color, "F \n");
	if (map->cl_floor == NULL)
		map->cl_floor = ft_strdup(temp);
	ft_strdel(&temp);
}

void	get_color_ceilling(char *color, t_map *map)
{
	char	*temp;

	temp = ft_strtrim(color, "C \n");
	if (map->cl_ceilling == NULL)
		map->cl_ceilling = ft_strdup(temp);
	ft_strdel(&temp);
}
