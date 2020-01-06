/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:49:45 by ihuang            #+#    #+#             */
/*   Updated: 2019/01/07 02:12:21 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_set_pixel(t_img *image, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int *)(image->ptr + ((x + y * IMG_WIDTH) * image->bpp)) = color;
}

void	clear_image(t_img *img)
{
	ft_bzero(img->ptr, IMG_WIDTH * IMG_HEIGHT * img->bpp);
}

t_img	*free_image(t_fdf *fdf, t_img *img)
{
	if (img != NULL)
	{
		if (img->image != NULL)
			mlx_destroy_image(fdf->mlx_ptr, img->image);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

t_img	*make_new_img(t_fdf *fdf)
{
	t_img	*img;

	if (!(img = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	if (!(img->image = mlx_new_image(fdf->mlx_ptr, IMG_WIDTH, IMG_HEIGHT)))
		return (NULL);
	img->ptr = mlx_get_data_addr(img->image, &(img->bpp), \
			&(img->size_line), &(img->endian));
	img->bpp /= 8;
	return (img);
}
