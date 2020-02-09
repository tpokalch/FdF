/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpokalch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:30:15 by tpokalch          #+#    #+#             */
/*   Updated: 2019/02/20 21:37:07 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>

# define ABS(x) ((2 * ((x) > 0) - 1) * (x))
# define STEPX(x) ((x == 0) ? 1 : (ABS((ABS(x) <= 1) + (1 / x) * (ABS(x) > 1))))
# define STEPY(x) (1/x == 0) ? 1 : (ABS((ABS(x) >= 1) + x * (ABS(x) < 1)))
# define MODT(x) (x < 0) ? (2 * M_PI + x) : x

typedef struct		s_matrix
{
	float x11;
	float x12;
	float x13;
	float x21;
	float x22;
	float x23;
}					t_matrix;

typedef struct		s_vector
{
	int		x;
	int		y;
	int		z;
	float	len;
}					t_vector;

typedef struct		s_global
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int		*data_ptr;
	t_vector	**points;
	t_vector	nr;
	int			width;
	int			height;
	int		col;
	int		u;
	int		l;
	int		sz_l;
	int		e;
	int		bpp;
}					t_global;

void				line_to_image(t_vector start, t_vector end, t_global *g);
t_vector			**create_points(char *filename);
t_vector			**project(t_vector angles, t_global *g);
int				file_height(char *filename);
void				free_points(t_vector **pts);
t_vector			transform(int x, int y, t_vector a, t_global *g);
t_vector			**initialize_points(int height);
int				o_putstr(char *message, char *clean, t_vector **save);

#endif
