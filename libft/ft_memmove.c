/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:09:32 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/11 17:29:38 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = n - 1;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/* int main (void)
{
	char s[] = "ola tudo bem?";
	// char d[] = "zzzzzzzzzzzzz";
	char s1[] = "ola tudo bem?";
	// char d1[] = "zzzzzzzzzzzzz";
	size_t n = 3;
	
	printf("%s\n", (char *) ft_memmove(s, s+4, n));
	printf("%s(ori)\n", (char *) memmove(s1, s1+4, n));
	return (0);
} */