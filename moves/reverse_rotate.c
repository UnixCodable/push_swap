/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:33 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/14 18:22:22 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_n **st_a, struct s_d *data, int to_print)
{
	t_n	*voyager;

	voyager = (*st_a);
	if (to_print == 1 && !data->low_disorder && !data->med_disorder)
	{
		ft_printf("rra\n");
		data->rra_count++;
		data->total_count++;
	}
	while (voyager->next != NULL)
		voyager = voyager->next;
	(*st_a)->previous = voyager;
	voyager->next = (*st_a);
	voyager->previous->next = NULL;
	voyager->previous = NULL;
	(*st_a) = (*st_a)->previous;
}

void	rrb(t_n **st_b, struct s_d *data, int to_print)
{
	t_n	*voyager;

	voyager = (*st_b);
	if (to_print == 1 && !data->low_disorder && !data->med_disorder)
	{
		ft_printf("rrb\n");
		data->rrb_count++;
		data->total_count++;
	}
	while (voyager->next != NULL)
		voyager = voyager->next;
	(*st_b)->previous = voyager;
	voyager->next = (*st_b);
	voyager->previous->next = NULL;
	voyager->previous = NULL;
	(*st_b) = (*st_b)->previous;
}

void	rrr(t_n **st_a, t_n **st_b, struct s_d *data)
{
	if (!data->low_disorder && !data->med_disorder)
	{
		data->rrr_count++;
		data->total_count++;
		ft_printf("rrr\n");
	}
	rra(st_a, data, 0);
	rrb(st_b, data, 0);
}
