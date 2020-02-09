/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpokalch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:19:59 by tpokalch          #+#    #+#             */
/*   Updated: 2019/02/20 22:08:47 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				next_num(char *s)
{
	int i;

	i = 0;
	while (*(s + i) == ' ')
		i++;
	while (*(s + i) != ' ' && *(s + i) != '\0')
	{
		if ((*(s + i) < '0' || *(s + i) > '9') && *(s + i) != ' ' && *(s + i) != '-')
			return (-1);
		i++;
	}
	while (*(s + i) == ' ')
		i++;
	return (i);
}

int				file_height(char *filename)
{
	char	*line;
	int		height;
	int		fd;
	int		gnl;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((gnl = get_next_line(fd, &line)))
	{
		if (gnl == -1)
			return (-1);
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int				o_putstr(char *put, char *clean, t_vector **del)
{
	int i;

	i = 0;
	if (clean)
		free(clean);
	if (del)
		free_points(del);
	while (*(put + i) != '\0')
	{
		write(1, put + i, 1);
		i++;
	}
	return (0);
}

int				parse_line(t_vector **a, char *s, int j)
{
	int		i;
	char	*save;

	save = s;
	i = 0;
	*(a + j) = (t_vector *)malloc(sizeof(t_vector) * (ft_strlen(s) + 1));
	while (*s != '\0' && i != -1)
	{
		(*(a + j) + (i))->x = i * 20;
		(*(a + j) + i)->y = j * 20;
		((*(a + j) + i)->z = ft_atoi(s) * 20);
		if (next_num(s) == -1)
		{
			return (o_putstr("File must contain only spaces and numbers\n",
			save, a));
		}
		s = s + next_num(s);
		i++;
	}
	(**(a + j)).len = i;
	if (j > 0 && ((**(a + j)).len != (**(a + j - 1)).len))
		return (o_putstr("File must contain rectangular map\n", save, a));
	return (1);
}

t_vector		**create_points(char *filename)
{
	t_vector	**ret;
	char		*line;
	int			height;
	int			fd;
	int			j;

	j = 0;
	height = file_height(filename);
	if (height == -1)
	{
		ft_putstr("Invalid file or buffer\n");
		return (NULL);
	}
	ret = initialize_points(height + 1);
	fd = open(filename, O_RDONLY);
	while (j < height)
	{
		if (get_next_line(fd, &line) == -1)
			return (NULL);
		if (!(parse_line((ret), line, j)))
			return (NULL);
		free(line);
		j++;
	}
	return (ret);
}
