/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 02:41:29 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/14 16:20:54 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *str)
{
	int				i;
	long long int	int_checker;

	i = 0;
	int_checker = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != 0)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		int_checker = (int_checker * 10) + (str[i] - 48);
		i++;
	}
	if (str[0] == '-')
		int_checker *= (-1);
	if (int_checker > 2147483647 || int_checker < -2147483648 || i > 15)
		return (0);
	return (1);
}
