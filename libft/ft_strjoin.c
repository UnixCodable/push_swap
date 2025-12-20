/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:22:30 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/17 18:47:07 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		ii;
	char	*str;

	i = 0;
	ii = 0;
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[ii])
		ii++;
	str = malloc((i + ii + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	ii = 0;
	while (s2[ii])
		str[i++] = s2[ii++];
	str[i] = 0;
	return (str);
}

/*Concat two strings into a new one*/
