/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:18:01 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/04 04:12:20 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_nearest(t_nlist **st_b, int nbr)
{
	t_nlist	*voyager;
	int		converted_nb;
	int		nearest;

	voyager = *st_b;
	while (voyager != NULL)
	{
		converted_nb = voyager->nb - nbr;
		if (converted_nb - nbr < nearest - nbr)
	}
	return (nearest);
}

int	best_pivot(t_nlist **st_b)
{
	t_nlist	*voyager;
	int		diff;
	int		sum;
	int		nbrs;

	voyager = *st_b;
	sum = 0;
	nbrs = 0;
	while (voyager != NULL)
	{
		sum += voyager->nb;
		nbrs++;
		voyager = voyager->next;
	}
	diff = sum / nbrs;
	return (find_nearest(st_b, diff));
}

int	min_finder(t_nlist **st_a)
{
	t_nlist	*voyager;
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

void	complex_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	static int	grow;
	int			actual_chunk;
	int			exec;
	t_nlist		*pivot;

	grow++;
	actual_chunk = (*st_a)->chunk;
	if (!(*st_b) && actual_chunk != -1)
	{
		while ((*st_a)->chunk != -1 && ((*st_a)->nb == min_finder(st_a)
				|| (*st_a)->next->nb == min_finder(st_a)))
		{
			if ((*st_a)->nb == min_finder(st_a))
			{
				(*st_a)->chunk = -1;
				ra(st_a, data, 1);
			}
			else
				sa(st_a, data, 1);
		}
		while ((*st_a) && (*st_a)->chunk == actual_chunk)
		{
			pb(st_a, st_b, data);
			if ((*st_b)->next)
				rb(st_b, data, 1);
		}
	}
	pivot = *st_b;
	while (pivot && pivot->next != NULL)
		pivot = pivot->next;
	while (*st_b)
	{
		if ((*st_b)->nb == pivot->nb)
		{
			(*st_b)->chunk = grow;
			pa(st_a, st_b, data);
			break ;
		}
		else if ((*st_b)->nb > pivot->nb)
		{
			(*st_b)->chunk = grow;
			pa(st_a, st_b, data);
		}
		else if ((*st_b)->nb < pivot->nb)
			rb(st_b, data, 1);
	}
	if (compute_disorder(*st_a, data) != 0.00 || (*st_b) != NULL)
		complex_alg(st_a, st_b, data);
	return ;
}
