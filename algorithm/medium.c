/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:37:24 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/13 13:27:38 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	give_chunk(t_nlist **st_a, struct s_medium *medium)
{
	t_nlist	*voyager;

	voyager = (*st_a);
	while (medium->l_max < medium->max)
	{
		medium->l_min = medium->l_max + 1;
		medium->l_max = medium->l_min + medium->l;
		medium->chunk += 1;
		// ft_printf("Lmin = %d\n", medium->l_min);
		// ft_printf("Lmax = %d\n\n", medium->l_max);
		voyager = (*st_a);
		while (voyager)
		{
			if (voyager->nb >= medium->l_min && voyager->nb <= medium->l_max)
				voyager->chunk = medium->chunk;
			voyager = voyager->next;
		}
	}
}

void	create_chunk(t_nlist **st_a, struct s_medium *medium)
{
	t_nlist	*voyager;

	voyager = (*st_a);
	medium->l = (medium->max - medium->min + 1) / medium->n_chunk;
	medium->l_max = medium->min + medium->l;
	medium->l_min = medium->l_max - medium->l;
	medium->chunk = 1;
	// ft_printf("Lmin = %d\n", medium->l_min);
	// ft_printf("Lmax = %d\n\n", medium->l_max);
	while (voyager->next != NULL)
	{
		if (voyager->nb >= medium->l_min && voyager->nb <= medium->l_max)
			voyager->chunk = medium->chunk;
		voyager = voyager->next;
	}
	give_chunk(st_a, medium);
}

void	chunk(t_nlist **st_a, struct s_data *data, struct s_medium *medium)
{
	t_nlist	*voyager;

	voyager = (*st_a);
	medium->min = (*st_a)->nb;
	medium->max = (*st_a)->nb;
	while (voyager->next != NULL)
	{
		if (voyager->nb < medium->min)
			medium->min = voyager->nb;
		if (voyager->nb > medium->max)
			medium->max = voyager->nb;
		voyager = voyager->next;
	}
	while (medium->n_chunk * medium->n_chunk <= data->number_count)
	{
		if (medium->n_chunk * medium->n_chunk == data->number_count)
			break ;
		medium->n_chunk += 1;
	}
	create_chunk(st_a, medium);
}

int	chunk_present(t_nlist **st_a, int i)
{
	t_nlist	*voyager;

	voyager = (*st_a);
	while (voyager != NULL)
	{
		if (voyager->chunk == i)
			return (1);
		voyager = voyager->next;
	}
	return (0);
}

void	organize_chunk(t_nlist **st_a, t_nlist **st_b, struct s_data *data,
			struct s_medium *medium)
{
	int		i;
	t_nlist *voyager;

	(void) (*st_a);
	(void) (*st_b);
	(void) data;
	(void) medium;
	i = 1;
	while ((*st_a) != NULL)
	{
		/*Tant qu'il y a un chunk = i*/
		while (chunk_present(st_a, i) == 1 || chunk_present(st_a, i + 1) == 1)
		{
			if ((*st_a)->chunk == i)
				pb(st_a, st_b, data);
			else if ((*st_a)->chunk == (i + 1))
			{
				pb(st_a, st_b, data);
				if (chunk_present(st_a, i) == 1)
				{
					if (!(*st_a) || (*st_a)->chunk == i || (*st_a)->chunk == i + 1)
						rb(st_b, data, 1);
					else
						rr(st_a, st_b, data);
				}
			}
			else
				ra(st_a, data, 1);
		}
		voyager = *st_b;
		while (voyager && voyager->chunk != i)
			voyager = voyager->next;
		while (voyager && voyager->chunk != i + 1)
			voyager = voyager->next;
		if (voyager == NULL)
			break ;
		while ((*st_b)->nb != voyager->nb)
			rrb(st_b, data, 1);
		i += 2;
	}
}

void	simple_alg_chunk(t_nlist **st_a, t_nlist **st_b, struct s_data *data, int i)
{
	t_nlist *voyager;

	while ((*st_b) && (*st_b)->next != NULL && (*st_b)->chunk == i)
	{
		if (chunk_checker_min_strict(st_b, i, (*st_b)->nb) == 1)
			rb(st_b, data, 1);
		else
			pa(st_a, st_b, data);
	}
	if ((*st_b)->next)
		rrb(st_b, data, 1);
	voyager = *st_b;
	while (voyager->next != NULL)
		voyager = voyager->next;
	while (((*st_a) && (*st_a)->chunk == (*st_b)->chunk) || ((*st_a) && (*st_a)->chunk != -1))
	{
		while ((*st_b)->nb > (*st_a)->nb)
			rb(st_b, data, 1);
		pb(st_a, st_b, data);
		if ((*st_a) && (*st_a)->nb < (*st_b)->nb)
			continue ;
		while ((*st_a) && (*st_b) && (*st_b)->nb < (*st_a)->nb && voyager->next != NULL)
			rrb(st_b, data, 1);
	}
	while (chunk_checker_max_strict(st_b, i, (*st_b)->chunk) != 1 && voyager->next != NULL)
		rrb(st_b, data, 1);
	while ((*st_b) && (*st_b)->chunk == i)
	{
		(*st_b)->chunk = -1;
		pa(st_a, st_b, data);
	}
	if (i > 1)
		simple_alg_chunk(st_a, st_b, data, --i);
	return ;
}

void	medium_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data,
			struct s_medium *medium)
{
	(void) (*st_b);
	chunk(st_a, data, medium);
	organize_chunk(st_a, st_b, data, medium);
	simple_alg_chunk(st_a, st_b, data, medium->n_chunk);
}
