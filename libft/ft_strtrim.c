/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:22:20 by ihuang            #+#    #+#             */
/*   Updated: 2018/10/15 21:56:21 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int	isempty(char const *s)
{
	if (!s)
		return (1);
	while (*s && ft_isspace(*s))
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*ret;
	char	*start;
	char	*end;

	if (!s || isempty(s))
		return (ret = ft_strdup(""));
	start = (char*)s;
	end = (char*)s + ft_strlen(s) - 1;
	while (*start && ft_isspace(*start))
		start++;
	while (*end && ft_isspace(*end))
		end--;
	if (start > end)
		return (NULL);
	if ((ret = ft_strnew(end - start + 1)))
	{
		ret = ft_strncpy(ret, start, end - start + 1);
		*(ret + (end - start + 1)) = '\0';
	}
	return (ret);
}
