/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:28 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/24 01:55:35 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_rb(t_num_list **stack_b, struct s_data *data)
{
	t_num_list	*voyager;

	data->rb_count++;
	voyager = *stack_b;
	while (voyager->next != NULL)
		voyager = voyager->next;
	(*stack_b)->previous = voyager;
	(*stack_b)->next->previous = NULL;
	(*stack_b)->next = NULL;
	voyager->next = *stack_b;
	while ((*stack_b)->previous != NULL)
		(*stack_b) = (*stack_b)->previous;
}