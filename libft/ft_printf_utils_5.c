/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:52:32 by amenses-          #+#    #+#             */
/*   Updated: 2022/12/05 22:18:26 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pkick(t_content *a, unsigned long long p)
{
	a->len = 0;
	if (a->space && p)
	{
		ft_putchar_fd(' ', 1);
		a->len++;
	}
	if (p == 0)
	{
		a->len += 5;
		a->prc = 0;
		a->zero = 0;
	}
	else
		a->len += 2 + ft_nbrlen_base(p, 1, 16);
	a->hashtag = 1;
}

void	ft_putp(t_content *a, unsigned long long p)
{
	size_t	i;

	ft_pkick(a, p);
	if (!(a->prc == -1 && a->zero))
		ft_padding(a);
	if (a->plus && p)
		ft_putchar_fd('+', 1);
	if (p == 0)
		ft_putstr_fd("(nil)", 1);
	else
		ft_putstr_fd("0x", 1);
	i = 0;
	while (p && (ft_off0(a->prc) > ft_nbrlen_base(p, 1, 16)) \
			&& i < ft_off0(a->prc) - ft_nbrlen_base(p, 1, 16))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	if (a->prc == -1)
		ft_padding(a);
	a->len += i + a->plus;
	ft_printnbr(a, p, "0123456789abcdef");
}

void	ft_signedkick(t_content *a, long long n)
{
	if (n < 0)
	{
		a->space = 0;
		a->plus = 0;
		if (a->prc > -1)
			a->prc += 1;
	}
	if (a->space)
	{
		ft_putchar_fd(' ', 1);
		a->len++;
	}
	if (!(a->prc == 0 && n == 0))
		a->len += ft_nbrlen_base(ft_sign(n) * n, ft_sign(n), 10);
}

void	ft_putd(t_content *a, int nbr)
{
	size_t		i;
	long long	n;

	n = nbr;
	ft_signedkick(a, n);
	if (!(a->prc == -1 && a->zero))
		ft_padding(a);
	if (a->plus)
		ft_putchar_fd('+', 1);
	if (n < 0)
		ft_putchar_fd('-', 1);
	if (a->prc == -1)
		ft_padding(a);
	i = 0;
	while ((ft_off0(a->prc) > \
			ft_nbrlen_base(ft_sign(n) * n, ft_sign(n), 10)) \
			&& i < ft_off0(a->prc) - ft_nbrlen_base(ft_sign(n) * n, \
			ft_sign(n), 10))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	a->len += i + a->plus;
	ft_printnbr(a, ft_sign(n) * n, "0123456789");
}

void	ft_putu(t_content *a, unsigned int n)
{
	size_t	i;

	a->len = 0;
	a->space = 0;
	a->plus = 0;
	if (!(a->prc == 0 && n == 0))
		a->len += ft_nbrlen_base(n, 1, 10);
	ft_padding(a);
	i = 0;
	while ((ft_off0(a->prc) > ft_nbrlen_base(n, 1, 10)) \
			&& i < ft_off0(a->prc) - ft_nbrlen_base(n, 1, 10))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	a->len += i;
	ft_printnbr(a, n, "0123456789");
}
