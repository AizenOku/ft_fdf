/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 02:12:37 by ihuang            #+#    #+#             */
/*   Updated: 2019/01/07 02:14:45 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press(int button, int x, int y, t_fdf *fdf)
{
	int		direction;

	fdf->x0 = x;
	fdf->x0 = y;
	if (button == 4 || button == 5)
	{
		clear_image(fdf->img);
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		direction = button == 4 ? -1 : 1;
		fdf->cam->scale += 5 * direction;
		render(fdf);
	}
	return (0);
}
