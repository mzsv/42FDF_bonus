/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:01:46 by amenses-          #+#    #+#             */
/*   Updated: 2022/12/05 21:39:38 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putx(t_content *a, unsigned int n)
{
	size_t	i;

	a->len = 0;
	a->space = 0;
	a->plus = 0;
	if (!(a->prc == 0 && n == 0))
		a->len += ft_nbrlen_base(n, 1, 16);
	if (a->hashtag && a->zero && n > 0)
		ft_putstr_fd("0x", 1);
	if (n == 0)
		a->hashtag = 0;
	if (a->hashtag)
		a->len += 2;
	ft_padding(a);
	if (a->hashtag && !a->zero && n > 0)
		ft_putstr_fd("0x", 1);
	i = 0;
	while ((ft_off0(a->prc) > ft_nbrlen_base(n, 1, 16)) \
			&& i < ft_off0(a->prc) - ft_nbrlen_base(n, 1, 16))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	a->len += i;
	ft_printnbr(a, n, "0123456789abcdef");
}

void	ft_putx_upper(t_content *a, unsigned int n)
{
	size_t	i;

	a->len = 0;
	a->space = 0;
	a->plus = 0;
	if (!(a->prc == 0 && n == 0))
		a->len += ft_nbrlen_base(n, 1, 16);
	if (a->hashtag && a->zero && n > 0)
		ft_putstr_fd("0X", 1);
	if (n == 0)
		a->hashtag = 0;
	if (a->hashtag)
		a->len += 2;
	ft_padding(a);
	if (a->hashtag && !a->zero && n > 0)
		ft_putstr_fd("0X", 1);
	i = 0;
	while ((ft_off0(a->prc) > ft_nbrlen_base(n, 1, 16)) \
			&& i < ft_off0(a->prc) - ft_nbrlen_base(n, 1, 16))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	a->len += i;
	ft_printnbr(a, n, "0123456789ABCDEF");
}

void	ft_printcontent(t_content *a, va_list arg)
{
	if (a->spec == 'c')
		ft_putc(a, va_arg(arg, int));
	else if (a->spec == 's')
		ft_puts(a, va_arg(arg, char *));
	else if (a->spec == 'p')
		ft_putp(a, va_arg(arg, unsigned long long));
	else if (a->spec == 'd' || a->spec == 'i')
		ft_putd(a, va_arg(arg, int));
	else if (a->spec == 'u')
		ft_putu(a, va_arg(arg, unsigned int));
	else if (a->spec == 'x')
		ft_putx(a, va_arg(arg, unsigned int));
	else if (a->spec == 'X')
		ft_putx_upper(a, va_arg(arg, unsigned int));
	else if (a->spec == '%')
	{
		ft_putchar_fd('%', 1);
		a->len = 1;
	}
}

char	*ft_readflags(t_content *a, const char *fmt)
{
	char	*f;
	size_t	i;

	i = 0;
	while (ft_isflag(fmt[i]))
		i++;
	f = ft_substr(fmt, 0, i);
	a->offset = i;
	return (f);
}

int	ft_isnumspec(char spec)
{
	return (spec == 'd' || spec == 'i' || spec == 'u' \
			|| spec == 'x' || spec == 'X' || spec == 'p');
}
