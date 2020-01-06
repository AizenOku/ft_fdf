/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:13:48 by ihuang            #+#    #+#             */
/*   Updated: 2018/10/05 15:16:08 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char		*str2;
	int			n;

	n = ft_strlen(s1);
	if (!(str2 = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (*s1)
		*str2++ = *s1++;
	*str2 = '\0';
	str2 -= n;
	return (str2);
}
