/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:56:52 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/13 23:32:00 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;
	t_list	*tmp;

	if (!del || !lst)
		return ;
	t = *lst;
	while (t)
	{
		tmp = t->next;
		ft_lstdelone(t, (del));
		t = tmp;
	}
	*lst = NULL;
}
