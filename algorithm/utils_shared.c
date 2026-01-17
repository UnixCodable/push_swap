/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_shared.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:01:13 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/17 17:07:34 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	min_finder(t_n **st_a)
{
	t_n	*j;
	int	min;

	j = *st_a;
	min = j->nb;
	while (j != NULL && j->chunk != -1)
	{
		j = j->next;
		if (j && j->nb < min && j->chunk != -1)
			min = j->nb;
	}
	return (min);
}

int	chunk_checker_min(t_n **st_a, int actual_chunk, int min_value)
{
	t_n	*j;

	j = *st_a;
	while (j && j->chunk == actual_chunk)
	{
		if (j->nb < min_value)
			return (0);
		j = j->next;
	}
	return (1);
}

int	chunk_checker_max(t_n **st_b, int max_value)
{
	t_n	*j;

	j = *st_b;
	while (j)
	{
		if (j->nb >= max_value)
			return (0);
		j = j->next;
	}
	return (1);
}

int	chunk_checker_max_strict(t_n **st_b, int actual_chunk, int max_value)
{
	t_n	*j;

	j = *st_b;
	while (j)
	{
		if (j->nb > max_value && j->chunk == actual_chunk)
			return (0);
		j = j->next;
	}
	return (1);
}
