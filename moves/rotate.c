/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:25 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/14 18:22:22 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_n **st_a, struct s_d *data, int to_print)
{
	t_n	*voyager;

	voyager = *st_a;
	if (to_print == 1 && !data->low_disorder && !data->med_disorder)
	{
		ft_printf("ra\n");
		data->ra_count++;
		data->total_count++;
	}
	if (!(*st_a)->next)
		return ;
	while (voyager->next != NULL)
		voyager = voyager->next;
	(*st_a)->previous = voyager;
	(*st_a)->next->previous = NULL;
	(*st_a)->next = NULL;
	voyager->next = *st_a;
	while ((*st_a)->previous != NULL)
		(*st_a) = (*st_a)->previous;
}

void	rb(t_n **st_b, struct s_d *data, int to_print)
{
	t_n	*voyager;

	voyager = *st_b;
	if (to_print == 1 && !data->low_disorder && !data->med_disorder)
	{
		ft_printf("rb\n");
		data->rb_count++;
		data->total_count++;
	}
	if (!(*st_b)->next)
		return ;
	while (voyager->next != NULL)
		voyager = voyager->next;
	(*st_b)->previous = voyager;
	(*st_b)->next->previous = NULL;
	(*st_b)->next = NULL;
	voyager->next = *st_b;
	while ((*st_b)->previous != NULL)
		(*st_b) = (*st_b)->previous;
}

void	rr(t_n **st_a, t_n **st_b, struct s_d *data)
{
	if (!data->low_disorder && !data->med_disorder)
	{
		data->rr_count++;
		data->total_count++;
		ft_printf("rr\n");
	}
	ra(st_a, data, 0);
	rb(st_b, data, 0);
}

// N =
