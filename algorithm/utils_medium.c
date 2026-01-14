/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_m.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:10:37 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/14 18:19:27 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	give_chunk(t_n **st_a, struct s_m *med)
{
	t_n	*voyager;

	voyager = (*st_a);
	while (med->l_max < med->max)
	{
		med->l_min = med->l_max + 1;
		med->l_max = med->l_min + med->l;
		med->chunk += 1;
		voyager = (*st_a);
		while (voyager)
		{
			if (voyager->nb >= med->l_min && voyager->nb <= med->l_max)
				voyager->chunk = med->chunk;
			voyager = voyager->next;
		}
	}
}

void	create_chunk(t_n **st_a, struct s_m *med)
{
	t_n	*voyager;

	voyager = (*st_a);
	med->l = (med->max - med->min + 1) / med->n_chunk;
	med->l_max = med->min + med->l;
	med->l_min = med->l_max - med->l;
	med->chunk = 1;
	while (voyager != NULL)
	{
		if (voyager->nb >= med->l_min && voyager->nb <= med->l_max)
			voyager->chunk = med->chunk;
		voyager = voyager->next;
	}
	give_chunk(st_a, med);
}

void	chunk(t_n **st_a, struct s_d *data, struct s_m *med)
{
	t_n	*voyager;

	voyager = (*st_a);
	med->min = (*st_a)->nb;
	med->max = (*st_a)->nb;
	while (voyager != NULL)
	{
		if (voyager->nb < med->min)
			med->min = voyager->nb;
		if (voyager->nb > med->max)
			med->max = voyager->nb;
		voyager = voyager->next;
	}
	while (med->n_chunk * med->n_chunk <= data->number_count)
	{
		if (med->n_chunk * med->n_chunk == data->number_count)
			break ;
		med->n_chunk += 1;
	}
	create_chunk(st_a, med);
}

int	chunk_present(t_n **st_a, long int i)
{
	t_n	*voyager;

	voyager = (*st_a);
	while (voyager != NULL)
	{
		if (voyager->chunk == i)
			return (1);
		voyager = voyager->next;
	}
	return (0);
}

int	chunk_checker_min_strict(t_n **stack, int actual_chunk, int min_value)
{
	t_n	*voyager;

	voyager = *stack;
	while (voyager)
	{
		if (voyager->nb < min_value && voyager->chunk == actual_chunk)
			return (0);
		voyager = voyager->next;
	}
	return (1);
}

int	chunk_checker_max_strict(t_n **st_b, int actual_chunk, int max_value)
{
	t_n	*voyager;

	voyager = *st_b;
	while (voyager)
	{
		if (voyager->nb > max_value && voyager->chunk == actual_chunk)
			return (0);
		voyager = voyager->next;
	}
	return (1);
}
