/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:35:08 by ihuang            #+#    #+#             */
/*   Updated: 2018/10/15 21:46:12 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*strdupc(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = 0;
	i = 0;
	ret = NULL;
	while (*(s + len) && *(s + len) != c)
		len++;
	if ((ret = (char*)malloc(sizeof(char) * (len + 1))))
	{
		while (i < len)
		{
			*(ret + i) = *(s + i);
			i++;
		}
		*(ret + len) = '\0';
	}
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	word_count;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	word_count = ft_wordcount(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (word_count + 1))))
		return (NULL);
	while (i < word_count)
	{
		if (!*s)
			break ;
		while (*s && *s == c)
			s++;
		if (!(*(tab + i) = strdupc(s, c)))
			return (NULL);
		while (*s && *s != c)
			s++;
		i++;
	}
	*(tab + word_count) = NULL;
	return (tab);
}
