/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 01:41:20 by lbordanave        #+#    #+#             */
/*   Updated: 2025/11/16 18:02:37 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	mod;

	mod = 0;
	if (fd < 0)
		return ;
	if (n > INT_MAX || n < INT_MIN)
		return ;
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0 && n > INT_MIN)
	{
		write(fd, "-", 1);
		n *= (-1);
	}
	mod = (mod * 10) + (n % 10) + 48;
	if (n <= 9 && n >= 0)
		write (fd, &mod, 1);
	if (n > 9)
	{
		ft_putnbr_fd((n /= 10), fd);
		write (fd, &mod, 1);
	}
}

/*Write a number into a text file*/
