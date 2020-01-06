/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:28:44 by ihuang            #+#    #+#             */
/*   Updated: 2018/09/20 14:36:07 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	ft_strlen(const char *s)
{
	char	*p;

	p = (char*)s;
	while (*p)
		p++;
	return (p - s);
}

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*p;

	p = s1 + ft_strlen(s1);
	while (*s2 && n-- != 0)
		*p++ = *s2++;
	*p = '\0';
	return (s1);
}
