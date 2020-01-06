/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <ihuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:56:56 by ihuang            #+#    #+#             */
/*   Updated: 2018/12/03 11:07:24 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_ptr(char **ptr, unsigned long long l, long long int n)
{
	char	*start;
	int		i;

	start = *ptr;
	i = 0;
	if (n == 0)
	{
		free(*ptr);
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

char			*ft_llitoa(long long int n)
{
	unsigned long long	l;
	char				*ptr;
	size_t				digits;

	ptr = NULL;
	l = n;
	if (n < 0)
		l = -l;
	digits = ft_digits_base(n, 10);
	if ((ptr = ft_strnew(digits + 1)))
		fill_ptr(&ptr, l, n);
	return (ptr);
}
