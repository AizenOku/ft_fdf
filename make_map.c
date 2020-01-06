/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:53:58 by ihuang            #+#    #+#             */
/*   Updated: 2019/01/07 04:05:28 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		malloc_map_2d_arrays(t_fdf *fdf)
{
	int		i;
	int		rows;
	int		cols;

	i = 0;
	rows = fdf->map->rows;
	cols = fdf->map->cols;
	fdf->map->vector = (t_vector **)malloc(sizeof(t_vector *) * rows);
	fdf->map->xy_map = (int**)malloc(sizeof(int *) * rows);
	while (i < rows)
	{
		fdf->map->xy_map[i] = (int*)malloc(sizeof(int) * cols);
		fdf->map->vector[i] = (t_vector *)malloc(sizeof(t_vector) * cols);
		i++;
	}
}

static void		move_ptr(char **ptr)
{
	while (ft_isdigit(**ptr) || **ptr == '-')
		(*ptr)++;
	while (**ptr == ' ')
		(*ptr)++;
}

static void		fill_vector_at_ij(t_fdf *fdf, int i, int j, char **ptr)
{
	int		num;

	num = ft_atoi(*ptr);
	fdf->map->xy_map[i][j] = num;
	fdf->map->vector[i][j].x = j;
	fdf->map->vector[i][j].y = i;
	fdf->map->vector[i][j].z = -num;
	fdf->map->min_height = MIN(num, fdf->map->min_height);
	fdf->map->max_height = MAX(num, fdf->map->max_height);
	move_ptr(ptr);
}

static int		make_map2(t_fdf *fdf, char *file_name, char *line)
{
	int		fd;
	int		i;
	int		j;
	char	*ptr;

	if ((fd = open(file_name, O_RDWR)) < 0)
		die("Error opening file or invalid file name");
	malloc_map_2d_arrays(fdf);
	i = 0;
	while (gnl(fd, &line))
	{
		j = -1;
		ptr = line;
		while (++j < fdf->map->cols)
			fill_vector_at_ij(fdf, i, j, &ptr);
		i++;
		free(line);
	}
	close(fd);
	update_vector_colors(fdf);
	return (1);
}

int				make_map_and_vectors(t_fdf *fdf, char *file_name)
{
	int		fd;
	int		i;
	char	*line;

	fdf->map->rows = 0;
	fdf->map->cols = -1;
	fdf->map->max_height = 0;
	fdf->map->min_height = 0;
	if ((fd = open(file_name, O_RDWR)) < 0)
		die("Error opening file or invalid file name");
	while (gnl(fd, &line))
	{
		ft_putendl(line);
		i = ft_wordcount(line, ' ');
		if (fdf->map->cols != -1 && fdf->map->cols != i)
			die("Invalid map");
		fdf->map->cols = i;
		fdf->map->rows++;
		free(line);
	}
	close(fd);
	make_map2(fdf, file_name, line);
	return (1);
}
