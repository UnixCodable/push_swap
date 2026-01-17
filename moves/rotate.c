/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:25 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/17 16:17:31 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_n **st_a, struct s_d *data, int to_print)
{
	t_n	*j;

	j = *st_a;
	if (to_print == 1 && !data->low_disorder && !data->med_disorder && !data->checker)
	{
		ft_printf("ra\n");
		data->ra_count++;
		data->total_count++;
	}
	if (!(*st_a) || !(*st_a)->next)
		return ;
	while (j->next != NULL)
		j = j->next;
	(*st_a)->previous = j;
	(*st_a)->next->previous = NULL;
	(*st_a)->next = NULL;
	j->next = *st_a;
	while ((*st_a)->previous != NULL)
		(*st_a) = (*st_a)->previous;
}

void	rb(t_n **st_b, struct s_d *data, int to_print)
{
	t_n	*j;

	j = *st_b;
	if (to_print == 1 && !data->low_disorder && !data->med_disorder && !data->checker)
	{
		ft_printf("rb\n");
		data->rb_count++;
		data->total_count++;
	}
	if (!(*st_b) || !(*st_b)->next)
		return ;
	while (j->next != NULL)
		j = j->next;
	(*st_b)->previous = j;
	(*st_b)->next->previous = NULL;
	(*st_b)->next = NULL;
	j->next = *st_b;
	while ((*st_b)->previous != NULL)
		(*st_b) = (*st_b)->previous;
}

void	rr(t_n **st_a, t_n **st_b, struct s_d *data)
{
	if (!data->low_disorder && !data->med_disorder && !data->checker)
	{
		data->rr_count++;
		data->total_count++;
		ft_printf("rr\n");
	}
	ra(st_a, data, 0);
	rb(st_b, data, 0);
}

// N =
