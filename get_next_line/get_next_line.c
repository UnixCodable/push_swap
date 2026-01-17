/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:30:33 by lbordana          #+#    #+#             */
/*   Updated: 2026/01/17 15:54:43 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*assign_and_clean(char *buffer, char *str, int i)
{
	if (buffer[i] == '\n')
	{
		str = ft_strjoin_gnl(str, ft_substr(buffer, 0, i + 1));
		ft_memset(buffer, 0, i + 1);
		ft_memcart(buffer);
	}
	else
	{
		str = ft_strjoin_gnl(str, ft_substr(buffer, 0, i + 1));
		ft_memset(buffer, 0, BUFFER_SIZE);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*str;
	int				count;
	int				i;

	str = NULL;
	i = 0;
	count = ft_strlen_gnl(buffer);
	if (count == 0)
		count = read(fd, buffer, BUFFER_SIZE);
	while (fd >= 0 && count > 0)
	{
		if (buffer[i] == '\n')
			return (assign_and_clean(buffer, str, i));
		if (++i == count)
		{
			str = assign_and_clean(buffer, str, i);
			count = read(fd, buffer, BUFFER_SIZE);
			i = -1;
		}
	}
	return (str);
}
