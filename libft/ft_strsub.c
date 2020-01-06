/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:13:14 by ihuang            #+#    #+#             */
/*   Updated: 2018/12/03 18:03:51 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	ret = NULL;
	if (!s || !len || !*(s + start))
		return (ret = ft_strdup(""));
	if ((ret = ft_strnew(len)))
	{
		s += start;
		ret = ft_strncpy(ret, s, len);
	}
	return (ret);
}
