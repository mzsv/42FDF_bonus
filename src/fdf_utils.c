/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:01:43 by amenses-          #+#    #+#             */
/*   Updated: 2023/07/03 18:18:59 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	isword;
	int	i;

	isword = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (isword == 1)
				count++;
			isword = 0;
		}
		else
			isword = 1;
		i++;
	}
	if (isword)
		count++;
	return (count);
}

void	ft_freestrs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

size_t	ft_2dlen(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
