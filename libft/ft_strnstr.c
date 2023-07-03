/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 00:37:03 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/10 20:53:53 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (little[j] && (big[i + j] == little[j]) && (i + j < len))
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}
/* int main()
{
    char str[] = "ola tudo bem?";
    char to_find[] = "tu";
	size_t len = 5;

	if (ft_strnstr(str, to_find, len) == 0)
		printf("null\n");
	else
    	printf("%s\n", ft_strnstr(str, to_find, len));
} */