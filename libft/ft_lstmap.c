/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:37:50 by ihuang            #+#    #+#             */
/*   Updated: 2018/10/15 19:31:51 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*new;

	start = NULL;
	new = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		new = f(lst);
		ft_lstadd(&start, new);
		lst = lst->next;
	}
	ft_lstrev(&start);
	return (start);
}
