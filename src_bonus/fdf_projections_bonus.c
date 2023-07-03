/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:53:31 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:19:13 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	ft_isometric_proj(t_fdf *fdf)
{
	int	i;

	fdf->mat = ft_rotation(fdf->mat, atan(1 / sqrt(2)), 0, PI / 4);
	i = 0;
	while (i < fdf->m.nelem)
	{
		fdf->p[i] = ft_matmul(fdf->mat.rot_z, fdf->p[i]);
		fdf->p[i] = ft_matmul(fdf->mat.rot_x, fdf->p[i]);
		i++;
	}
}

void	ft_rotated_proj(t_fdf *fdf, int x, int y)
{
	int	i;

	fdf->mat = ft_rotation(fdf->mat, \
			-(y - fdf->img.cursor[1]) * PI / ROTF, \
			-(x - fdf->img.cursor[0]) * PI / ROTF, \
			0.5 * ((y - fdf->img.cursor[1]) + \
			(x - fdf->img.cursor[0])) * PI / ROTF);
	i = 0;
	while (i < fdf->m.nelem)
	{
		fdf->p[i] = ft_matmul(fdf->mat.rot_x, fdf->p[i]);
		fdf->p[i] = ft_matmul(fdf->mat.rot_y, fdf->p[i]);
		fdf->p[i] = ft_matmul(fdf->mat.rot_z, fdf->p[i]);
		fdf->t[i] = fdf->p[i];
		i++;
	}
}

double	ft_dist(t_fdf *fdf)
{
	double	w2;
	double	h2;

	w2 = pow(fdf->m.ncols * fdf->m.scale, 2);
	h2 = pow(fdf->m.nrows * fdf->m.scale, 2);
	return (0.5 * sqrt(w2 + h2) * (1 + PERSF));
}

void	ft_weak_perspective(t_fdf *fdf)
{
	double	proj[3][3];
	double	f;
	double	dist;
	int		i;

	ft_bzero(proj, sizeof(double) * 9);
	dist = ft_dist(fdf);
	i = 0;
	while (i < fdf->m.nelem)
	{
		f = dist / (dist - fdf->p[i].z);
		proj[0][0] = f;
		proj[1][1] = f;
		proj[2][2] = 1;
		fdf->t[i] = ft_matmul(proj, fdf->t[i]);
		i++;
	}
}
