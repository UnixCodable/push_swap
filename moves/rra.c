/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:33 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/24 01:08:44 by agathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		move_rra(t_num_list **stack_a, struct s_data *data)
{
    t_num_list  *voyager;
    
    data->rra_count++;
    voyager = (*stack_a);
    while (voyager->next != NULL)
        voyager = voyager->next;
    (*stack_a)->previous = voyager;
    voyager->next = (*stack_a);
    voyager->previous->next = NULL;
    voyager->previous = NULL;
    (*stack_a) = (*stack_a)->previous;
}
