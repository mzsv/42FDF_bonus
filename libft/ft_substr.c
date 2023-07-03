/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:31:09 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/11 20:37:55 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (start > i)
		len = 0;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/* int main(void)
{
	char s[] = "ola tudo bem?";
	char *dup;
	int i;

	dup = ft_substr(s, 2, 5);
	if (dup == NULL)
		printf("naaaa");
	else
	{
		i = 0;
		while (dup[i])
		{
			printf("%c", dup[i]);
			i++;
		}
	}
	free(dup);
	return (0);
} */