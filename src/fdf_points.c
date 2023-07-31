/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:57:55 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/31 20:04:57 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_atoi_ptr(char **nptr)
{
	unsigned int	res;
	int				sign;

	sign = 1;
	res = 0;
	while ((**nptr >= 9 && **nptr <= 13) || **nptr == 32)
		(*nptr)++;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			sign = -1;
		(*nptr)++;
	}
	while ((**nptr >= 48 && **nptr <= 57) && **nptr)
	{
		res = res * 10 + **nptr - '0';
		(*nptr)++;
	}
	return (res * sign);
}

static int	ft_x_atoi_ptr(char **x)
{
	int		n;
	int		i;

	n = 0;
	if (!x || !*x || **x != ',')
		return (DMCOLOR);
	*x = ft_strchr(*x, 'x');
	if (*x)
	{
		(*x)++;
		i = 0;
		while (i < 6 && **x && !((**x >= 9 && **x <= 13) || **x == ' '))
		{
			if (**x >= 'A' && **x <= 'Z')
				n |= ft_findchr("0123456789ABCDEF", **x) << (4 * (5 - i));
			else
				n |= ft_findchr("0123456789abcdef", **x) << (4 * (5 - i));
			i++;
			(*x)++;
		}
		n >>= 4 * (6 - i);
		return (n);
	}
	return (DMCOLOR);
}

t_point	*ft_get_points(t_model *m)
{
	t_point	*p;
	int		i;
	double	e[2];
	char	*tmp;

	ft_bzero(e, sizeof(double) * 2);
	e[0] = (double) !(m->ncols % 2) * 0.5;
	e[1] = (double) !(m->nrows % 2) * 0.5;
	p = ft_calloc(m->nelem, sizeof(t_point));
	if (!p)
		return (ft_error("Error: memory allocation failed"), NULL);
	i = -1;
	while (++i < m->nelem)
	{
		p[i].x = ((i % m->ncols) - (m->ncols / 2) + e[0]) * m->scale;
		p[i].y = ((i / m->ncols) - (m->nrows / 2) + e[1]) * m->scale;
		if (i % m->ncols == 0)
			tmp = m->map[i / m->ncols];
		p[i].z = ft_atoi_ptr(&tmp);
		p[i].color[0] = ft_x_atoi_ptr(&tmp);
	}
	p = ft_adjust_z(p, *m);
	return (p);
}

void	ft_points_color(t_point *p, t_model m, t_image *img)
{
	int		i;
	double	f;

	ft_findrange_z(p, img, m.nelem);
	f = 0;
	i = 0;
	while (i < m.nelem)
	{
		if (p[i].z < 0)
		{
			f = p[i].z / img->range_z[0];
			p[i].color[1] = ft_inter_color(NCOLOR, LCOLOR, f);
		}
		else
		{
			if (img->range_z[1] == 0)
				p[i].color[1] = NCOLOR;
			else
			{
				f = p[i].z / img->range_z[1];
				p[i].color[1] = ft_inter_color(NCOLOR, HCOLOR, f);
			}
		}
		i++;
	}
}
