/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 22:17:46 by ihuang            #+#    #+#             */
/*   Updated: 2018/10/06 16:33:53 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstp;
	char	*srcp;

	dstp = (char*)dst;
	srcp = (char*)src;
	if (srcp < dstp)
		while (len--)
			*(dstp + len) = *(srcp + len);
	else
		while (len--)
			*dstp++ = *srcp++;
	return (dst);
}
