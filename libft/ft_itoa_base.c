/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <ihuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 22:19:10 by ihuang            #+#    #+#             */
/*   Updated: 2018/11/17 10:41:49 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_ptr(char **ptr, long l, int n, int b)
{
	char	*start;
	char	*rep;
	int		i;

	start = *ptr;
	rep = "0123456789abcdef";
	i = 0;
	if (n == 0)
	{
		*ptr = ft_strdup("0");
		return ;
	}
	while (l)
	{
		start[i++] = rep[l % b];
		l /= b;
	}
	if (n < 0 && b == 10)
		start[i++] = '-';
	start[i] = '\0';
	ft_strrev(&start);
}

char			*ft_itoa_base(int n, int b)
{
	long	l;
	char	*ptr;
	size_t	digits;

	ptr = NULL;
	l = n;
	if (n < 0)
		l = -l;
	if (n == -2147483648 && b == 10)
		return ((ptr = ft_strdup("-2147483648")));
	digits = ft_digits_base(n, b);
	if ((ptr = ft_strnew(digits + 1)))
		fill_ptr(&ptr, l, n, b);
	return (ptr);
}
