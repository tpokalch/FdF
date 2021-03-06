/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpokalch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:23:33 by tpokalch          #+#    #+#             */
/*   Updated: 2018/11/11 22:08:32 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putarr(char **arr)
{
	int j;

	j = 0;
	while (*(arr + j))
	{
		ft_putstr((*(arr + j)));
		j++;
		write(1, "\n", 1);
	}
}
