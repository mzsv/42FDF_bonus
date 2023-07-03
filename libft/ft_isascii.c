/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:09:07 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/10 20:53:01 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}
/* int	main(void)
{
	char c = 0;

	printf("c = %d\n", ft_isascii(c));
	printf("c = %d (ori)\n", isascii(c));
	return (0);
} */