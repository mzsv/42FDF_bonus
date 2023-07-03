/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:42:42 by amenses-          #+#    #+#             */
/*   Updated: 2022/11/13 17:41:46 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, (s + i), 1);
		i++;
	}
	write(fd, "\n", 1);
}
/* int main(void)
{
	char s[] = "ola tudo bem?";
	ft_putendl_fd(s, 1);
	return (0);
} */