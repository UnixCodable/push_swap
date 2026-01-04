/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:25 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/04 02:29:43 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_nlist **st_a, struct s_data *data, int to_print)
{
	t_nlist	*voyager;

	voyager = *st_a;
	if (to_print == 1)
	{
		ft_printf("ra\n");
		data->ra_count++;
		data->total_count++;
	}
	if (!(*st_a)->next)
		return ;
	while (voyager->next != NULL)
		voyager = voyager->next;
	(*st_a)->previous = voyager;
	(*st_a)->next->previous = NULL;
	(*st_a)->next = NULL;
	voyager->next = *st_a;
	while ((*st_a)->previous != NULL)
		(*st_a) = (*st_a)->previous;
}

void	rb(t_nlist **st_b, struct s_data *data, int to_print)
{
	t_nlist	*voyager;

	voyager = *st_b;
	if (to_print == 1)
	{
		ft_printf("rb\n");
		data->rb_count++;
		data->total_count++;
	}
	if (!(*st_b)->next)
		return ;
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
	data->total_count++;
	ft_printf("rr\n");
	ra(st_a, data, 0);
	rb(st_b, data, 0);
}
