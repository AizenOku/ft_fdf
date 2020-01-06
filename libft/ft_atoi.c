/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 18:15:47 by ihuang            #+#    #+#             */
/*   Updated: 2018/10/15 15:52:05 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\f' || c == '\r' \
			|| c == '\v' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int					isneg;
	unsigned long long	value;

	isneg = 1;
	value = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			isneg = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		value = value * 10 + *str - '0';
		if (value >= 9223372036854775807)
		{
			if (isneg == -1)
				return (0);
			return (-1);
		}
		str++;
	}
	return ((int)isneg * value);
}
