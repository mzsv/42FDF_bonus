/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:31:35 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:19:13 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double	ft_dmax(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	ft_dmin(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

void	ft_swap(double a, double b)
{
	double	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

int	ft_round(double n)
{
	int	r;

	r = (int)n;
	if (n - (double)r >= 0.5)
		r++;
	return (r);
}
