/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:12 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/24 01:12:39 by agathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void   		move_rrr(t_num_list **stack_a, t_num_list **stack_b, struct s_data *data)
{
    data->rrr_count++;
    move_rra(stack_a, data);
    move_rrb(stack_b, data);
}