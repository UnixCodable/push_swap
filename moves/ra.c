/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:25 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/24 00:59:13 by agathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_ra(t_num_list **stack_a, struct s_data *data)
{
	t_num_list	*voyager;

	data->ra_count++;
	voyager = *stack_a;
	while (voyager->next != NULL)
		voyager = voyager->next;
	(*stack_a)->previous = voyager;
	(*stack_a)->next->previous = NULL;
	(*stack_a)->next = NULL;
	voyager->next = *stack_a;
	while ((*stack_a)->previous != NULL)
		(*stack_a) = (*stack_a)->previous;
}
