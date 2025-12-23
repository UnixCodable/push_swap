/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:20 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/24 00:48:52 by agathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_pa(t_num_list **stack_a, t_num_list **stack_b, struct s_data *data)
{
	data->pa_count++;
	if (!(*stack_b))
		return ;
	if ((*stack_a))
	{
		(*stack_a)->previous = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		if ((*stack_b))
			(*stack_b)->previous = NULL;
		(*stack_a)->previous->next = (*stack_a);
		(*stack_a) = (*stack_a)->previous;
	}
	else
	{
		(*stack_b) = (*stack_b)->next;
		(*stack_a) = (*stack_b)->previous;
		(*stack_b)->previous = NULL;
		(*stack_a)->next = NULL;
	}
}
