/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 20:00:55 by ihuang            #+#    #+#             */
/*   Updated: 2019/01/07 04:08:33 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	free_map(t_fdf **fdf)
{
	int				y;

	if ((*fdf)->map)
	{
		if ((*fdf)->map->xy_map)
		{
			y = 0;
			while (y < (*fdf)->map->rows)
				free((*fdf)->map->xy_map[y++]);
			free((*fdf)->map->xy_map);
			(*fdf)->map->xy_map = NULL;
		}
		if ((*fdf)->map->vector)
		{
			y = 0;
			while (y < (*fdf)->map->rows)
				free((*fdf)->map->vector[y++]);
			free((*fdf)->map->vector);
			(*fdf)->map->vector = NULL;
		}
		free((*fdf)->map);
		(*fdf)->map = NULL;
	}
}

int					close_program(t_fdf *fdf)
{
	free_all(&fdf);
	die("Bye!");
	return (0);
}

/*
** list of things to free:
** 1. fdf->img
** 2. fdf->map
** 	- xy_map
** 	- vector
** 3. fdf->cam
** 4. fdf
*/

void				free_all(t_fdf **fdf)
{
	free_image(*fdf, (*fdf)->img);
	free_map(fdf);
	if ((*fdf)->cam)
	{
		free((*fdf)->cam);
		(*fdf)->cam = NULL;
	}
	free(*fdf);
	*fdf = NULL;
}

void				die(char *message)
{
	ft_putendl(message);
	exit(0);
}

void				free_all_and_die(t_fdf **fdf, char *message)
{
	free_all(fdf);
	die(message);
}
