/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:03:42 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:18:59 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_pixel_put(t_image *img, int x, int y, int color)
{
	char	*pxl;

	pxl = img->addr + (y * img->line + x * (img->bpp / 8));
	*(unsigned int *)pxl = ft_dmax(*(unsigned int *)pxl, color);
}

t_lpvar	ft_lp_initvar(t_image img, t_point p0, t_point p1)
{
	t_lpvar	v;

	v.x0 = ft_round(p0.x) + img.center[0];
	v.x1 = ft_round(p1.x) + img.center[0];
	v.y0 = ft_round(p0.y) + img.center[1];
	v.y1 = ft_round(p1.y) + img.center[1];
	v.dx = ft_abs(v.x1 - v.x0);
	v.dy = -ft_abs(v.y1 - v.y0);
	v.sx = -1;
	if (v.x0 <= v.x1)
		v.sx = 1;
	v.sy = -1;
	if (v.y0 <= v.y1)
		v.sy = 1;
	v.e = v.dx + v.dy;
	return (v);
}

void	ft_line_put(t_image img, t_point p0, t_point p1)
{
	t_lpvar	v;

	v = ft_lp_initvar(img, p0, p1);
	while (1)
	{
		if (v.x0 < WINW && v.x0 > 0 && v.y0 < WINH && v.y0 > 0)
			ft_pixel_put(&img, v.x0, v.y0, ft_pxl_color(p0, p1, v, img));
		if (v.x0 == v.x1 && v.y0 == v.y1)
			break ;
		if (2 * v.e >= v.dy && v.x0 != v.x1)
		{
			v.x0 += v.sx;
			v.e += v.dy;
		}
		if (2 * v.e <= v.dx && v.y0 != v.y1)
		{
			v.y0 += v.sy;
			v.e += v.dx;
		}
	}
}

void	ft_render_fdf(t_point *p, t_model m, t_image *img)
{
	int	i;

	ft_findrange_z(p, img, m.nelem);
	i = 0;
	while (i < m.nelem)
	{
		if ((i + 1) % m.ncols > 0)
			ft_line_put(*img, p[i], p[i + 1]);
		if (i + m.ncols < m.nelem)
			ft_line_put(*img, p[i], p[i + m.ncols]);
		i++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->ptr, 0, 0);
}
