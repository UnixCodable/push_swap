/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 19:08:28 by agathe            #+#    #+#             */
/*   Updated: 2025/12/23 20:43:52 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_ss(t_num_list **stack_a, t_num_list **stack_b, struct s_data *data)
{
	move_sa(stack_a, data);
	move_sb(stack_b, data);
}
