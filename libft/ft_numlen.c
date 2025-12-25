/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 02:41:29 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/25 03:01:07 by lbordanave       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int nbr)
{
	char	*convert;
	int		size;

	convert = ft_itoa(nbr);
	size = ft_strlen(convert);
	free(convert);
	return (size);
}
