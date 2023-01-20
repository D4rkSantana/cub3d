/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:52:07 by esilva-s          #+#    #+#             */
/*   Updated: 2023/01/20 01:03:39 by jefernan         ###   ########.fr       */
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
