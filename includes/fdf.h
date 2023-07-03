/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:23:35 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:21:52 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# define PI 		3.14159265358979323846264338
# define TITLE		"fdf_mandatory"
# define WINW		1920
# define WINH		1080
# define DCOLOR		0xff00
# define DMCOLOR	0x696969
# define LCOLOR		0x006994
# define NCOLOR		0xcdaa6d
# define HCOLOR		0xe43414
# define Z_SCALE	0
# define KEY_C		0x0063
# define KEY_H		0x0068
# define KEY_ESC	0xff1b
# define BUFF_SIZE	7000000

typedef struct s_model
{
	char	**map;
	int		nrows;
	int		ncols;
	int		nelem;
	double	scale;
}	t_model;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color[2];
}	t_point;

typedef struct s_matrix
{
	double	rot_x[3][3];
	double	rot_y[3][3];
	double	rot_z[3][3];
}	t_matrix;

typedef struct s_image
{
	void	*mlx_ptr;
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
	void	*win_ptr;
	double	range_z[2];
	int		center[2];
	int		color_mode;
}	t_image;

typedef struct s_lpvar
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		e;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
}	t_lpvar;

typedef struct s_fdf
{
	t_model		m;
	t_point		*p;
	t_point		*t;
	t_point		*iso;
	t_image		img;
	t_matrix	mat;
}	t_fdf;

void		ft_display_menu(t_image img);

int			ft_inter_color(int color_0, int color_1, double f);

int			ft_color_gradient(t_point p0, t_point p1, t_lpvar v, t_image img);

int			ft_pxl_color(t_point p0, t_point p1, t_lpvar v, t_image img);

int			ft_key_hook(int keycode, void *param);

t_model		ft_init_model(void);

t_image		ft_init_image(void);

t_matrix	ft_init_mat(void);

t_fdf		ft_init_fdf(void);

int			ft_read_map(t_model *m, char *fn);

int			ft_abs(int n);

double		ft_dmax(double a, double b);

double		ft_dmin(double a, double b);

void		ft_swap(double a, double b);

int			ft_round(double n);

t_matrix	ft_rotation(t_matrix mat, double alpha, double beta, double gamma);

t_point		ft_matmul(double m[3][3], t_point p);

t_point		*ft_get_points(t_model *m);

void		ft_points_color(t_point *p, t_model m, t_image *img);

t_point		*ft_adjust_z(t_point *p, t_model m);

double		ft_z_scale(t_point *p, int nelem, int len, double map_scale);

void		ft_findrange_z(t_point *p, t_image *img, int nelem);

void		ft_isometric_proj(t_fdf *fdf);

void		ft_pixel_put(t_image *img, int x, int y, int color);

t_lpvar		ft_lp_initvar(t_image img, t_point p0, t_point p1);

void		ft_line_put(t_image img, t_point p0, t_point p1);

void		ft_render_fdf(t_point *p, t_model m, t_image *img);

int			ft_new_image(t_image *img);

void		ft_color_mode(t_fdf *fdf);

void		ft_isometric_mode(t_fdf *fdf);

int			ft_error(char *msg);

int			ft_free_mlx(void *mlx_ptr, void *img_ptr, void *win_ptr);

int			ft_free_fdf(t_fdf *fdf);

int			ft_terminate(void *param);

int			ft_wordcount(char const *s, char c);

size_t		ft_2dlen(char **s);

void		ft_freestrs(char **strs);

#endif
