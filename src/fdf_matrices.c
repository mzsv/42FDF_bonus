/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:43:43 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:18:59 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix	ft_rotation(t_matrix mat, double alpha, double beta, double gamma)
{
	mat.rot_x[0][0] = 1;
	mat.rot_x[1][1] = cos(alpha);
	mat.rot_x[1][2] = -sin(alpha);
	mat.rot_x[2][1] = sin(alpha);
	mat.rot_x[2][2] = cos(alpha);
	mat.rot_y[0][0] = cos(beta);
	mat.rot_y[0][2] = sin(beta);
	mat.rot_y[1][1] = 1;
	mat.rot_y[2][0] = -sin(beta);
	mat.rot_y[2][2] = cos(beta);
	mat.rot_z[0][0] = cos(gamma);
	mat.rot_z[0][1] = -sin(gamma);
	mat.rot_z[1][0] = sin(gamma);
	mat.rot_z[1][1] = cos(gamma);
	mat.rot_z[2][2] = 1;
	return (mat);
}

t_point	ft_matmul(double m[3][3], t_point p)
{
	t_point	r;

	r.x = p.x * m[0][0] + p.y * m[0][1] + p.z * m[0][2];
	r.y = p.x * m[1][0] + p.y * m[1][1] + p.z * m[1][2];
	r.z = p.x * m[2][0] + p.y * m[2][1] + p.z * m[2][2];
	r.color[0] = p.color[0];
	r.color[1] = p.color[1];
	return (r);
}
