/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:17:05 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/08 13:52:21 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	counting_steps(t_nlist **st_a, t_nlist **st_b)
{
	int		steps_front;
	int		steps_back;
	t_nlist	*voyager;

	voyager = *st_a;
	steps_back = 0;
	steps_front = 0;
	while (voyager && voyager->nb > voyager->next->nb)
	{
		voyager = voyager->next;
		steps_back++;
	}
	while (voyager && (*st_b)->nb > voyager->nb)
	{
		voyager = voyager->next;
		steps_back++;
	}
	while (voyager != NULL)
	{
		voyager = voyager->next;
		steps_front++;
	}
	if (steps_back >= steps_front)
		return (1);
	return (0);
}

void	simple_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	(void)st_b;
	while ((*st_a)->next != NULL)
	{
		if (chunk_checker_max_strict(st_a, (*st_a)->nb) == 1)
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
		if (counting_steps(st_a, st_b) == 1)
			while ((*st_a)->nb != min_finder(st_a))
				ra(st_a, data, 1);
		else
			while ((*st_a)->nb > (*st_b)->nb)
			{
				if ((*st_b)->nb < (*st_a)->nb && min_finder(st_a) == (*st_a)->nb)
					break ;
				rra(st_a, data, 1);
			}
	}
	return ;
}
