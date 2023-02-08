/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:52:07 by esilva-s          #+#    #+#             */
/*   Updated: 2023/02/08 12:43:08 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_args(int argc, char **argv)
{
	int		len;
	char	*str;

	if (argc < 2)
	{
		printf("Wrong numbers of arguments\n");
		return (1);
	}
	else
	{
		len = 0;
		str = ft_strrchr(argv[1], '.');
		if (str)
		{
			len = ft_strlen(str);
			if (!ft_memcmp(str, ".cub", len))
				return (0);
		}
		printf("Error\nInvalid map extension. Use .cub\n");
		return (1);
	}
	return (0);
}

int	check_texture(char *str, t_map *map)
{
	char	*temp;
	char	*extension;

	extension = ft_strrchr(str, '.');
	temp = ft_strrchr(str, ' ');
	if (!(ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0
			|| ft_strncmp(str, "WE ", 3) == 0
			|| ft_strncmp(str, "EA ", 3) == 0))
	{
		printf("Error, invalid texture\n");
		return (1);
	}
	if (!(ft_strncmp(temp, " ./textures/", 12) == 0
			&& ft_strncmp(extension, ".xpm\0", 5) == 0))
	{
		printf("Error, invalid texture\n");
		return (1);
	}
	get_texture(str, map);
	return (0);
}

int	verify_count_rgb(int i)
{
	if (i != 3)
	{
		printf("Error, invalid color\n");
		return (1);
	}
	return (0);
}
