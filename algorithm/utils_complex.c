/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 00:13:20 by lbordana          #+#    #+#             */
/*   Updated: 2026/01/14 18:22:22 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_n	*find_nearest(t_n **st_b, int nbr, int chunk)
{
	t_n	*voyager;
	int		converted_nb;
	t_n	*nearest;

	voyager = *st_b;
	converted_nb = INT_MAX;
	while (voyager != NULL && voyager->chunk == chunk)
	{
		if (voyager->nb - nbr < 0 && (voyager->nb - nbr) * (-1) < converted_nb)
		{
			converted_nb = (voyager->nb - nbr) * (-1);
			nearest = voyager;
		}
		else if (voyager->nb - nbr >= 0 && (voyager->nb - nbr) < converted_nb)
		{
			converted_nb = (voyager->nb - nbr);
			nearest = voyager;
		}
		voyager = voyager->next;
	}
	return (nearest);
}

t_n	*best_pivot(t_n **st_b, int chunk)
{
	t_n	*voyager;
	int		diff;
	int		sum;
	int		nbrs;

	voyager = *st_b;
	sum = 0;
	nbrs = 0;
	if ((*st_b)->chunk != chunk)
		return (NULL);
	while (voyager != NULL && voyager->chunk == chunk)
	{
		sum += voyager->nb;
		nbrs++;
		voyager = voyager->next;
	}
	diff = sum / nbrs;
	return (find_nearest(st_b, diff, chunk));
}

int	check_other_chunk(t_n **stack)
{
	int		chunk;
	t_n	*voyager;

	chunk = (*stack)->chunk;
	voyager = *stack;
	while (voyager != NULL)
	{
		if (voyager->chunk != chunk)
			return (0);
		voyager = voyager->next;
	}
	return (1);
}

int	chunk_checker_max(t_n **st_b, int max_value)
{
	t_n	*voyager;

	voyager = *st_b;
	while (voyager)
	{
		if (voyager->nb >= max_value)
			return (0);
		voyager = voyager->next;
	}
	return (1);
}

int	chunk_checker_min(t_n **st_a, int actual_chunk, int min_value)
{
	t_n	*voyager;

	voyager = *st_a;
	while (voyager && voyager->chunk == actual_chunk)
	{
		if (voyager->nb < min_value)
			return (0);
		voyager = voyager->next;
	}
	return (1);
}

int	min_finder(t_n **st_a)
{
	t_n	*voyager;
	int		min;

	voyager = *st_a;
	min = voyager->nb;
	while (voyager != NULL && voyager->chunk != -1)
	{
		voyager = voyager->next;
		if (voyager && voyager->nb < min && voyager->chunk != -1)
			min = voyager->nb;
	}
	return (min);
}
