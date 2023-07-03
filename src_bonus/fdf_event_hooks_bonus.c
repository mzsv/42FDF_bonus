/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event_hooks_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:28:27 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:19:13 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	ft_mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->img.cursor[0] = x;
	fdf->img.cursor[1] = y;
	if (button == 1)
		fdf->img.rotate = 1;
	if (button == 3)
		fdf->img.translate = 1;
	if (button == 4 || button == 5)
	{
		if (button == 4)
			fdf->img.zoom *= 1 + ZOOMF;
		else
			fdf->img.zoom *= 1 - ZOOMF;
		ft_rescale(fdf->p, fdf->t, fdf);
		if (fdf->img.perspective_mode)
			ft_weak_perspective(fdf);
		if (!ft_new_image(&fdf->img))
			ft_terminate(fdf);
		ft_render_fdf(fdf->t, fdf->m, &fdf->img);
	}
	return (0);
}

int	ft_mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->img.rotate)
	{
		ft_rotated_proj(fdf, x, y);
		ft_rescale(fdf->p, fdf->t, fdf);
		if (fdf->img.perspective_mode)
			ft_weak_perspective(fdf);
		if (!ft_new_image(&fdf->img))
			ft_terminate(fdf);
		ft_render_fdf(fdf->t, fdf->m, &fdf->img);
	}
	if (fdf->img.translate)
	{
		fdf->img.center[0] += (x - fdf->img.cursor[0]) * TRANSF;
		fdf->img.center[1] += (y - fdf->img.cursor[1]) * TRANSF;
		if (!ft_new_image(&fdf->img))
			ft_terminate(fdf);
		ft_render_fdf(fdf->t, fdf->m, &fdf->img);
	}
	fdf->img.cursor[0] = x;
	fdf->img.cursor[1] = y;
	return (0);
}

int	ft_key_hook(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == KEY_ESC)
		ft_terminate(param);
	if (keycode == KEY_C)
		ft_color_mode(fdf);
	if (keycode == KEY_H)
		ft_display_menu(fdf->img);
	if (keycode == KEY_I)
		ft_isometric_mode(fdf);
	if (keycode == KEY_P)
		ft_perspective_mode(fdf);
	if (keycode == KEY_S)
		ft_depth_mode(fdf);
	return (0);
}

int	ft_mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == 1)
		fdf->img.rotate = 0;
	if (button == 3)
		fdf->img.translate = 0;
	return (0);
}
