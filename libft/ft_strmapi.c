/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmpai.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:33:20 by ihuang            #+#    #+#             */
/*   Updated: 2018/10/08 11:56:38 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	ret = NULL;
	i = 0;
	if (s && f)
	{
		if ((ret = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		{
			while (s[i])
			{
				ret[i] = f(i, s[i]);
				i++;
			}
			ret[i] = '\0';
		}
	}
	return (ret);
}
