/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_vector_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 03:22:04 by ihuang            #+#    #+#             */
/*   Updated: 2019/01/07 03:23:57 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		update_vector_colors(t_fdf *fdf)
{
	int		i;
	int		j;
	int		num;

	i = -1;
	while (++i < fdf->map->rows)
	{
		j = -1;
		while (++j < fdf->map->cols)
		{
			num = fdf->map->xy_map[i][j];
			fdf->map->vector[i][j].color = get_color(fdf, num, 1);
		}
	}
}
