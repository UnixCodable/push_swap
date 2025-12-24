/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:33 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/24 04:05:09 by lbordanave       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_nlist **st_a, struct s_data *data)
{
	t_nlist	*voyager;

	data->rra_count++;
	voyager = (*st_a);
	while (voyager->next != NULL)
		voyager = voyager->next;
	(*st_a)->previous = voyager;
	voyager->next = (*st_a);
	voyager->previous->next = NULL;
	voyager->previous = NULL;
	(*st_a) = (*st_a)->previous;
}

void	rrb(t_nlist **st_b, struct s_data *data)
{
	t_nlist	*voyager;

	data->rrb_count++;
	voyager = (*st_b);
	while (voyager->next != NULL)
		voyager = voyager->next;
	(*st_b)->previous = voyager;
	voyager->next = (*st_b);
	voyager->previous->next = NULL;
	voyager->previous = NULL;
	(*st_b) = (*st_b)->previous;
}

void	rrr(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	data->rrr_count++;
	rra(st_a, data);
	rrb(st_b, data);
}
