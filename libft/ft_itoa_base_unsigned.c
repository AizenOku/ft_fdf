/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <ihuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 22:19:10 by ihuang            #+#    #+#             */
/*   Updated: 2018/12/01 14:41:43 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_digits_unsigned(unsigned long long int nbr, int base)
{
	int		digits;

	digits = 1;
	if (nbr == 0)
		return (digits);
	while (nbr / (unsigned int)base)
	{
		digits++;
		nbr /= base;
	}
	return (digits);
}

static void		fill_ptr(char **ptr, unsigned long long int n, int b)
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
	while (n)
	{
		start[i++] = rep[n % b];
		n /= b;
	}
	start[i] = '\0';
	ft_strrev(&start);
}

char			*ft_itoa_base_unsigned(unsigned long long int nbr, int base)
{
	char	*ptr;
	size_t	digits;

	ptr = NULL;
	digits = ft_digits_unsigned(nbr, base);
	if ((ptr = ft_strnew(digits + 1)))
		fill_ptr(&ptr, nbr, base);
	return (ptr);
}
