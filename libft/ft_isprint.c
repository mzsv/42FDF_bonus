/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:15:58 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/10 20:53:07 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return ((c >= 32 && c <= 126));
}
/* int	main(void)
{
	char c = 126;

	printf("c = %d\n", ft_isprint(c));
	printf("c = %d (ori)\n", isprint(c));
	return (0);
} */