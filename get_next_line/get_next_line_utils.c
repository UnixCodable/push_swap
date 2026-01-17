/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:30:28 by lbordana          #+#    #+#             */
/*   Updated: 2026/01/17 15:54:59 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *) s)[i++] = c;
	return (s);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		ii;
	char	*str;

	i = 0;
	ii = 0;
	if (!s1)
		return (s2);
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
	free (s1);
	free (s2);
	return (str);
}

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

void	*ft_memcart(void *cart)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	while (((unsigned char *)cart)[i] == 0 && i < BUFFER_SIZE)
		i++;
	while (i < BUFFER_SIZE)
	{
		((unsigned char *)cart)[ii] = ((unsigned char *)cart)[i];
		ii++;
		i++;
	}
	while (ii < BUFFER_SIZE)
	{
		((unsigned char *)cart)[ii] = 0;
		ii++;
	}
	return (cart);
}

int	ft_strlen_gnl(const char *s)
{
	long int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
