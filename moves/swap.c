/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:13:41 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/04 02:29:55 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_nlist **st_a, struct s_data *data, int to_print)
{
	int	pos;

	if (to_print == 1)
	{
		ft_printf("sa\n");
		data->sa_count++;
		data->total_count++;
	}
	if (!(*st_a) || !(*st_a)->next)
		return ;
	pos = (*st_a)->pos;
	(*st_a)->pos = (*st_a)->next->pos;
	(*st_a)->next->pos = pos;
	if ((*st_a)->next->next)
		(*st_a)->next->next->previous = (*st_a);
	(*st_a)->previous = (*st_a)->next;
	(*st_a)->next = (*st_a)->next->next;
	(*st_a)->previous->previous = NULL;
	(*st_a)->previous->next = (*st_a);
	(*st_a) = (*st_a)->previous;
}

void	sb(t_nlist **st_b, struct s_data *data, int to_print)
{
	int	pos;

	if (to_print == 1)
	{
		ft_printf("sb\n");
		data->sa_count++;
		data->total_count++;
	}
	if (!(*st_b) || !(*st_b)->next)
		return ;
	pos = (*st_b)->pos;
	(*st_b)->pos = (*st_b)->next->pos;
	(*st_b)->next->pos = pos;
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
	data->total_count++;
	ft_printf("ss\n");
	sa(st_a, data, 0);
	sb(st_b, data, 0);
}
