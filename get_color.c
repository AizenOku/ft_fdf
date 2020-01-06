/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <ihuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 18:24:49 by ihuang            #+#    #+#             */
/*   Updated: 2019/01/07 03:47:17 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** percent: used to find percentage between 2 points with known colors
*/

static double	percent(int start, int end, int current)
{
	double		placement;
	double		distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

/*
** get_light essentially gets the correct percentage between the 0 - 255
** between color0 and color1
*/

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				get_color(t_fdf *fdf, int x, int time)
{
	int			r;
	int			b;
	int			g;
	int			start;
	double		p;

	if (time == 1)
	{
		p = percent(fdf->map->min_height, fdf->map->max_height, x);
		start = fdf->base_color0;
		fdf->end = COLOR1;
	}
	else
	{
		p = percent(fdf->x0, fdf->x1, x);
		start = fdf->color0;
		fdf->end = fdf->color1;
	}
	r = get_light((start >> 16) & 0xFF, (fdf->end >> 16) & 0xFF, p);
	g = get_light((start >> 8) & 0xFF, (fdf->end >> 8) & 0xFF, p);
	b = get_light((start) & 0xFF, (fdf->end) & 0xFF, p);
	return ((r << 16) | (g << 8) | b);
}
