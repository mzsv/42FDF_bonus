/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:52:03 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 16:17:10 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_atoi_ll(const char *nptr)
{
	unsigned long long	res;
	int					sign;

	sign = 1;
	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while ((*nptr >= 48 && *nptr <= 57) && *nptr)
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * sign);
}

size_t	ft_nbrlen_base(unsigned long long nbr, int sign, int base_len)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base_len;
		len++;
	}
	if (sign == 1)
		return (len);
	else
		return (len + 1);
}

void	ft_putnbr_base(unsigned long long n, char *base)
{
	size_t				base_len;

	base_len = ft_strlen(base);
	if (n < base_len)
		ft_putchar_fd(base[n], 1);
	else
	{
		ft_putnbr_base(n / base_len, base);
		ft_putnbr_base(n % base_len, base);
	}
}

size_t	ft_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	else
		return (a);
}
