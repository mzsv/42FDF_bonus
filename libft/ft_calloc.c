/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 01:50:03 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/11 21:24:30 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*s;

	s = malloc(nmemb * size);
	if (!s)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
	return (s);
}
/* int main(void)
{
	char *s;
	char *s1;
	size_t nmemb = 3;
	size_t size = sizeof(char);
	int i;
	
	s = (char *)ft_calloc(nmemb, size);
	i = 0;
	while (i < nmemb)
	{
		if (s[i] == '\0')
			printf("%d", 0);
		else
			printf("%c", s[i]);
		i++;
	}
	printf("\n");
	s1 = (char *)calloc(nmemb, size);
	i = 0;
	while (i < nmemb)
	{
		if (s1[i] == 0)
			printf("%d", 0);
		else
			printf("%c", s1[i]);
		i++;
	}
	free(s);
	free(s1);
	return (0);
} */