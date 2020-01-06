/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:14:55 by ihuang            #+#    #+#             */
/*   Updated: 2018/10/15 20:55:28 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_strrev(char **s)
{
	size_t	end;
	size_t	start;
	char	temp;

	end = ft_strlen(*s) - 1;
	start = 0;
	temp = 0;
	while (end > start)
	{
		temp = *(*s + start);
		*(*s + start) = *(*s + end);
		*(*s + end) = temp;
		end--;
		start++;
	}
}
