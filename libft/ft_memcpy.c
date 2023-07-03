/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:50:03 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/11 21:24:41 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/* int main (void)
{
	char s[] = "ola tudo bem?";
	char d[] = "zzzzzzzzzzzzz";
	char s1[] = "ola tudo bem?";
	char d1[] = "zzzzzzzzzzzzz";
	size_t n = 10;
	
	printf("%s\n", (char *) ft_memcpy(d, s, n));
	printf("%s(ori)\n", (char *) ft_memcpy(d1, s1, n));
	return (0);
} */