/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:10:37 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/14 15:42:09 by lbordana         ###   ########.fr       */
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
	while (voyager != NULL)
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
	while (voyager != NULL)
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

int	chunk_present(t_nlist **st_a, long int i)
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

int	chunk_checker_min_strict(t_nlist **stack, int actual_chunk, int min_value)
{
	t_nlist	*voyager;

	voyager = *stack;
	while (voyager)
	{
		if (voyager->nb < min_value && voyager->chunk == actual_chunk)
			return (0);
		voyager = voyager->next;
	}
	return (1);
}

int	chunk_checker_max_strict(t_nlist **st_b, int actual_chunk, int max_value)
{
	t_nlist	*voyager;

	voyager = *st_b;
	while (voyager)
	{
		if (voyager->nb > max_value && voyager->chunk == actual_chunk)
			return (0);
		voyager = voyager->next;
	}
	return (1);
}
