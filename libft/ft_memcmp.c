/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 00:19:51 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/10 20:53:15 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s1)[i] != ((unsigned char *)s2)[i]))
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/* int main(void)
{
	char s1[] = "ola tudo bem?";
	char s2[] = "ola tudo bem?";
	size_t n = 100;

	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("%d(ori)\n", memcmp(s1, s2, n));
	return (0);
} */