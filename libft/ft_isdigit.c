/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:53:51 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/10 20:53:04 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
/* int	main(void)
{
	char c = '0';

	printf("c = %d\n", ft_isdigit(c));
	printf("c = %d (ori)\n", isdigit(c));
	return (0);
} */