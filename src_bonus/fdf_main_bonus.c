/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:21:35 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:19:13 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

static void	ft_input_check(char *argv)
{
	size_t	len;

	len = ft_strlen(argv);
	if (ft_strnstr(argv, ".fdf", len) != (argv + len - 4))
		ft_error("Error: run with a valid fdf file");
}

void	ft_display_menu(t_image img)
{
	mlx_string_put(img.mlx_ptr, img.win_ptr, 10, 20, 0xffff00, \
		"+ + + + + + + + + + + + + + + + + + + + + +");
	mlx_string_put(img.mlx_ptr, img.win_ptr, 10, 40, 0xffff00, \
		"+                HELP                     +");
	mlx_string_put(img.mlx_ptr, img.win_ptr, 10, 60, 0xffff00, \
		"+ + + + + + + + + + + + + + + + + + + + + +");
	mlx_string_put(img.mlx_ptr, img.win_ptr, 10, 80, 0xffff00, \
		" left mouse button:   rotation");
	mlx_string_put(img.mlx_ptr, img.win_ptr, 10, 100, 0xffff00, \
		" right mouse button:  translation");
	mlx_string_put(img.mlx_ptr, img.win_ptr, 10, 120, 0xffff00, \
		" scroll up/down:      zoom in/out");
	mlx_string_put(img.mlx_ptr, img.win_ptr, 10, 140, 0xffff00, \
		" press C:             change color mode");
	mlx_string_put(img.mlx_ptr, img.win_ptr, 10, 160, 0xffff00, \
		" press H:             help");
	mlx_string_put(img.mlx_ptr, img.win_ptr, 10, 180, 0xffff00, \
		" press I:             isometric mode");
	mlx_string_put(img.mlx_ptr, img.win_ptr, 10, 200, 0xffff00, \
		" press P:             perspective mode");
	mlx_string_put(img.mlx_ptr, img.win_ptr, 10, 220, 0xffff00, \
		" press S:             depth-shade mode");
}

static void	ft_fdf_loop(t_fdf *fdf)
{
	mlx_key_hook(fdf->img.win_ptr, ft_key_hook, fdf);
	mlx_hook(fdf->img.win_ptr, 04, 1L << 2, ft_mouse_press, fdf);
	mlx_hook(fdf->img.win_ptr, 05, 1L << 3, ft_mouse_release, fdf);
	mlx_hook(fdf->img.win_ptr, 06, 1L << 6, ft_mouse_move, fdf);
	mlx_hook(fdf->img.win_ptr, 17, 1L << 17, ft_terminate, fdf);
	mlx_loop(fdf->img.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		ft_error("Error: run with one filename (only)");
	ft_input_check(argv[1]);
	fdf = ft_init_fdf();
	ft_read_map(&fdf.m, argv[1]);
	if (!fdf.m.map)
		ft_terminate(&fdf);
	fdf.p = ft_get_points(&fdf.m);
	if (!fdf.p)
		ft_terminate(&fdf);
	ft_points_color(fdf.p, fdf.m, &fdf.img);
	ft_isometric_proj(&fdf);
	fdf.iso = ft_pointsdup(fdf.p, fdf.m);
	fdf.t = ft_pointsdup(fdf.p, fdf.m);
	if (!fdf.iso || !fdf.t)
		ft_terminate(&fdf);
	ft_render_fdf(fdf.p, fdf.m, &fdf.img);
	ft_display_menu(fdf.img);
	ft_fdf_loop(&fdf);
	return (0);
}
