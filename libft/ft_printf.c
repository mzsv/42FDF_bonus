/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:58:27 by amenses-          #+#    #+#             */
/*   Updated: 2022/12/05 22:26:52 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	t_content	*a;
	va_list		arg;
	int			r;

	va_start(arg, fmt);
	r = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			a = ft_getflags(fmt + 1);
			fmt += a->offset;
			ft_printcontent(a, arg);
			r += a->len;
			free(a);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			r++;
		}
		fmt++;
	}
	va_end(arg);
	return (r);
}
