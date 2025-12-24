/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:31 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/24 01:02:28 by agathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    move_rr(t_num_list **stack_a, t_num_list **stack_b, struct s_data *data)
{
    data->rr_count++;
    move_ra(stack_a, data);
    move_rb(stack_b, data);
}