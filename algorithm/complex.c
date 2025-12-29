/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:18:01 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/29 02:31:37 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	chunk_disorder(t_nlist *st_a, struct s_data *data, int chunk)
{
	double	mistakes;
	double	total_pairs;

	mistakes = 0.00;
	total_pairs = 0.00;
	while (st_a->next)
	{
		if (st_a->chunk == chunk && st_a->next->chunk == chunk)
		{
			total_pairs += 1;
			if (st_a->nb > st_a->next->nb)
				mistakes += 1;
		}
		st_a = st_a->next;
	}
	return (mistakes / total_pairs);
}

void	complex_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	static int	pivot;

	while ((*st_a))
	{
		rra(st_a, data, 1);
		pivot = (*st_a)->nb;
		while ((*st_a)->stop != 1)
		{
			(*st_a)->stop = 1;
			if ((*st_a)->nb >= pivot)
				pb(st_a, st_b, data);
			rra(st_a, data, 1);
		}
	}
}
