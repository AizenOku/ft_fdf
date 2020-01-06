/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <ihuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:41:59 by ihuang            #+#    #+#             */
/*   Updated: 2019/01/07 03:48:12 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void	set_cam_and_colors(t_fdf **fdf)
{
	(*fdf)->cam->x = 0.5;
	(*fdf)->cam->y = 0.5;
	(*fdf)->cam->scale = 32;
	(*fdf)->cam->offsetx = WIN_WIDTH / 2;
	(*fdf)->cam->offsety = WIN_HEIGHT / 2;
	(*fdf)->color0 = COLOR0;
	(*fdf)->color1 = COLOR1;
	(*fdf)->base_color0 = (*fdf)->color0;
	(*fdf)->curr_color = 0;
	(*fdf)->end = 0;
}

void				initialize_fdf(t_fdf **fdf)
{
	if (!(*fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		die("malloc failed");
	(*fdf)->mlx_ptr = mlx_init();
	(*fdf)->win_ptr = mlx_new_window((*fdf)->mlx_ptr, WIN_WIDTH, \
			WIN_HEIGHT, "My Window");
	(*fdf)->img = make_new_img(*fdf);
	(*fdf)->map = (t_map *)malloc(sizeof(t_map));
	(*fdf)->cam = (t_cam *)malloc(sizeof(t_cam));
	set_cam_and_colors(fdf);
}

static inline void	hookers(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, 2, 0, &key_press, fdf);
	mlx_hook(fdf->win_ptr, 4, 0, &mouse_press, fdf);
	mlx_hook(fdf->win_ptr, 17, (1L << 17), &close_program, fdf);
	mlx_loop(fdf->mlx_ptr);
}

int					main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		die("Usage: ./fdf [file]");
	initialize_fdf(&fdf);
	make_map_and_vectors(fdf, av[1]);
	render(fdf);
	hookers(fdf);
	free_all(&fdf);
	return (0);
}
