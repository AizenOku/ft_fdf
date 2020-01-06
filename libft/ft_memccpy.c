/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 22:12:51 by ihuang            #+#    #+#             */
/*   Updated: 2018/09/24 18:30:19 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char*)dst;
	while (n-- > 0)
	{
		*p = *(unsigned char*)src;
		if (*p == (unsigned char)c)
			return (p + 1);
		p++;
		src++;
	}
	return (NULL);
}
