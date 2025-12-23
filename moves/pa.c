/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:20 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/23 20:23:33 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_pa(t_num_list **stack_a, t_num_list **stack_b, struct s_data data)
{
	if ((*stack_b)->is_empty == 1)
		return ;
	if ((*stack_a))
	{
		(*stack_a)->previous = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->previous->next = (*stack_a);
		(*stack_b)->previous = NULL;
	}
	else
	{
		(*stack_b) = (*stack_b)->next;
		(*stack_a) = (*stack_b)->previous;
		(*stack_b)->previous = NULL;
		(*stack_a)->next = NULL;
	}
}
