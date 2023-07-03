/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:11:40 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/14 01:21:41 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(unsigned int nbr, int sign)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	if (sign == 1)
		return (len);
	else
		return (len + 1);
}

char	*ft_itoa(int n)
{
	char			*s;
	int				len;
	unsigned int	nbr;
	int				sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	nbr = n * sign;
	len = ft_nbrlen(nbr, sign);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (len > 0)
	{
		s[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	if (n < 0)
		s[len] = '-';
	return (s);
}
/* int main(void)
{
	size_t nbr = -2147483648;
	char *s;
	int sign = -1;
	
	printf("%ld -> %d\n", nbr, ft_nbrlen(nbr, sign));
	// printf("%d", 10 * (-sign));
	s = ft_itoa(nbr);
	printf("%s\n", ft_itoa(nbr));
	free(s);
	return (0);
} */