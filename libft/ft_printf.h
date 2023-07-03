/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:26:20 by amenses-          #+#    #+#             */
/*   Updated: 2022/12/10 03:31:42 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_content
{
	int				minus;
	int				zero;
	int				hashtag;
	int				space;
	int				plus;
	size_t			fw;
	long long		prc;
	char			spec;
	size_t			len;
	size_t			offset;
}					t_content;

int					ft_printf(const char *fmt, ...);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnstr_fd(char *s, size_t n, int fd);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);

unsigned long long	ft_atoi_ll(const char *nptr);
size_t				ft_nbrlen_base(unsigned long long nbr, \
						int sign, int base_len);
void				ft_putnbr_base(unsigned long long nbr, char *base);
size_t				ft_max(size_t a, size_t b);
size_t				ft_min(size_t a, size_t b);

char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_isflag(char c);
int					ft_isspec(char c);
size_t				ft_off0(long long n);
int					ft_sign(long long n);

char				*ft_strchr(const char *s, int c);
void				ft_setflags(t_content *a, const char *fmt);
void				ft_setfw(t_content *a, const char *fmt);
void				ft_setprc(t_content *a, const char *fmt);
void				ft_setspec(t_content *a, const char *fmt);

t_content			*ft_getflags(const char *fmt);
void				ft_putc(t_content *a, char c);
void				ft_puts(t_content *a, char *s);
void				ft_padding(t_content *a);
void				ft_printnbr(t_content *a, unsigned long long n, char *base);

void				ft_pkick(t_content *a, unsigned long long p);
void				ft_putp(t_content *a, unsigned long long p);
void				ft_signedkick(t_content *a, long long n);
void				ft_putd(t_content *a, int n);
void				ft_putu(t_content *a, unsigned int n);

void				ft_putx(t_content *a, unsigned int n);
void				ft_putx_upper(t_content *a, unsigned int n);
void				ft_printcontent(t_content *a, va_list arg);
char				*ft_readflags(t_content *a, const char *fmt);
int					ft_isnumspec(char spec);

char				*ft_getnull(t_content *a, int *isnull);

#endif
