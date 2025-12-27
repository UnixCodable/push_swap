/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:20 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/27 00:15:41 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	data->pa_count++;
	ft_printf("pa\n");
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

void	pb(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	data->pb_count++;
	ft_printf("pb\n");
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
