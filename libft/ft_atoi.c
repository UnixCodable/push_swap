/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:32:46 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/18 12:29:38 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	is_negative;

	i = 0;
	nbr = 0;
	is_negative = 0;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			is_negative = 1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		nbr = (nbr * 10) + (nptr[i] - 48);
		i++;
	}
	if (is_negative == 1)
		nbr *= (-1);
	return (nbr);
}

/*Convert an ascii into an integer*/
