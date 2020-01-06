/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 11:21:06 by ihuang            #+#    #+#             */
/*   Updated: 2018/12/03 18:09:46 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int	ft_new_line(char **s, char **line, const int fd, int br)
{
	char		*tmp;
	int			len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		tmp = ft_strdup(s[fd] + len + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(s + fd);
	}
	else if (s[fd][len] == '\0' && br < BUFF_SIZE)
	{
		*line = ft_strdup(*(s + fd));
		ft_strdel(s + fd);
	}
	else
		return (gnl(fd, line));
	return (1);
}

int			gnl(const int fd, char **line)
{
	static char	*s[4864];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			br;

	if (fd < 0 || !line || BUFF_SIZE < 1 || fd > 4863)
		return (-1);
	while ((br = read(fd, buf, BUFF_SIZE)) > 0)
	{
		*(buf + br) = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (br < 0)
		return (-1);
	else if (br == 0 && (!s[fd] || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd, br));
}
