/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:25:17 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/10 20:53:56 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i] == c)
		return ((char *)(s + i));
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
/* int main(void)
{
	int c = '?';
	char s[] = "ola tudo bem? sim e contigo?";

	printf("%s%d\n", ft_strrchr(s, c), *ft_strrchr(s, c) == '\0');
	printf("%s%d(ori)\n", strrchr(s, c), *strrchr(s, c) == '\0');
	return (0);
} */