/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:41 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/24 00:49:24 by agathe           ###   ########.fr       */
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

// void	move_sa(t_num_list *stack_a)
// {
// 	int	save_nbr;

// 	if (stack_a->is_empty == 1 || stack_a->next->is_empty == 1)
// 		return ;
// 	save_nbr = stack_a->next->nb;
// 	stack_a->next->nb = stack_a->nb;
// 	stack_a->nb = save_nbr;
// 	return ;
// }