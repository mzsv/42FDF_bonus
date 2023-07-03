/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:28:23 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/10 20:52:46 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
/* int main (void)
{
	char s[] = "ola tudo bem?";
	char s1[] = "ola tudo bem?";
	size_t n = 3;
	int len = strlen(s);
	int i;
	
	ft_bzero(s, n);
	i = 0;
	while (i < len)
	{
		if (s[i] == '\0')
			printf("%d", 0);
		else
			printf("%c", s[i]);
		i++;
	}
	bzero(s1, n);
	i = 0;
	while (i < len)
	{
		if (s1[i] == '\0')
			printf("%d", 0);
		else
			printf("%c", s1[i]);
		i++;
	}
	return (0);
} */