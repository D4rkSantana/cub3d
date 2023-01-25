/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:44:38 by jefernan          #+#    #+#             */
/*   Updated: 2023/01/25 02:25:20 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture(char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
		get_north(str);
	// if (!ft_strncmp(str, "SO ", 3))
	// 	get_south(str);
	// if (!ft_strncmp(str, "WE ", 3))
	// 	get_west(str);
	// if if (!ft_strncmp(str, "EA ", 3))
	// 	get_east(str);
}

void	get_north(char *str)
{
	t_map 	*map;
	char	*line;
	
	line = ft_strtrim(str, "NO \n");
	ft_strlcpy(map->no_path, line, ft_strlen(line));
}

void	get_south(char *str)
{
	t_map 	*map;
	char	*line;
	
	line = ft_strtrim(str, "SO \n");
	ft_strlcpy(map->no_path, line, ft_strlen(line));
}

void	get_west(char *str)
{
	t_map 	*map;
	char	*line;
	
	line = ft_strtrim(str, "WE \n");
	ft_strlcpy(map->no_path, line, ft_strlen(line));
}

void	get_east(char *str)
{
	t_map 	*map;
	char	*line;
	
	line = ft_strtrim(str, "EA \n");
	ft_strlcpy(map->no_path, line, ft_strlen(line));
}