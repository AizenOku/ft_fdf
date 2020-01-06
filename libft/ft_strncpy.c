/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:06:54 by ihuang            #+#    #+#             */
/*   Updated: 2018/10/08 17:39:51 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = (int)len;
	while (src[i] && j < n)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	while (j < n)
		dst[j++] = '\0';
	return (dst);
}
