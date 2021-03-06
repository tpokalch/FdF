/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_points.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpokalch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:37:27 by tpokalch          #+#    #+#             */
/*   Updated: 2019/02/20 21:37:39 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_vector	**initialize_points(int height)
{
	int			i;
	t_vector	**ret;

	i = 0;
	ret = (t_vector **)malloc(sizeof(t_vector *) * height);
	while (i < height)
	{
		*(ret + i) = NULL;
		i++;
	}
	return (ret);
}
