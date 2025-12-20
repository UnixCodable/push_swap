/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:54:57 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/12 14:45:58 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		ii;
	char				*sub;

	i = 0;
	ii = 0;
	if (!s)
		return (NULL);
	while (s[i] != 0)
	{
		if (i >= start && ii < len)
			ii++;
		i++;
	}
	sub = malloc((ii + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = -1;
	ii = 0;
	while (s[++i] != 0)
		if (i >= start && ii < len)
			sub[ii++] = s[i];
	sub[ii] = 0;
	return (sub);
}

/*Send back an other string from a given position, without exceeding
a given size*/
