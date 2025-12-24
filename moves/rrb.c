/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:36 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/24 01:09:49 by agathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		move_rrb(t_num_list **stack_b, struct s_data *data)
{
    t_num_list  *voyager;
    
    data->rrb_count++;
    voyager = (*stack_b);
    while (voyager->next != NULL)
        voyager = voyager->next;
    (*stack_b)->previous = voyager;
    voyager->next = (*stack_b);
    voyager->previous->next = NULL;
    voyager->previous = NULL;
    (*stack_b) = (*stack_b)->previous;
}