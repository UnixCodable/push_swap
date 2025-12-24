/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:17:05 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/24 06:04:04 by lbordanave       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simple_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	int	i;

	i = 0;
	(void)st_b;
	while (compute_disorder(*st_a, data) != 0.00 && i != 9999)
	{
		if ((*st_a)->nb > (*st_a)->next->nb)
		{
			sa(st_a, data);
			ra(st_a, data);
			data->total_count += 2;
		}
		else
		{
			ra(st_a, data);
			data->total_count += 1;
		}
		i++;
	}
	return ;
}
