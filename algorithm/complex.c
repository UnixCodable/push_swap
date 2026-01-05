/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:18:01 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/05 21:09:30 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_nlist	*find_nearest(t_nlist **st_b, int nbr, int chunk)
{
	t_nlist	*voyager;
	int		converted_nb;
	t_nlist	*nearest;

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

t_nlist	*best_pivot(t_nlist **st_b, int chunk)
{
	t_nlist	*voyager;
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

int	check_other_chunk(t_nlist **stack)
{
	int		chunk;
	t_nlist	*voyager;

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

int	chunk_checker_max(t_nlist **st_b, int max_value)
{
	t_nlist	*voyager;

	voyager = *st_b;
	while (voyager)
	{
		if (voyager->nb >= max_value)
			return (0);
		voyager = voyager->next;
	}
	return (1);
}

int	chunk_checker_min(t_nlist **st_a, int actual_chunk, int min_value)
{
	t_nlist	*voyager;

	voyager = *st_a;
	while (voyager && voyager->chunk == actual_chunk)
	{
		if (voyager->nb < min_value)
			return (0);
		voyager = voyager->next;
	}
	return (1);
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
	double		disorder;
	t_nlist		*pivot;
	t_nlist		*voyager;

	grow++;
	actual_chunk = (*st_a)->chunk;
	if (data->low_disorder)
		disorder = 0.19;
	else if (data->med_disorder)
		disorder = 0.39;
	else
		disorder = 0.00;
	if (!(*st_b) && actual_chunk != -1)
	{
		while ((*st_a)->chunk != -1 && ((*st_a)->nb == min_finder(st_a)
				|| (*st_a)->next->nb == min_finder(st_a)
				|| (*st_a)->next->next->nb == min_finder(st_a)))
		{
			if ((*st_a)->nb != min_finder(st_a) && (*st_a)->next->nb != min_finder(st_a))
			{
				ra(st_a, data, 1);
				sa(st_a, data, 1);
				rra(st_a, data, 1);
			}
			if ((*st_a)->nb != min_finder(st_a))
				sa(st_a, data, 1);
			(*st_a)->chunk = -1;
			ra(st_a, data, 1);
		}
		pivot = best_pivot(st_a, actual_chunk);
		while (pivot && (*st_a) && (*st_a)->chunk == actual_chunk)
		{
			if (chunk_checker_min(st_a, actual_chunk, pivot->nb) == 1)
				break ;
			else if ((*st_a)->nb < pivot->nb)
				pb(st_a, st_b, data);
			else if ((*st_a)->nb >= pivot->nb && (*st_a)->next)
				ra(st_a, data, 1);
		}
		if (check_other_chunk(st_a) == 0)
		{
			voyager = *st_a;
			while (voyager != NULL && voyager->chunk != -1)
				voyager = voyager->next;
			while (voyager != NULL && voyager->chunk == -1)
				voyager = voyager->next;
			while (voyager && (*st_a)->nb != voyager->nb)
				rra(st_a, data, 1);
		}
	}
	if (*st_b)
		pivot = best_pivot(st_b, (*st_b)->chunk);
	while (*st_b)
	{
		if (chunk_checker_max(st_b, pivot->nb) == 1)
			break ;
		else if ((*st_b)->nb >= pivot->nb)
		{
			(*st_b)->chunk = grow;
			pa(st_a, st_b, data);
		}
		else if ((*st_b)->nb == min_finder(st_b))
		{
			(*st_b)->chunk = -1;
			pa(st_a, st_b, data);
			ra(st_a, data, 1);
		}
		else if ((*st_b)->nb < pivot->nb && (*st_b)->next)
			rb(st_b, data, 1);
	}
	if (compute_disorder(*st_a, data) > disorder || (*st_b) != NULL)
		complex_alg(st_a, st_b, data);
	else if (disorder > 0.00)
	{
		data->disorder = compute_disorder(*st_a, data);
		ft_lst_print(*st_a);
	}
	return ;
}
