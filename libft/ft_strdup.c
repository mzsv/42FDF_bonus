/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:05:23 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/10 22:08:06 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = 0;
	while (s[len])
		len++;
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	len = 0;
	while (s[len])
	{
		dup[len] = s[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}
/* int main(void)
{
	char s[] = "ola tudo bem?";
	char *dup;
	char *dup1;
	int i;

	dup = ft_strdup(s);
	i = 0;
	while (dup[i])
	{
		printf("%c", dup[i]);
		i++;
	}
	free(dup);
	dup1 = strdup(s);
	printf("\n");
	i = 0;
	while (dup1[i])
	{
		printf("%c", dup1[i]);
		i++;
	}
	free(dup1);
	return (0);
} */