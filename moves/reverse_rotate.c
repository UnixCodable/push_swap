/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:33 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/16 18:28:16 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_n **st_a, struct s_d *data, int to_print)
{
	t_n	*j;

	j = (*st_a);
	if (to_print == 1 && !data->low_disorder && !data->med_disorder && !data->checker)
	{
		ft_printf("rra\n");
		data->rra_count++;
		data->total_count++;
	}
	while (j->next != NULL)
		j = j->next;
	(*st_a)->previous = j;
	j->next = (*st_a);
	j->previous->next = NULL;
	j->previous = NULL;
	(*st_a) = (*st_a)->previous;
}

void	rrb(t_n **st_b, struct s_d *data, int to_print)
{
	t_n	*j;

	j = (*st_b);
	if (to_print == 1 && !data->low_disorder && !data->med_disorder && !data->checker)
	{
		ft_printf("rrb\n");
		data->rrb_count++;
		data->total_count++;
	}
	while (j->next != NULL)
		j = j->next;
	(*st_b)->previous = j;
	j->next = (*st_b);
	j->previous->next = NULL;
	j->previous = NULL;
	(*st_b) = (*st_b)->previous;
}

void	rrr(t_n **st_a, t_n **st_b, struct s_d *data)
{
	if (!data->low_disorder && !data->med_disorder && !data->checker)
	{
		data->rrr_count++;
		data->total_count++;
		ft_printf("rrr\n");
	}
	rra(st_a, data, 0);
	rrb(st_b, data, 0);
}
