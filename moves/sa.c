/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:41 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/22 15:46:43 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*move_sa(t_num_list *stack_a)
{
	int	save_nbr;

	if (stack_a == NULL || stack_a->next == NULL)
		return ;
	save_nbr = stack_a->next->nb;
	stack_a->next->nb = stack_a->nb;
	stack_a->nb = save_nbr;
	printf("%d/n", stack_a->nb);
	printf("%d/n", stack_a->next->nb);
	return ;
}

