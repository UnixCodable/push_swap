/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:43 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/24 00:49:38 by agathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_sb(t_num_list **stack_b, struct s_data *data)
{
	data->sb_count++;
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	(*stack_b)->previous = (*stack_b)->next;
	(*stack_b)->next = (*stack_b)->next->next;
	(*stack_b)->previous->previous = NULL;
	(*stack_b)->previous->next = (*stack_b);
	(*stack_b) = (*stack_b)->previous;
}
