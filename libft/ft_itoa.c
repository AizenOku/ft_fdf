/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:56:56 by ihuang            #+#    #+#             */
/*   Updated: 2018/11/14 08:45:36 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_ptr(char **ptr, long l, int n)
{
	char	*start;
	int		i;

	start = *ptr;
	i = 0;
	if (n == 0)
	{
		*ptr = ft_strdup("0");
		return ;
	}
	while (l)
	{
		start[i++] = l % 10 + '0';
		l /= 10;
	}
	if (n < 0)
		start[i++] = '-';
	start[i] = '\0';
	ft_strrev(&start);
}

char			*ft_itoa(int n)
{
	long			l;
	char			*ptr;
	size_t			digits;

	ptr = NULL;
	l = n;
	if (l < 0)
		l = -l;
	if (n == -2147483648)
		return ((ptr = ft_strdup("-2147483648")));
	digits = ft_digits_base(n, 10);
	if ((ptr = ft_strnew(digits + 1)))
		fill_ptr(&ptr, l, n);
	return (ptr);
}
