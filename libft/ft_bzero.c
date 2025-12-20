/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:02:38 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/12 15:20:50 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = s;
	while (i < n)
		cpy[i++] = 0;
	s = cpy;
}

/*Delete data from a memory zone and fullfill it with zero*/
