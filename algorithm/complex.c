/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:18:01 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/14 19:21:31 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_n	*best_pivot(t_n **st_b, int chunk)
{
	t_n	*j;
	int	diff;
	int	sum;
	int	nbrs;

	j = *st_b;
	sum = 0;
	nbrs = 0;
	if ((*st_b)->chunk != chunk)
		return (NULL);
	while (j != NULL && j->chunk == chunk)
	{
		sum += j->nb;
		nbrs++;
		j = j->next;
	}
	diff = sum / nbrs;
	return (find_nearest(st_b, diff, chunk));
}

void	stack_sorting(t_n **st_a, t_n **st_b, struct s_d *data)
{
	static int	grow;
	t_n			*pivot;

	grow++;
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
}

void	send_and_clean(t_n **st_a, t_n **st_b, struct s_d *data,
	int actual_chunk)
{
	t_n	*pivot;
	t_n	*j;

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
		j = *st_a;
		while (j != NULL && j->chunk != -1)
			j = j->next;
		while (j != NULL && j->chunk == -1)
			j = j->next;
		while (j && (*st_a)->nb != j->nb)
			rra(st_a, data, 1);
	}
}

void	sort_me(t_n **st_a, struct s_d *data)
{
	while ((*st_a)->chunk != -1 && ((*st_a)->nb == min_finder(st_a)
			|| (*st_a)->next->nb == min_finder(st_a)
			|| (*st_a)->next->next->nb == min_finder(st_a)))
	{
		if ((*st_a)->nb != min_finder(st_a)
			&& (*st_a)->next->nb != min_finder(st_a))
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
}

void	complex_alg(t_n **st_a, t_n **st_b, struct s_d *data)
{
	int			actual_chunk;
	double		disorder;

	actual_chunk = (*st_a)->chunk;
	if (data->low_disorder)
		disorder = 0.19;
	else if (data->med_disorder)
		disorder = 0.39;
	else
		disorder = 0.00;
	if (!(*st_b) && actual_chunk != -1)
	{
		sort_me(st_a, data);
		send_and_clean(st_a, st_b, data, actual_chunk);
	}
	stack_sorting(st_a, st_b, data);
	if (compute_disorder(*st_a, data) > disorder || (*st_b) != NULL)
		complex_alg(st_a, st_b, data);
	else if (disorder > 0.00)
	{
		data->disorder = compute_disorder(*st_a, data);
		ft_lst_print(*st_a);
	}
	return ;
}
