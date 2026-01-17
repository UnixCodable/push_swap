/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:37:24 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/14 18:22:22 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	push_chunk(long int i, t_n **st_a, t_n **st_b, struct s_d *data)
{
	while (chunk_present(st_a, i) == 1 || chunk_present(st_a, i + 1) == 1)
	{
		if ((*st_a)->chunk == i)
			pb(st_a, st_b, data);
		else if ((*st_a)->chunk == (i + 1))
		{
			pb(st_a, st_b, data);
			if (!(*st_a) || (*st_a)->chunk == i || (*st_a)->chunk == i + 1)
				rb(st_b, data, 1);
			else
				rr(st_a, st_b, data);
		}
		else
			ra(st_a, data, 1);
	}
}

void	arrange_chunk(t_n **st_a, t_n **st_b, struct s_d *data)
{
	long int	i;
	t_n			*j;

	i = 1;
	while ((*st_a) != NULL)
	{
		push_chunk(i, st_a, st_b, data);
		j = *st_b;
		while (j && j->chunk != i)
			j = j->next;
		while (j && j->chunk != i + 1)
			j = j->next;
		if (j == NULL)
			break ;
		while ((*st_b)->nb != j->nb)
			rrb(st_b, data, 1);
		i += 2;
	}
}

void	place_chunk(t_n *j, t_n **st_a, t_n **st_b, struct s_d *data)
{
	while (((*st_a) && (*st_a)->chunk == (*st_b)->chunk) || ((*st_a)
			&& (*st_a)->chunk != -1))
	{
		while ((*st_b)->nb > (*st_a)->nb)
			rb(st_b, data, 1);
		pb(st_a, st_b, data);
		if ((*st_a) && (*st_a)->nb < (*st_b)->nb)
			continue ;
		while ((*st_a) && (*st_b) && (*st_b)->nb < (*st_a)->nb && j->next)
			rrb(st_b, data, 1);
	}
}

void	simple_alg_chunk(t_n **st_a, t_n **st_b, struct s_d *data, long int i)
{
	t_n	*j;

	while ((*st_b) && (*st_b)->next != NULL && (*st_b)->chunk == i)
	{
		if (chunk_checker_min_strict(st_b, i, (*st_b)->nb) == 1)
			rb(st_b, data, 1);
		else
			pa(st_a, st_b, data);
	}
	if ((*st_b)->next)
		rrb(st_b, data, 1);
	j = *st_b;
	while (j->next != NULL)
		j = j->next;
	place_chunk(j, st_a, st_b, data);
	while (chunk_checker_max_strict(st_b, i, (*st_b)->chunk) != 1 && j->next)
		rrb(st_b, data, 1);
	while ((*st_b) && (*st_b)->chunk == i)
	{
		(*st_b)->chunk = -1;
		pa(st_a, st_b, data);
	}
	if (i > 1)
		simple_alg_chunk(st_a, st_b, data, --i);
	return ;
}

void	med_alg(t_n **st_a, t_n **st_b, struct s_d *data, struct s_m *med)
{
	chunk(st_a, data, med);
	arrange_chunk(st_a, st_b, data);
	simple_alg_chunk(st_a, st_b, data, med->n_chunk);
}
