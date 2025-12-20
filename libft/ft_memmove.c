/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:02:38 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/12 15:02:31 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	if (dest > src)
	{
		i = n;
		while (i--)
			((char *)dest)[i] = ((char *)src)[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *) dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*Copy bytes in an other memory zone and handle overlap*/
