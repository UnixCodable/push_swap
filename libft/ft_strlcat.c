/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:59:35 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/14 01:46:09 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	ii;
	size_t	check;

	i = 0;
	len = 0;
	ii = 0;
	check = 0;
	len = ft_strlen(src);
	while (i < size && dst[i] != 0)
	{
		i++;
		if ((i == size || dst[i] == 0) && check == 0)
			check += i;
	}
	while (size - 1 > i && src[ii] != 0 && size != 0)
		dst[i++] = src[ii++];
	if (i < size)
		dst[i] = 0;
	return (len + check);
}

/*Concat two string without exceeding a given size and return the length that
was trying to be concat*/
