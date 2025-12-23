/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:41 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/23 12:30:24 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_sa(t_num_list **stack_a)
{
	if ((*stack_a)->is_empty == 1 || (*stack_a)->next->is_empty == 1)
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