/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:28:38 by ihuang            #+#    #+#             */
/*   Updated: 2018/12/02 12:21:23 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ret;

	s1_len = s1 ? ft_strlen(s1) : 0;
	s2_len = s2 ? ft_strlen(s2) : 0;
	ret = NULL;
	if ((ret = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
	{
		if (s1)
			ret = ft_strcpy(ret, s1);
		if (s2)
			ret = ft_strcat(ret, (char*)s2);
		*(ret + s1_len + s2_len) = '\0';
	}
	return (ret);
}
