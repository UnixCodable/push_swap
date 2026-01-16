/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:20 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/16 18:27:42 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_n **st_a, t_n **st_b, struct s_d *data)
{
	if (!data->low_disorder && !data->med_disorder && !data->checker)
	{
		data->pa_count++;
		data->total_count++;
		ft_printf("pa\n");
	}
	if (!(*st_b))
		return ;
	if ((*st_a))
	{
		(*st_a)->previous = (*st_b);
		(*st_b) = (*st_b)->next;
		if ((*st_b))
			(*st_b)->previous = NULL;
		(*st_a)->previous->next = (*st_a);
		(*st_a) = (*st_a)->previous;
	}
	else
	{
		(*st_b) = (*st_b)->next;
		(*st_a) = (*st_b)->previous;
		(*st_b)->previous = NULL;
		(*st_a)->next = NULL;
	}
}

void	pb(t_n **st_a, t_n **st_b, struct s_d *data)
{
	if (!data->low_disorder && !data->med_disorder && !data->checker)
	{
		data->pb_count++;
		data->total_count++;
		ft_printf("pb\n");
	}
	if (!(*st_a))
		return ;
	if ((*st_b))
	{
		(*st_b)->previous = (*st_a);
		(*st_a) = (*st_a)->next;
		if ((*st_a))
			(*st_a)->previous = NULL;
		(*st_b)->previous->next = (*st_b);
		(*st_b) = (*st_b)->previous;
	}
	else
	{
		(*st_a) = (*st_a)->next;
		(*st_b) = (*st_a)->previous;
		(*st_a)->previous = NULL;
		(*st_b)->next = NULL;
	}
}
