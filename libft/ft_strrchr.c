/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 23:53:58 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/12 14:47:37 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		ii;
	int		counter;

	i = 0;
	ii = 0;
	counter = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char) c)
		{
			ii = i;
			counter++;
		}
		i++;
	}
	if (counter > 0)
		return ((char *) s + ii);
	else if (c == 0)
		return ((char *) s + i);
	return (0);
}

/*Search in two string the first occurence of a given char, converted as
a decimal, then send back the address of it*/
