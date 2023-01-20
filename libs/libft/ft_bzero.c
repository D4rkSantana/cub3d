/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 12:56:59 by esilva-s          #+#    #+#             */
/*   Updated: 2022/03/06 19:00:48 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}
