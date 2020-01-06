/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:37:49 by ihuang            #+#    #+#             */
/*   Updated: 2019/01/07 04:06:28 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** returns the vector at y, x of 2D vector array in fdf
*/

static t_vector	get_vector(int y, int x, t_fdf *fdf)
{
	return (fdf->map->vector[y][x]);
}

static t_vector	rotate(t_vector p, t_cam *r)
{
	t_vector	v;
	double		x;
	double		y;
	double		z;

	x = p.x;
	z = p.z;
	v.x = cos(r->y) * x + sin(r->y) * z;
	v.z = -sin(r->y) * x + cos(r->y) * z;
	y = p.y;
	z = v.z;
	v.y = cos(r->x) * y - sin(r->x) * z;
	v.z = sin(r->x) * y + cos(r->x) * z;
	v.color = p.color;
	return (v);
}

/*
** scales and rotates the vector
*/

static t_vector	project_vector(t_vector v, t_fdf *fdf)
{
	v.x -= (double)(fdf->map->cols - 1) / 2.0f;
	v.y -= (double)(fdf->map->rows - 1) / 2.0f;
	v.z += (double)(fdf->map->min_height + fdf->map->max_height) / 2.0f;
	v = rotate(v, fdf->cam);
	v.x = v.x * fdf->cam->scale + fdf->cam->offsetx;
	v.y = v.y * fdf->cam->scale + fdf->cam->offsety;
	return (v);
}

void			render(t_fdf *fdf)
{
	t_vector	v;
	int			x;
	int			y;

	clear_image(fdf->img);
	y = -1;
	while (++y < fdf->map->rows)
	{
		x = -1;
		while (++x < fdf->map->cols)
		{
			v = project_vector(get_vector(y, x, fdf), fdf);
			if (x + 1 < fdf->map->cols)
				make_line(fdf, v, \
						project_vector(get_vector(y, x + 1, fdf), fdf));
			if (y + 1 < fdf->map->rows)
				make_line(fdf, v, \
						project_vector(get_vector(y + 1, x, fdf), fdf));
		}
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->image, \
			0, 0);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 10, \
			fdf->base_color0, "FdF");
}
