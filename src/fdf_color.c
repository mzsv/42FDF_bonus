/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:11:30 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:18:59 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_inter_color(int color_0, int color_1, double f)
{
	int		r[3];
	int		g[3];
	int		b[3];

	if (color_0 == color_1)
		return (color_0);
	r[0] = color_0 >> 16;
	r[1] = color_1 >> 16;
	g[0] = (color_0 >> 8) & 0xFF;
	g[1] = (color_1 >> 8) & 0xFF;
	b[0] = color_0 & 0xFF;
	b[1] = color_1 & 0xFF;
	r[2] = f * r[1] + (1 - f) * r[0];
	g[2] = f * g[1] + (1 - f) * g[0];
	b[2] = f * b[1] + (1 - f) * b[0];
	return (r[2] << 16 | g[2] << 8 | b[2]);
}

int	ft_color_gradient(t_point p0, t_point p1, t_lpvar v, t_image img)
{
	double	l;
	double	dl;
	double	f;

	l = sqrt(pow(v.dx, 2) + pow(v.dy, 2));
	dl = sqrt(pow(v.x0 - img.center[0] - p0.x, 2) + \
		pow(v.y0 - img.center[1] - p0.y, 2));
	f = dl / l;
	if (img.color_mode == 2)
		return (ft_inter_color(p0.color[0], p1.color[0], f));
	return (ft_inter_color(p0.color[1], p1.color[1], f));
}

int	ft_pxl_color(t_point p0, t_point p1, t_lpvar v, t_image img)
{
	int	color;

	color = DCOLOR;
	if (img.color_mode)
		color = ft_color_gradient(p0, p1, v, img);
	return (color);
}
