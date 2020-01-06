/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 11:03:21 by ihuang            #+#    #+#             */
/*   Updated: 2018/10/15 19:30:23 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	ret = NULL;
	if ((ret = (t_list*)malloc(sizeof(t_list))))
	{
		if (!content)
		{
			ret->content = NULL;
			ret->content_size = 0;
		}
		else
		{
			if (!(ret->content = malloc(content_size)))
				return (NULL);
			ft_memcpy(ret->content, content, content_size);
			ret->content_size = content_size;
		}
		ret->next = NULL;
	}
	return (ret);
}
