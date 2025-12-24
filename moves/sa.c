/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:41 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/24 01:13:28 by agathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_sa(t_num_list **stack_a, struct s_data *data)
{
	data->sa_count++;
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	(*stack_a)->previous = (*stack_a)->next;
	(*stack_a)->next = (*stack_a)->next->next;
	(*stack_a)->previous->previous = NULL;
	(*stack_a)->previous->next = (*stack_a);
	(*stack_a) = (*stack_a)->previous;
}
