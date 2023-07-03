/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:49:35 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/14 00:23:56 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*tmp;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	t = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!t)
			head = tmp;
		if (!tmp)
		{
			ft_lstclear(&head, (del));
			return (NULL);
		}
		ft_lstadd_back(&t, tmp);
		lst = lst->next;
	}
	return (t);
}
