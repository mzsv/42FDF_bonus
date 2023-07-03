/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:46:52 by amenses-          #+#    #+#             */
/*   Updated: 2022/12/04 23:48:30 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_getnull(t_content *a, int *isnull)
{
	char	*s;

	s = ft_substr("(null)", 0, 6);
	*isnull = 1;
	if (a->prc > 6)
		a->prc = 6;
	if (a->prc > -1 && a->prc < 6)
		a->prc = 0;
	return (s);
}
