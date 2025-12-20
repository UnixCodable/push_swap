/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:35:02 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/13 10:11:50 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a_zero;
	size_t	i;
	size_t	overflow;

	i = 0;
	overflow = nmemb * size;
	if (!nmemb || !size)
		return (malloc(0));
	else if (nmemb * size > __INT_MAX__ || overflow / nmemb != size)
		return (NULL);
	a_zero = malloc((nmemb * size));
	if (!a_zero)
		return (NULL);
	while (i != (nmemb * size))
	{
		((char *)a_zero)[i] = 0;
		i++;
	}
	return (a_zero);
}

/*Allocate memory and fullfill it with zero (0)*/
