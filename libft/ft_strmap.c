/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:23:35 by ihuang            #+#    #+#             */
/*   Updated: 2018/10/08 11:54:12 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*start;
	char	*ret;

	ret = NULL;
	start = NULL;
	if (s && f)
	{
		if ((ret = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		{
			start = ret;
			while (*s)
			{
				*ret = f((char)*s);
				s++;
				ret++;
			}
			*ret = '\0';
		}
	}
	return (start);
}
