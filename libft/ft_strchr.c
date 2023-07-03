/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:59:35 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/10 20:53:28 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (0);
}
/* int main(void)
{
	int c = 'u';
	char s[] = "ola tudo bem?";

	printf("%s%d\n", ft_strchr(s, c), *ft_strchr(s, c) == '\0');
	printf("%s%d(ori)\n", strchr(s, c), *strchr(s, c) == '\0');
	return (0);
} */