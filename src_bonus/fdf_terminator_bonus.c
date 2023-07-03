/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_terminator_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 04:10:10 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:19:13 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	ft_error(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (1);
}

int	ft_free_mlx(void *mlx_ptr, void *img_ptr, void *win_ptr)
{
	int	i;

	i = 0;
	if (img_ptr)
	{
		mlx_destroy_image(mlx_ptr, img_ptr);
		i++;
	}
	if (win_ptr)
	{
		mlx_destroy_window(mlx_ptr, win_ptr);
		i++;
	}
	if (mlx_ptr)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		i++;
	}
	return (i);
}

int	ft_free_fdf(t_fdf *fdf)
{
	int	i;

	i = 0;
	if (fdf->m.map)
	{
		ft_freestrs(fdf->m.map);
		i++;
	}
	if (fdf->p)
	{
		free(fdf->p);
		i++;
	}
	if (fdf->iso)
	{
		free(fdf->iso);
		i++;
	}
	if (fdf->t)
	{
		free(fdf->t);
		i++;
	}
	return (i);
}

int	ft_terminate(void *param)
{
	t_fdf	*fdf;
	int		r;

	fdf = (t_fdf *)param;
	r = ft_free_mlx(fdf->img.mlx_ptr, fdf->img.ptr, fdf->img.win_ptr);
	r += ft_free_fdf(fdf);
	if (r < 7)
		ft_error("Error: memory allocation failed");
	exit(1);
	return (r);
}
