/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:59:35 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/12 14:55:50 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ii;

	i = 0;
	ii = 0;
	while (src[ii] != 0)
		ii++;
	if (size == 0)
		return (ii);
	if (size == 1)
	{
		dst[i] = 0;
		return (ii);
	}
	while (i < (size - 1) && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ii);
}

/*Copy a string into an other while not exceeding a given size and return the
length of it*/
