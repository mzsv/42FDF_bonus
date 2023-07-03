/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:53:31 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:18:59 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
