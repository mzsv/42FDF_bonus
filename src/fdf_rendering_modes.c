/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering_modes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:40:05 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:18:59 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	ft_render_fdf(fdf->p, fdf->m, &fdf->img);
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
