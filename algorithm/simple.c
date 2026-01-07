/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:17:05 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/06 23:01:12 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simple_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	(void)st_b;
	while (compute_disorder(*st_a, data) != 0.00)
	{
		if ((*st_a)->nb > (*st_a)->next->nb
			&& (*st_a)->pos < (*st_a)->next->pos)
		{
			sa(st_a, data, 1);
			ra(st_a, data, 1);
		}
		else
		{
			ra(st_a, data, 1);
		}
	}
	return ;
}
