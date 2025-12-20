/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 23:53:58 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/12 14:58:22 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i++;
	}
	if (c == 0)
		return ((char *) s + i);
	return (0);
}

/*Search in two string the first occurence of a given decimal converted into
ascii and send back the address of it*/
