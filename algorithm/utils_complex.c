/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 00:13:20 by lbordana          #+#    #+#             */
/*   Updated: 2026/01/17 17:05:19 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_n	*find_nearest(t_n **st_b, int nbr, int chunk)
{
	t_n	*j;
	int	converted_nb;
	t_n	*nearest;

	j = *st_b;
	converted_nb = INT_MAX;
	while (j != NULL && j->chunk == chunk)
	{
		if (j->nb - nbr < 0 && (j->nb - nbr) * (-1) < converted_nb)
		{
			converted_nb = (j->nb - nbr) * (-1);
			nearest = j;
		}
		else if (j->nb - nbr >= 0 && (j->nb - nbr) < converted_nb)
		{
			converted_nb = (j->nb - nbr);
			nearest = j;
		}
		j = j->next;
	}
	return (nearest);
}

int	check_other_chunk(t_n **stack)
{
	int	chunk;
	t_n	*j;

	chunk = (*stack)->chunk;
	j = *stack;
	while (j != NULL)
	{
		if (j->chunk != chunk)
			return (0);
		j = j->next;
	}
	return (1);
}

// int	chunk_checker_max(t_n **st_b, int max_value)
// {
// 	t_n	*j;

// 	j = *st_b;
// 	while (j)
// 	{
// 		if (j->nb >= max_value)
// 			return (0);
// 		j = j->next;
// 	}
// 	return (1);
// }

// int	chunk_checker_min(t_n **st_a, int actual_chunk, int min_value)
// {
// 	t_n	*j;

// 	j = *st_a;
// 	while (j && j->chunk == actual_chunk)
// 	{
// 		if (j->nb < min_value)
// 			return (0);
// 		j = j->next;
// 	}
// 	return (1);
// }

// int	min_finder(t_n **st_a)
// {
// 	t_n	*j;
// 	int	min;

// 	j = *st_a;
// 	min = j->nb;
// 	while (j != NULL && j->chunk != -1)
// 	{
// 		j = j->next;
// 		if (j && j->nb < min && j->chunk != -1)
// 			min = j->nb;
// 	}
// 	return (min);
// }
