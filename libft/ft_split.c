/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:37:05 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/14 01:24:32 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;
	int		isword;
	size_t	i;

	isword = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (isword == 1)
				count++;
			isword = 0;
		}
		else
			isword = 1;
		i++;
	}
	if (isword)
		count++;
	return (count);
}

static size_t	ft_wordlen(char const *s, char c, size_t w)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	len = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (len >= 1)
			{
				count++;
				if (count == w)
					return (len);
			}
			len = 0;
		}
		else
			len++;
		i++;
	}
	return (len);
}

static size_t	ft_wordstart(char const *s, char c, size_t w)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	len = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (len >= 1)
			{
				count++;
				if (count == w)
					return (i - len);
			}
			len = 0;
		}
		else
			len++;
		i++;
	}
	return (i - len);
}

static void	ft_freestrs(char **strs, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	nmemb;
	size_t	i;

	if (!s)
		return (NULL);
	nmemb = ft_wordcount(s, c);
	strs = (char **)malloc((nmemb + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < nmemb)
	{
		strs[i] = ft_substr(s, ft_wordstart(s, c, i + 1),
				ft_wordlen(s, c, i + 1));
		if (!strs[i])
		{
			ft_freestrs(strs, i);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
/* int main(void)
{
	char *s = "  ola tudo bem ?   ";
	char c = ' ';
	int w = 1;
	size_t i;
	char **strs;
	
	printf("words = %ld\n", ft_wordcount(s, c));
	printf("len = %ld\n", ft_wordlen(s, c, w));
	printf("start = %ld\n", ft_wordstart(s, c, w));
	strs = ft_split(s, c);
	i = 0;
	while (i < ft_wordcount(s, c))
	{
		printf(".%s.\n", strs[i]);
		if (strs[i] == NULL)
			printf("null");
		i++;
	}
	ft_freestrs(strs, ft_wordcount(s, c));
	return(0);
} */