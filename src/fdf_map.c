/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:49:56 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:18:59 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_getdimensions(t_model *m, char **map)
{
	int	i;

	m->ncols = ft_wordcount(map[0], ' ');
	i = 1;
	while (map[i] && m->ncols == ft_wordcount(map[i], ' '))
		i++;
	while (map[m->nrows])
		m->nrows++;
	if (m->nrows != i || m->ncols < 2 || m->nrows < 2)
	{
		ft_freestrs(map);
		return (1);
	}
	m->nelem = m->ncols * m->nrows;
	m->scale = 0.9 * ft_min(WINH, WINW) / sqrt(pow(m->ncols, 2) \
		+ pow(m->nrows, 2));
	return (0);
}

static int	ft_charcheck(char *data)
{
	char	*tmp;

	tmp = data;
	while (*tmp)
	{
		if (ft_isdigit(*tmp) || *tmp == '-' || *tmp == '+' || \
			(*tmp >= 9 && *tmp <= 13) || *tmp == 32 || *tmp == ',' || \
			*tmp == 'x' || (*tmp >= 'A' && *tmp <= 'F') || \
			(*tmp >= 'a' && *tmp <= 'f'))
			tmp++;
	}
	if (*tmp)
		return (1);
	return (0);
}

int	ft_read_map(t_model *m, char *fn)
{
	int		n;
	int		fd;
	char	*buff;
	char	**tmp;

	fd = open(fn, 00);
	buff = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if (!buff)
		return (ft_error("Error: memory allocation failed"));
	n = read(fd, buff, BUFF_SIZE);
	close(fd);
	if (n < 0)
		return (free(buff), ft_error("Error: failed to read map"));
	if (n == BUFF_SIZE)
		return (free(buff), ft_error("Error: map too big"));
	if (ft_charcheck(buff) == 1)
		return (free(buff), ft_error("Error: invalid map"));
	tmp = ft_split(buff, '\n');
	if (!tmp)
		return (free(buff), ft_error("Error: failed to read map"));
	if (ft_getdimensions(m, tmp) == 1)
		return (free(buff), ft_error("Error: invalid map"));
	m->map = tmp;
	return (free(buff), 0);
}
