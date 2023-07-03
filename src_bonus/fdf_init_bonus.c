/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:55:26 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:19:13 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

t_model	ft_init_model(void)
{
	t_model	m;

	m.map = NULL;
	m.ncols = 0;
	m.nelem = 0;
	m.nrows = 0;
	m.scale = 1;
	return (m);
}

t_image	ft_init_image(void)
{
	t_image	img;

	img.mlx_ptr = mlx_init();
	if (!img.mlx_ptr)
		ft_error("Error: connection with X-server failed");
	img.ptr = mlx_new_image(img.mlx_ptr, WINW, WINH);
	if (!img.ptr)
		if (ft_free_mlx(img.mlx_ptr, img.ptr, NULL))
			ft_error("Error: failed to initialize image");
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.line, &img.endian);
	img.win_ptr = mlx_new_window(img.mlx_ptr, WINW, WINH, TITLE);
	if (!img.win_ptr)
		if (ft_free_mlx(img.mlx_ptr, img.ptr, img.win_ptr))
			ft_error("Error: failed to initialize window");
	ft_bzero(img.range_z, sizeof(double) * 2);
	img.translate = 0;
	img.rotate = 0;
	img.perspective_mode = 0;
	ft_bzero(img.cursor, sizeof(int) * 2);
	img.center[0] = WINW / 2;
	img.center[1] = WINH / 2;
	img.zoom = 1;
	img.depth_mode = 0;
	img.color_mode = 0;
	return (img);
}

t_matrix	ft_init_mat(void)
{
	t_matrix	mat;

	ft_bzero(mat.rot_x, sizeof(double) * 9);
	ft_bzero(mat.rot_y, sizeof(double) * 9);
	ft_bzero(mat.rot_z, sizeof(double) * 9);
	ft_bzero(mat.persp_proj, sizeof(double) * 9);
	return (mat);
}

t_fdf	ft_init_fdf(void)
{
	t_fdf	fdf;

	fdf.m = ft_init_model();
	fdf.p = NULL;
	fdf.t = NULL;
	fdf.iso = NULL;
	fdf.img = ft_init_image();
	fdf.mat = ft_init_mat();
	return (fdf);
}
