/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:17:05 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/17 18:04:16 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	counting_steps(t_n **st_a, t_n **st_b)
{
	int	steps_front;
	int	steps_back;
	t_n	*j;

	j = *st_a;
	steps_back = 0;
	steps_front = 0;
	while (j && j->nb > j->next->nb)
	{
		j = j->next;
		steps_back++;
	}
	while (j && (*st_b)->nb > j->nb)
	{
		j = j->next;
		steps_back++;
	}
	while (j != NULL)
	{
		j = j->next;
		steps_front++;
	}
	if (steps_back >= steps_front)
		return (1);
	return (0);
}

void	sens_rotate(t_n **st_a, t_n **st_b, struct s_d *data)
{
	if (counting_steps(st_a, st_b) == 1)
		while ((*st_a)->nb != min_finder(st_a))
			ra(st_a, data, 1);
	else
	{
		while ((*st_a)->nb > (*st_b)->nb)
		{
			if ((*st_b)->nb < (*st_a)->nb && min_finder(st_a) == (*st_a)->nb)
				break ;
			rra(st_a, data, 1);
		}
	}
}

void	simple_alg(t_n **st_a, t_n **st_b, struct s_d *data)
{
	while ((*st_a)->next != NULL)
	{
		if (chunk_checker_max_strict(st_a, 0, (*st_a)->nb) == 1)
			ra(st_a, data, 1);
		else
			pb(st_a, st_b, data);
	}
	while (*st_b)
	{
		while ((*st_b)->nb > (*st_a)->nb)
			ra(st_a, data, 1);
		pa(st_a, st_b, data);
		if (!*st_b)
		{
			while (compute_disorder(*st_a, data) != 0.00)
				ra(st_a, data, 1);
			break ;
		}
		if ((*st_b) && (*st_a)->nb < (*st_b)->nb)
			continue ;
		sens_rotate(st_a, st_b, data);
	}
	return ;
}
