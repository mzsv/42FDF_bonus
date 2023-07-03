/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:20:15 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/13 21:42:32 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	t = *lst;
	while (t->next)
	{
		t = t->next;
	}
	t->next = new;
}
