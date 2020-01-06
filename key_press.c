/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:24:13 by ihuang            #+#    #+#             */
/*   Updated: 2019/01/07 03:27:43 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	believe_by_cher(t_fdf *fdf)
{
	static int		i = 0;
	static int		direction = 1;

	clear_image(fdf->img);
	fdf->cam->x += 0.1;
	fdf->cam->y += 0.1;
	if (i++ % 7 == 0)
	{
		direction *= -1;
		fdf->base_color0 += 0xF;
		fdf->base_color0 == 0x0 ? fdf->base_color0 = 0xFF0000 : 0;
		update_vector_colors(fdf);
	}
	fdf->cam->scale += 2 * direction;
	render(fdf);
}

static inline void	change_base_color(t_fdf *fdf, int key)
{
	clear_image(fdf->img);
	if (key == 18)
		fdf->base_color0 = 0xFF0E0E;
	else if (key == 19)
		fdf->base_color0 = 0xFF710E;
	else if (key == 20)
		fdf->base_color0 = 0xDEFF0E;
	else if (key == 21)
		fdf->base_color0 = 0x0EFFC8;
	else
		fdf->base_color0 = 0xFF7CDF;
	update_vector_colors(fdf);
	render(fdf);
}

static inline void	rotate(t_fdf *fdf, int key)
{
	clear_image(fdf->img);
	if (key == 123)
		fdf->cam->y -= 0.1;
	else if (key == 124)
		fdf->cam->y += 0.1;
	else if (key == 125)
		fdf->cam->x -= 0.1;
	else
		fdf->cam->x += 0.1;
	render(fdf);
}

int					key_press(int key, t_fdf *fdf)
{
	if (key == 16)
		believe_by_cher(fdf);
	else if (key >= 18 && key <= 23)
		change_base_color(fdf, key);
	else if (key >= 123 && key <= 126)
		rotate(fdf, key);
	else if (key == 53)
		free_all_and_die(&fdf, "Bye, see ya next time!");
	return (0);
}
