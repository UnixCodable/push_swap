/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:20:33 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/14 02:15:14 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_counter(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			counter++;
		i++;
	}
	return (counter);
}

static char	**mallocator(char const *s, char c)
{
	int		i;
	int		ii;
	int		last_size;
	int		split;
	char	**splitted;

	i = -1;
	ii = 0;
	last_size = -1;
	split = c_counter(s, c);
	splitted = ft_calloc((split + 1), sizeof(char *));
	while ((i < 0 || s[i] != 0) && splitted != NULL)
	{
		i++;
		if (i > 0 && (s[i] == c || s[i] == 0) && s[i - 1] != c)
		{
			splitted[ii] = ft_calloc((i - last_size), sizeof(char));
			last_size = i;
			ii++;
		}
		else if (s[i] == c)
			last_size++;
	}
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;
	int		ii;
	int		iii;

	i = -1;
	ii = 0;
	iii = 0;
	if (!s)
		return (NULL);
	splitted = mallocator(s, c);
	if (!splitted)
		return (NULL);
	while (i < 0 || s[i] != 0)
	{
		if (s[++i] != c && s[i] != 0)
			splitted[ii][iii++] = s[i];
		if (i > 0 && (s[i] == c || s[i] == 0) && s[i - 1] != c && s[i - 1] > 0)
		{
			splitted[ii++][iii] = '\0';
			iii = 0;
		}
	}
	splitted[ii] = 0;
	return (splitted);
}

/*Split a given string into new one thanks to a given delimiter*/
