/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:22 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/23 21:35:01 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_pb(t_num_list **stack_a, t_num_list **stack_b, struct s_data *data)
{
	data->pb_count++;
	if (!(*stack_a))
		return ;
	if ((*stack_b))
	{
		(*stack_b)->previous = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		if ((*stack_a))
			(*stack_a)->previous = NULL;
		(*stack_b)->previous->next = (*stack_b);
		(*stack_b) = (*stack_b)->previous;
	}
	else
	{
		(*stack_a) = (*stack_a)->next;
		(*stack_b) = (*stack_a)->previous;
		(*stack_a)->previous = NULL;
		(*stack_b)->next = NULL;
	}
}
