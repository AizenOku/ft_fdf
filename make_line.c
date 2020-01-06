/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <ihuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:16:55 by ihuang            #+#    #+#             */
/*   Updated: 2019/01/07 04:11:59 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** plot function draws a pixel on screen of given brightness
** 0 <= brightness <= 1.
*/

static void		plott(t_fdf *fdf, double x, double y, double brightness)
{
	int			color;
	int			red;
	int			green;
	int			blue;

	red = (fdf->curr_color & 0xFF0000) >> 16;
	red *= brightness;
	green = (fdf->curr_color & 0xFF00) >> 8;
	green *= brightness;
	blue = (fdf->curr_color & 0xFF);
	blue *= brightness;
	color = (red << 16 | green << 8 | blue);
	image_set_pixel(fdf->img, x, y, color);
}

static void		make_line2(t_fdf *fdf, t_vector v0, t_vector v1, \
		int steep)
{
	double		gradient;
	double		intersect_y;
	int			x;

	gradient = (v1.x == v0.x) ? 1 : (v1.y - v0.y) / (v1.x - v0.x);
	x = fdf->x0;
	intersect_y = v0.y;
	while (x <= fdf->x1)
	{
		fdf->curr_color = get_color(fdf, x, 2);
		if (steep)
		{
			plott(fdf, ipart(intersect_y), x, rfpart(intersect_y));
			plott(fdf, ipart(intersect_y) + 1, x, fpart(intersect_y));
		}
		else
		{
			plott(fdf, x, ipart(intersect_y), rfpart(intersect_y));
			plott(fdf, x, ipart(intersect_y) + 1, fpart(intersect_y));
		}
		intersect_y += gradient;
		x++;
	}
}

static void		swap_double(double *i1, double *i2)
{
	double	temp;

	temp = *i1;
	*i1 = *i2;
	*i2 = temp;
}

void			make_line(t_fdf *fdf, t_vector v0, t_vector v1)
{
	int			steep;

	fdf->color0 = v0.color;
	fdf->color1 = v1.color;
	steep = absolute(v1.y - v0.y) > absolute(v1.x - v0.x);
	if (steep)
	{
		swap_double(&(v0.x), &(v0.y));
		swap_double(&(v1.x), &(v1.y));
	}
	if (v0.x > v1.x)
	{
		swap_double(&(v0.x), &(v1.x));
		swap_double(&(v0.y), &(v1.y));
		swap(&(fdf->color0), &(fdf->color1));
	}
	fdf->x0 = v0.x;
	fdf->x1 = v1.x;
	make_line2(fdf, v0, v1, steep);
}
