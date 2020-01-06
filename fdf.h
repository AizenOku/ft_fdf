/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <ihuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:10:04 by ihuang            #+#    #+#             */
/*   Updated: 2019/01/07 04:15:16 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** include for open, read, write, close
*/
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/*
** include for malloc, free, exit
*/
# include <stdlib.h>

/*
** include for perror, strerror
*/
# include <stdio.h>

/*
** math library
*/
# include <math.h>

/*
** miniLibx library
*/
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

# define MAX(a, b) ((a > b) ? a : b)
# define MIN(a, b) ((a < b) ? a : b)

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define IMG_WIDTH 1280
# define IMG_HEIGHT 720
# define COLOR0 0x00FF00
# define COLOR1 0xFFFFFF

typedef struct	s_cam
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	int			scale;
}				t_cam;

typedef struct	s_img
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_vector;

typedef struct	s_map
{
	int			rows;
	int			cols;
	int			min_height;
	int			max_height;
	int			**xy_map;
	t_vector	**vector;
}				t_map;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_map		*map;
	t_cam		*cam;
	int			base_color0;
	int			color0;
	int			color1;
	int			curr_color;
	int			x0;
	int			y0;
	int			z0;
	int			x1;
	int			y1;
	int			z1;
	int			end;
}				t_fdf;

/*
** math_helpers.c
*/
int				ipart(double x);
double			fpart(double x);
double			rfpart(double x);
double			absolute(double x);
void			swap(int *a, int *b);

/*
** get_color.c
*/
int				get_color(t_fdf *fdf, int x, int time);

/*
** draw_line.c
*/
void			make_line(t_fdf *fdf, t_vector v1, t_vector v2);

/*
** image.c
*/
void			clear_image(t_img *img);
void			image_set_pixel(t_img *img, int x, int y, int color);
t_img			*free_image(t_fdf *fdf, t_img *img);
t_img			*make_new_img(t_fdf *fdf);

/*
** make_map.c
*/
int				make_map_and_vectors(t_fdf *fdf, char *file_name);

/*
** update_vector_colors.c
*/
void			update_vector_colors(t_fdf *fdf);

/*
** render.c
*/
void			render(t_fdf *fdf);

/*
** key_press and mouse_press
*/
int				key_press(int key, t_fdf *fdf);
int				mouse_press(int button, int x, int y, t_fdf *fdf);

/*
** free_all.c
*/
int				close_program(t_fdf *fdf);
void			free_all(t_fdf **fdf);
void			die(char *message);
void			free_all_and_die(t_fdf **fdf, char *message);

#endif
