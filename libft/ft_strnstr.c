/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:02:53 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/12 14:49:21 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	ii;

	i = 0;
	if (little[i] == 0)
		return ((char *)big);
	while (big[i] != 0 && len > i)
	{
		ii = 0;
		if (i > 0 && big[i - 1] == little [0])
			ii = 1;
		if (little[ii] == big[i])
		{
			while (little[ii] == big[i] && len > i)
			{
				ii++;
				i++;
				if (little[ii] == 0)
					return ((char *)big + (i - ii));
			}
		}
		else
			i++;
	}
	return (0);
}

/*Send back a string from the first occurence of a given word or sentence
(without exceeding a given size) and send the address of it*/
