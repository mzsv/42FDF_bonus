/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:58:16 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/11 17:31:05 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)(s + i));
		i++;
	}
	return (0);
}
/* int main(void)
{
	int c = '\0';
	char s[] = "ola tudo bem?";
	size_t n = 145;

	printf("%s%d\n", (char *)ft_memchr(s, c, n),
		*(char *)ft_memchr(s, c, n) == '\0');
	printf("%s%d(ori)\n", (char *)memchr(s, c, n),
		*(char *)memchr(s, c, n) == '\0');
	return (0);
} */