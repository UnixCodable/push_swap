/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:41 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/24 05:32:25 by lbordanave       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_nlist **st_a, struct s_data *data)
{
	data->sa_count++;
	if (!(*st_a) || !(*st_a)->next)
		return ;
	if ((*st_a)->next->next)
		(*st_a)->next->next->previous = (*st_a);
	(*st_a)->previous = (*st_a)->next;
	(*st_a)->next = (*st_a)->next->next;
	(*st_a)->previous->previous = NULL;
	(*st_a)->previous->next = (*st_a);
	(*st_a) = (*st_a)->previous;
}

void	sb(t_nlist **st_b, struct s_data *data)
{
	data->sb_count++;
	if (!(*st_b) || !(*st_b)->next)
		return ;
	if ((*st_b)->next->next)
		(*st_b)->next->next->previous = (*st_b);
	(*st_b)->previous = (*st_b)->next;
	(*st_b)->next = (*st_b)->next->next;
	(*st_b)->previous->previous = NULL;
	(*st_b)->previous->next = (*st_b);
	(*st_b) = (*st_b)->previous;
}

void	ss(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	data->ss_count++;
	sa(st_a, data);
	sb(st_b, data);
}
