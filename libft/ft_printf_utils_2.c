/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:52:12 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/07 02:44:23 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(char c)
{
	return (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+');
}

int	ft_isspec(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' \
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

size_t	ft_off0(long long n)
{
	if (n < 0)
		return (0);
	return (n);
}

int	ft_sign(long long n)
{
	if (n < 0)
		return (-1);
	return (1);
}
