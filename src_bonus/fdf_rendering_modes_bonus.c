/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering_modes_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:40:05 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:19:13 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	ft_new_image(t_image *img)
{
	mlx_destroy_image(img->mlx_ptr, img->ptr);
	img->ptr = mlx_new_image(img->mlx_ptr, WINW, WINH);
	if (!img->ptr)
		return (0);
	img->addr = mlx_get_data_addr(img->ptr, \
		&img->bpp, &img->line, &img->endian);
	return (1);
}

void	ft_color_mode(t_fdf *fdf)
{
	if (fdf->img.color_mode < 2)
		fdf->img.color_mode++;
	else
		fdf->img.color_mode = 0;
	if (!ft_new_image(&fdf->img))
		ft_terminate(fdf);
	ft_render_fdf(fdf->t, fdf->m, &fdf->img);
	if (fdf->img.color_mode == 2)
		mlx_string_put(fdf->img.mlx_ptr, fdf->img.win_ptr, 10, 20, 0xffff00, \
			"COLOR MODE: MAP COLOR");
	else if (fdf->img.color_mode == 1)
		mlx_string_put(fdf->img.mlx_ptr, fdf->img.win_ptr, 10, 20, 0xffff00, \
			"COLOR MODE: 3-COLOR DEGRADE (DEFAULT)");
	else
		mlx_string_put(fdf->img.mlx_ptr, fdf->img.win_ptr, 10, 20, 0xffff00, \
			"COLOR MODE: MONOCOLOR (DEFAULT)");
}

void	ft_isometric_mode(t_fdf *fdf)
{
	fdf->img.perspective_mode = 0;
	ft_rescale(fdf->iso, fdf->t, fdf);
	if (!ft_new_image(&fdf->img))
		ft_terminate(fdf);
	ft_render_fdf(fdf->t, fdf->m, &fdf->img);
	ft_points_cpy(fdf->p, fdf->iso, fdf->m);
	mlx_string_put(fdf->img.mlx_ptr, fdf->img.win_ptr, 10, 20, 0xffff00, \
		"ISOMETRIC PROJECTION");
}

void	ft_perspective_mode(t_fdf *fdf)
{
	if (!fdf->img.perspective_mode)
	{
		fdf->img.perspective_mode = 1;
		ft_weak_perspective(fdf);
	}
	else
	{
		fdf->img.perspective_mode = 0;
		ft_points_cpy(fdf->t, fdf->p, fdf->m);
		ft_rescale(fdf->p, fdf->t, fdf);
	}
	if (!ft_new_image(&fdf->img))
		ft_terminate(fdf);
	ft_render_fdf(fdf->t, fdf->m, &fdf->img);
	if (fdf->img.perspective_mode)
		mlx_string_put(fdf->img.mlx_ptr, fdf->img.win_ptr, 10, 20, 0xffff00, \
			"PERSPECTIVE PROJECTION MODE: ON");
	else
		mlx_string_put(fdf->img.mlx_ptr, fdf->img.win_ptr, 10, 20, 0xffff00, \
			"PERSPECTIVE PROJECTION MODE: OFF (DEFAULT PARALLEL PROJECTION)");
}

void	ft_depth_mode(t_fdf *fdf)
{
	if (!fdf->img.depth_mode)
		fdf->img.depth_mode = 1;
	else
		fdf->img.depth_mode = 0;
	if (!ft_new_image(&fdf->img))
		ft_terminate(fdf);
	ft_render_fdf(fdf->t, fdf->m, &fdf->img);
	if (fdf->img.depth_mode)
		mlx_string_put(fdf->img.mlx_ptr, fdf->img.win_ptr, 10, 20, 0xffff00, \
			"DEPTH-SHADE MODE: ON");
	else
		mlx_string_put(fdf->img.mlx_ptr, fdf->img.win_ptr, 10, 20, 0xffff00, \
			"DEPTH-SHADE MODE: OFF");
}
