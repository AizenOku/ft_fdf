/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 18:19:17 by ihuang            #+#    #+#             */
/*   Updated: 2019/01/07 04:10:15 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ipart returns integer part of double x
*/

int		ipart(double x)
{
	return (floor(x));
}

double	fpart(double x)
{
	return (x - floor(x));
}

/*
** returns 1 - fractional part of number
*/

double	rfpart(double x)
{
	return (1 - fpart(x));
}

double	absolute(double x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	swap(int *i1, int *i2)
{
	int		temp;

	temp = *i1;
	*i1 = *i2;
	*i2 = temp;
}
