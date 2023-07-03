/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:52:18 by amenses-          #+#    #+#             */
/*   Updated: 2023/02/07 02:44:45 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_setflags(t_content *a, const char *fmt)
{
	char		*f;

	f = ft_readflags(a, fmt);
	if (ft_strchr(f, '-'))
		a->minus = 1;
	if (ft_strchr(f, '0') && a->minus == 0)
		a->zero = 1;
	if (ft_strchr(f, '#') && a->spec != 'd' \
			&& a->spec != 'i' && a->spec != 'u')
		a->hashtag = 1;
	if (ft_strchr(f, '+') && a->spec != 'u' \
			&& a->spec != 'x' && a->spec != 'X')
		a->plus = 1;
	if (ft_strchr(f, ' ') && a->plus == 0 \
			&& a->spec != 'u' && a->spec != 'x' && a->spec != 'X')
		a->space = 1;
	free(f);
}

void	ft_setfw(t_content *a, const char *fmt)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = a->offset;
	j = 0;
	while (ft_isdigit(fmt[i]))
	{
		i++;
		j++;
	}
	tmp = ft_substr(fmt, i - j, j);
	a->fw = ft_atoi_ll(tmp);
	a->offset = i;
	free(tmp);
}

void	ft_setprc(t_content *a, const char *fmt)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = a->offset;
	if (fmt[i] == '.')
	{
		i++;
		j = 0;
		while (ft_isdigit(fmt[i]))
		{
			i++;
			j++;
		}
		tmp = ft_substr(fmt, i - j, j);
		a->prc = ft_atoi_ll(tmp);
		free(tmp);
	}
	else
		a->prc = -1;
	if (a->prc > -1)
		a->zero = 0;
	a->offset = i;
}

void	ft_setspec(t_content *a, const char *fmt)
{
	size_t	i;

	i = a->offset;
	if (ft_isspec(fmt[i]))
		a->spec = fmt[i];
	else
		a->spec = 0;
	a->offset = i + 1;
}
