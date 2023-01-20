/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:53 by esilva-s          #+#    #+#             */
/*   Updated: 2023/01/20 16:19:05 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libs/minilibx/mlx.h"
# include "../libft/libft.h"

typedef struct s_map
{
	char	*patch;
	char	**elements;
	int		height;
	int		col;
	int		player;
}			t_map;

/* check.c */
int		check_args(int argc, char **argv);
int		parse_map(t_map *map);
int		check_walls(t_map *map);
int		check_chars(t_map *map);
int		is_char_valid(t_map *map, int i, int j, char player);

size_t	ft_strlen(const char *s);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strrchr(const char *s, int c);

/*Read map*/
int		read_map(t_map *map);

void	test_mlx(void);

#endif /* CUB3D_H */
