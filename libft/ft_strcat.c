/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:36:26 by ihuang            #+#    #+#             */
/*   Updated: 2018/10/08 12:32:24 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strlen(const char *s)
{
	char	*p;

	p = (char*)s;
	while (*p)
		p++;
	return (p - s);
}

char		*ft_strcat(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*p;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = s1 + s1_len;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (s1);
}
