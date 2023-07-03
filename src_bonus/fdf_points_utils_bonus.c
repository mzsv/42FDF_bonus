/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_points_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:50:54 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:19:13 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

t_point	*ft_pointsdup(t_point *p, t_model m)
{
	t_point	*dup;
	int		i;

	if (!p)
		return (NULL);
	dup = malloc(sizeof(t_point) * m.nelem);
	if (!dup)
		return (ft_error("Error: memory allocation failed"), NULL);
	i = 0;
	while (i < m.nelem)
	{
		dup[i].x = p[i].x;
		dup[i].y = p[i].y;
		dup[i].z = p[i].z;
		dup[i].color[0] = p[i].color[0];
		dup[i].color[1] = p[i].color[1];
		i++;
	}
	return (dup);
}

void	ft_points_cpy(t_point *dst, t_point *src, t_model m)
{
	int	i;

	i = 0;
	while (i < m.nelem)
	{
		dst[i] = src[i];
		i++;
	}
}

t_point	*ft_adjust_z(t_point *p, t_model m)
{
	int		i;
	double	new_scale;

	new_scale = 0;
	i = 0;
	if (Z_SCALE)
	{
		while (i < m.nelem)
		{
			p[i].z *= Z_SCALE;
			i++;
		}
	}
	else
	{
		new_scale = ft_z_scale(p, m.nelem, ft_dmax(m.ncols, m.nrows), m.scale);
		while (i < m.nelem)
		{
			p[i].z *= new_scale;
			i++;
		}
	}
	return (p);
}

double	ft_z_scale(t_point *p, int nelem, int len, double map_scale)
{
	int		i;
	int		range[2];
	double	scale;

	i = 0;
	ft_bzero(range, sizeof(int) * 2);
	scale = 0;
	while (i < nelem)
	{
		if (p[i].z > range[1])
			range[1] = p[i].z;
		if (p[i].z < range[0])
			range[0] = p[i].z;
		i++;
	}
	if (range[1] - range[0])
		scale = (0.1 * len * map_scale) / (range[1] - range[0]);
	if (scale < 1)
		return (1);
	return (scale);
}

void	ft_findrange_z(t_point *p, t_image *img, int nelem)
{
	int		i;
	double	min;
	double	max;

	i = 0;
	min = 0;
	max = 0;
	while (i < nelem)
	{
		if (max < p[i].z)
			max = p[i].z;
		if (min > p[i].z)
			min = p[i].z;
		i++;
	}
	img->range_z[0] = min;
	img->range_z[1] = max;
}
