/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:48:36 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/12 14:46:26 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	size_t			end;
	unsigned int	start;
	int				i;

	if (set == NULL || s1 == NULL)
		return (NULL);
	end = ft_strlen(s1) - 1;
	start = 0;
	i = -1;
	while (set[++i] != 0)
	{
		if (s1[end] == set[i])
		{
			end--;
			i = -1;
		}
		else if (s1[start] == set[i])
		{
			start++;
			i = -1;
		}
	}
	trimmed = ft_substr(s1, start, (((unsigned int)end + 1) - start));
	return (trimmed);
}

/*Remove a set of char from a given string*/
