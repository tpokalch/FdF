/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpokalch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:08:04 by tpokalch          #+#    #+#             */
/*   Updated: 2019/02/20 21:10:10 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			line_in_bounds(t_vector s, t_vector e, t_global *g)
{
	return (!((s.x > g->width) && (e.x > g->width))
	&& !(s.x < 0 && e.x < 0)
	&& !((s.y >= g->height) && (e.y >= g->height))
	&& !(s.y < 0 && e.y < 0));
}	

t_vector	transform(int x, int y, t_vector a, t_global *g)
{
	t_vector ret;
	t_matrix m;

	m.x11 = cos((a.z / (float)12)) * cos(a.y / (float)12);
	m.x12 = -sin(a.z / (float)12) * cos(a.x / (float)12) +
		(cos(a.z / (float)12)) * sin(a.y / (float)12) * sin(a.x / (float)12);
	m.x13 = sin((a.z / (float)12)) * sin(a.x / (float)12) +
		cos((a.z / (float)(12))) * sin(a.y / (float)12) * cos(a.x / (float)12);
	m.x21 = sin((a.z / (float)12)) * cos(a.y / (float)12);
	m.x22 = cos((a.z / (float)(12))) * cos(a.x / (float)12) +
		sin(a.z / (float)12) * sin(a.y / (float)12) * sin(a.x / (float)12);
	m.x23 = -cos(a.z / (float)12) * sin(a.x / (float)12) +
		sin(a.z / (float)12) * sin(a.y / (float)12) * cos(a.x / (float)12);
	ret.x = round((a.len / ((float)10)) * (
			(*(*(g->points + y) + x)).x * m.x11
			+ (*(*(g->points + y) + x)).y * m.x12
			+ (*(*(g->points + y) + x)).z * m.x13))
			+ 120 + g->l;
	ret.y = round((a.len / ((float)10)) * (
			(*(*(g->points + y) + x)).x * m.x21
			+ (*(*(g->points + y) + x)).y * m.x22
			+ (*(*(g->points + y) + x)).z * m.x23))
			+ 200 + g->u;
	return (ret);
}

t_vector	**project(t_vector angles, t_global *g)
{
	int i;
	int j;
	t_vector p1;
	t_vector p2;
	t_vector p3;

	j = -1;
	while (*(g->points + (++j)) && (i = -1))
	{
		while (++i < (**(g->points + j)).len)
		{
			p1 = transform(i, j, angles, g);
			if (i + 1 < (**(g->points + j)).len ) 
				p2 = transform(i + 1, j, angles, g);
			if (*(g->points + j + 1))
				p3 = transform(i, j + 1, angles, g);
			if (i + 1 < (**(g->points + j)).len && line_in_bounds(p1, p2, g))
				line_to_image(p1, p2, g);
			if (*(g->points + j + 1) && line_in_bounds(p1, p3, g))
				line_to_image(p1, p3, g);
		}
	}
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
	return (g->points);
}
