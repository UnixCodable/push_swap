/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:17:40 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/09 17:57:40 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	counting_steps_medium(t_nlist **st_a, t_nlist **st_b)
{
	int		steps_front;
	int		steps_back;
	t_nlist	*voyager;

	voyager = *st_a;
	steps_back = 0;
	steps_front = 0;
	while (voyager && voyager->nb > voyager->next->nb)
	{
		voyager = voyager->next;
		steps_back++;
	}
	while (voyager && (*st_b)->nb > voyager->nb)
	{
		voyager = voyager->next;
		steps_back++;
	}
	while (voyager != NULL)
	{
		voyager = voyager->next;
		steps_front++;
	}
	if (steps_back >= steps_front)
		return (1);
	return (0);
}

void	simple_alg_chunk(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	while ((*st_b) && (*st_b)->next != NULL)
	{
		if (chunk_checker_min_strict(st_b, (*st_b)->nb) == 1)
			rb(st_b, data, 1);
		else
			pa(st_a, st_b, data);
	}
	while ((*st_a)->chunk == (*st_b)->chunk)
	{
		while ((*st_b)->nb > (*st_a)->nb)
			rb(st_b, data, 1);
		pb(st_a, st_b, data);
		if ((*st_a) && (*st_a)->nb < (*st_b)->nb)
			continue ;
		while (!(chunk_checker_max_strict(st_b, (*st_b)->nb)))
			rb(st_b, data, 1);
	}
	while (compute_disorder(*st_b, data) != 1)
	{
		if (!(*st_b)->next)
			break ;
		rb(st_b, data, 1);
		//ft_printf("Disorder = %d", (int)(compute_disorder(*st_b, data) * 1000));
	}
		// if (counting_steps_medium(st_b, st_a) == 1)
		// {
		// 	while ((*st_b)->nb != min_finder(st_b))
		// 		rb(st_b, data, 1);
		// }
		// else
		// while ((*st_b)->nb > (*st_a)->nb && (*st_b)->chunk == (*st_a)->chunk)
		// {
		// 	if ((*st_a)->chunk != (*st_b)->chunk)
		// 		break ;
		// 	rrb(st_b, data, 1);
		// }
	return ;
}

int	counting_best_path(t_nlist **st_a, struct s_medium *medium)
{
	int		voyager_front;
	int		voyager_back;
	t_nlist	*voyager;

	voyager = (*st_a);
	voyager_front = 0;
	voyager_back = 0;
	while (voyager->next != NULL)
	{
		if (!(voyager-> nb >= medium->l_min && voyager-> nb <= medium->l_max))
			voyager_front++;
		voyager = voyager->next;
	}
	while (!(voyager-> nb >= medium->l_min && voyager-> nb <= medium->l_max))
	{
		voyager = voyager->previous;
		voyager_back++;
	}
	voyager_front -= voyager_back;
	if (voyager_front > voyager_back)
		return (1);
	return (0);
}
int	interval_checker(t_nlist **st_a, struct s_medium *medium)
{
	t_nlist	*voyager;

	voyager = (*st_a);
	while (voyager)
	{
		if (voyager->nb >= medium->l_min && voyager->nb <= medium->l_max)
			return (1);
		voyager = voyager->next;
	}
	return (0);
}
void	limit_chunk(struct s_medium *medium)
{
	if (medium->p == 0)
	{
		medium->l = (medium->max - medium->min + 1) / medium->n_chunk;
		medium->l_max = medium->min + medium->l;
		medium->l_min = medium->l_max - medium->l;
		// ft_printf("L = %d\n", medium->l);
		ft_printf("L_min = %d\n", medium->l_min);
		ft_printf("L_max = %d\n\n", medium->l_max);
		while (medium->l_max < medium->max)
		{
			medium->l_min = medium->l_max + 1;
			medium->l_max = medium->l_min + medium->l;
			ft_printf("L_min = %d\n", medium->l_min);
			ft_printf("L_max = %d\n\n", medium->l_max);
		}
		medium->p = 1;
		medium->chunk = 1;
	}
	else
	{
		medium->l_max = medium->l_min - 1;
		medium->l_min = medium->l_max - medium->l;
		medium->chunk += 1;
		// // ft_printf("L_min = %d\n", medium->l_min);
		// // ft_printf("L_max = %d\n\n", medium->l_max);
	}
	return ;
}

void	number_chunk(struct s_data *data, struct s_medium *medium)
{
	while (medium->n_chunk * medium->n_chunk <= data->number_count)
	{
		if (medium->n_chunk * medium->n_chunk == data->number_count)
			break ;
		medium->n_chunk += 1;
	}
}

void	calcul_min_max(t_nlist *st_a, struct s_medium *medium)
{
	medium->min = st_a->nb;
	medium->max = st_a->nb;
	while (st_a)
	{
		if (st_a->nb < medium->min)
			medium->min = st_a->nb;
		if (st_a->nb > medium->max)
			medium->max = st_a->nb;
		st_a = st_a->next;
	}
}

void	medium_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data, struct s_medium *medium)
{
	// ft_printf("P = %d\n", medium->p);
	if (medium->p == 0)
	{
		calcul_min_max(*st_a, medium);
		number_chunk(data, medium);
		// ft_printf("Nombre chunks = %d\n", medium->n_chunk);
		// ft_printf("min = %d\n", medium->min);
		// ft_printf("max = %d\n", medium->max);
	}
	limit_chunk(medium);
	if (medium->l_min < medium->min)
		return ;
	while (interval_checker(st_a, medium) == 1)
	{
		if ((*st_a)->nb >= medium->l_min && (*st_a)->nb <= medium->l_max)
		{
			// printf("nb = %d\n", (*st_a)->nb);
			(*st_a)->chunk = medium->chunk;
			// printf("chunk = %d\n", (*st_a)->chunk);
			pb(st_a, st_b, data);
		}
		else
		{
			if (counting_best_path(st_a, medium) == 1)
				while (!((*st_a)->nb >= medium->l_min && (*st_a)->nb <= medium->l_max))
					ra(st_a, data, 1);
			else
				while (!((*st_a)->nb >= medium->l_min && (*st_a)->nb <= medium->l_max))
					rra(st_a, data, 1);
		}
	}
	while ((*st_b)->next && compute_disorder((*st_b), data) != 1)
		simple_alg_chunk(st_a, st_b, data);
	while ((*st_b))
	{
		(*st_b)->chunk = -1;
		pa(st_a, st_b, data);
	}
	// ft_printf("P = %d\n", medium->p);
	if (compute_disorder((*st_a), data) != 0)
		medium_alg(st_a, st_b, data, medium);
	// while ((*st_a))
	// {
	// 	ft_printf("%d-", (*st_a)->nb);
	// 	(*st_a) = (*st_a)->next;
	// }
	// ft_printf("\n");
	// ft_printf("Nombre de couts : %d\n", data->total_count);
	return ;
}
