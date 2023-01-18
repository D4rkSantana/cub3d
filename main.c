/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefernan <jefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:49:20 by esilva-s          #+#    #+#             */
/*   Updated: 2023/01/19 00:51:41 by jefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (check_args(argc, argv))
		return (0);
//	test_mlx();
	printf("Hello!\n");
	return (0);
}

void	test_mlx()
{
	void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Cub3d");
    mlx_loop(mlx);
}