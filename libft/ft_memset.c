/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:36:38 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/10 20:53:24 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
/* int main (void)
{
	char s[] = "ola tudo bem?";
	int c = 'z';
	size_t n = 3;
	
	printf("%s\n", (char *) ft_memset(s, c, n));
	printf("%s(ori)\n", (char *) memset(s, c, n));
	return (0);
} */