/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:36:19 by ihuang            #+#    #+#             */
/*   Updated: 2018/09/21 18:49:10 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		flag;

	flag = 0;
	while (*s)
	{
		if (*s == c)
		{
			p = (char*)s;
			flag = 1;
		}
		s++;
	}
	if (*s == c)
		return ((char*)s);
	if (flag)
		return (p);
	else
		return (NULL);
}
