/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:48:04 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/10 20:53:40 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}
/* int main (void)
{
	char s[] = "ola tudo bem?";
	char d[] = "zzzzzzzzzzzzz";
	// char s1[] = "ola tudo bem?";
	// char d1[] = "zzzzzzzzzzzzz";
	size_t a = 0;
	// size_t b = 0;
	size_t size = 4;
	
	a = ft_strlcpy(d, s, size);
	printf("%s, return %ld\n", d, a);
	// b = strlcpy(d1, s1, size);
	// printf("%s(ori), return %ld\n", d1, b);
	return (0);
} */