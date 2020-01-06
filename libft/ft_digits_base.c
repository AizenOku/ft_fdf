/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <ihuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:52:23 by ihuang            #+#    #+#             */
/*   Updated: 2018/11/19 10:41:59 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_digits_base(long long int nbr, int base)
{
	unsigned int	isneg;
	size_t			digits;

	isneg = 0;
	digits = 1;
	if (nbr == -2147483648)
		return (11);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		isneg = 1;
		nbr = -nbr;
	}
	while (nbr / base)
	{
		digits++;
		nbr /= base;
	}
	return (isneg + digits);
}
