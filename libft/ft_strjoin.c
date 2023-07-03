/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:25:42 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/11 21:57:12 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		s[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		s[i] = s2[i - s1_len];
		i++;
	}
	s[i] = '\0';
	return (s);
}
/* int main(void)
{
	char *s1 = "a", *s2 = "b";
	char *s;
	
	s = ft_strjoin(s1, s2);
	printf("%s.\nlen = %ld\n", s, ft_strlen(s1) + ft_strlen(s2));
	free(s);
	return (0);
} */