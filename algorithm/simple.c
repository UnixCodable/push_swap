/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:17:05 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/07 11:22:01 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simple_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	(void)st_b;
	(*st_a)->chunk = -1;
	while (compute_disorder(*st_a, data) != 0.00)
	{
		while ((*st_a)->chunk == -1 && compute_disorder(*st_a, data) != 0.00)
			ra(st_a, data, 1);
		while ((*st_a)->next->chunk != -1)
		{
			ft_printf("test");
			sa(st_a, data, 1);
			ra(st_a, data, 1);
		}
		while ((*st_a)->nb > (*st_a)->next->nb && (*st_a)->next->chunk == -1)
		{
			sa(st_a, data, 1);
			ra(st_a, data, 1);
		}
		(*st_a)->chunk = -1;
	}
	return ;
}
