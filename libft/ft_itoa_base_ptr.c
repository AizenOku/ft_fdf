/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <ihuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:55:33 by ihuang            #+#    #+#             */
/*   Updated: 2018/11/19 14:52:21 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_ptr(char **ptr, unsigned long l, int b)
{
	char	*start;
	char	*rep;
	int		i;

	start = *ptr;
	rep = "0123456789abcdef";
	i = 0;
	if (l == 0)
	{
		*ptr = ft_strcpy(*ptr, "0x0");
		return ;
	}
	while (l)
	{
		start[i++] = rep[l % b];
		l /= b;
	}
	start[i++] = 'x';
	start[i++] = '0';
	start[i] = '\0';
	ft_strrev(&start);
}

char			*ft_itoa_base_ptr(unsigned long n, int b)
{
	char			*ptr;
	size_t			digits;

	ptr = NULL;
	digits = ft_digits_base(n, b);
	if ((ptr = ft_strnew(digits + 3)))
		fill_ptr(&ptr, n, b);
	return (ptr);
}
