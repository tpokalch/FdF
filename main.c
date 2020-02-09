/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpokalch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:32:47 by tpokalch          #+#    #+#             */
/*   Updated: 2019/02/20 22:28:32 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ginit(t_global *g)
{
	g->width = 600;
	g->height = 450;
	g->nr.x = 12;
	g->nr.y = -6;
	g->nr.z = 4;
	g->nr.len = 10;
	g->u = 0;
	g->l = 0;
	g->col = 4;
}

int		clean_destroy(t_global *p)
{
	mlx_destroy_image(p->mlx_ptr, p->img_ptr);
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	free_points(p->points);
	return (1);
}

int		key_press(int k, void *param)
{
	t_global *p;

	p = param;
	ft_bzero((int *)p->data_ptr, p->sz_l * p->height);
	if (k == 13 || k == 1)
		((p)->nr).x = ((p)->nr).x + 2 * (k == 13) - 1;
	else if (k == 2 || k == 0)
		((p)->nr).y = ((p)->nr).y + 2 * (k == 2) - 1;
	else if (k == 14 || k == 12)
		((p)->nr).z = ((p)->nr).z + 2 * (k == 14) - 1;
	else if (k == 15 || k == 17)
		((p)->nr).len = ((p)->nr).len * (1.1 * (k == 15) + 1 / 1.1 * (k == 17));
	else if (k == 123 || k == 124)
		p->l = (p)->l - 10 * (2 * (k == 123) - 1);
	else if (k == 126 || k == 125)
		(p)->u = (p)->u - 10 * (2 * (k == 126) - 1);
	else if (k == 8)
		p->col++;
	else if (k == 53)
		exit(clean_destroy(p));
	project((p->nr), p);
	return (1);
}

int		main(int argc, char **argv)
{
	t_global g;

	if (argc != 2)
		return (o_putstr("Usage : ./fdf <filename>\n", NULL, NULL));
	if (!(g.points = create_points(*(argv + 1))))
		return (o_putstr("Error\n", NULL, NULL));
	g.mlx_ptr = mlx_init();
	ginit(&g);
	g.win_ptr = mlx_new_window(g.mlx_ptr, g.width, g.height, "fdf");
	g.img_ptr = mlx_new_image(g.mlx_ptr, g.width, g.height);
	g.data_ptr = (int *)mlx_get_data_addr(g.img_ptr, &g.bpp, &g.sz_l, &g.e);
	project((g.nr), &g);
	mlx_string_put(g.mlx_ptr, g.win_ptr, 1000, 1200, 0xFFFFFF,
	"Hello! Use WA-SD-QE to rotate image, RT to zoom, arrows to shift,");
	mlx_string_put(g.mlx_ptr, g.win_ptr, 1200, 1230, 0xFFFFFF,
	"C to change color");
	mlx_hook(g.win_ptr, 2, 2, key_press, &g);
	mlx_loop(g.mlx_ptr);
	return (0);
}
