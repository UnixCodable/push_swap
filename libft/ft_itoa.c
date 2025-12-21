/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:59:40 by lbordana          #+#    #+#             */
/*   Updated: 2025/12/21 03:24:58 by lbordanave       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert(char *to_convert,
	long int nbr, int counter, int is_negative)
{
	int	i;

	i = 0;
	if (!to_convert)
		return (NULL);
	if (is_negative == 1)
	{
		to_convert[i++] = '-';
		counter--;
		nbr *= (-1);
	}
	while (counter != 0)
	{
		to_convert[i] = (nbr % 10) + 48;
		counter--;
		nbr /= 10;
		i++;
	}
	to_convert[i] = '\0';
	return (to_convert);
}

char	*ft_itoa(int n)
{
	char		*converted;
	long int	i;
	int			counter;
	int			is_negative;

	i = 0;
	counter = 0;
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		counter++;
	}
	if (n == 0)
		counter++;
	while (n != 0)
	{
		i = (i * 10) + (n % 10);
		n /= 10;
		counter++;
	}
	converted = malloc((counter + 1) * sizeof(char));
	converted = convert(converted, i, counter, is_negative);
	return (converted);
}

/*Convert an int into ascii*/
