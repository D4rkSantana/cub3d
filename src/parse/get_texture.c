/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:44:38 by jefernan          #+#    #+#             */
/*   Updated: 2023/01/27 02:34:05 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture(char *str)
{
	t_map	*map;

	if (ft_strncmp(str, "NO ", 3) == 0)
		get_north(str, map);
	if (ft_strncmp(str, "SO ", 3) == 0)
		get_south(str, map);
	if (ft_strncmp(str, "WE ", 3) == 0)
		get_west(str, map);
	if (ft_strncmp(str, "EA ", 3) == 0)
		get_east(str, map);
}

void	get_north(char *str, t_map *map)
{
	char	*temp;
	
	temp = ft_strtrim(str, "NO \n");
	if (map->no_path == NULL)
		map->no_path = ft_strdup(temp);
	ft_strdel(&temp);
}

void	get_south(char *str, t_map *map)
{
	char	*temp;
	
	temp = ft_strtrim(str, "SO \n");
	if (map->so_path == NULL)
		map->so_path = ft_strdup(temp);
	ft_strdel(&temp);
}

void	get_west(char *str, t_map *map)
{
	char	*temp;
	
	temp = ft_strtrim(str, "WE \n");
	if (map->we_path == NULL)
		map->we_path = ft_strdup(temp);
	ft_strdel(&temp);
}

void	get_east(char *str, t_map *map)
{
	char	*temp;
	
	temp = ft_strtrim(str, "EA \n");
	if (map->ea_path == NULL)
		map->ea_path = ft_strdup(temp);
	ft_strdel(&temp);
}