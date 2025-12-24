/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:25 by aeuvrard          #+#    #+#             */
/*   Updated: 2025/12/24 13:19:11 by lbordanave       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_nlist **st_a, struct s_data *data)
{
	t_nlist	*voyager;

	data->ra_count++;
	voyager = *st_a;
	while (voyager->next != NULL)
		voyager = voyager->next;
	(*st_a)->previous = voyager;
	(*st_a)->next->previous = NULL;
	(*st_a)->next = NULL;
	voyager->next = *st_a;
	while ((*st_a)->previous != NULL)
		(*st_a) = (*st_a)->previous;
}

void	rb(t_nlist **st_b, struct s_data *data)
{
	t_nlist	*voyager;

	data->rb_count++;
	voyager = *st_b;
	while (voyager->next != NULL)
		voyager = voyager->next;
	(*st_b)->previous = voyager;
	(*st_b)->next->previous = NULL;
	(*st_b)->next = NULL;
	voyager->next = *st_b;
	while ((*st_b)->previous != NULL)
		(*st_b) = (*st_b)->previous;
}

void	rr(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	data->rr_count++;
	ra(st_a, data);
	rb(st_b, data);
}
