/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:37:24 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/11 18:41:06 by aeuvrard         ###   ########.fr       */
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
		while (voyager->next != NULL)
		{
			if (voyager->nb >= medium->l_min && voyager->nb <= medium->l_max)
				voyager->chunk = medium->chunk;
			voyager = voyager->next;
		}
		voyager->chunk = medium->chunk;
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

int	impaire_chunk(t_nlist **st_a, t_nlist **st_b, int i)
{
	t_nlist	*voyager;

	voyager = (*st_a);
	if (i == 1)
	{
		while (voyager->next != NULL)
		{
			ft_printf("LA\n");
			if (voyager->chunk % 2 != 0)
				return (1);
			voyager = voyager->next;
		}
	}
	else
	{
		while (voyager)
		{
			if (voyager->chunk == (*st_b)->chunk)
				return (1);
			voyager = voyager->next;
		}
	}
	return (0);
}

int	best_path_a(t_nlist **st_a)
{
	int		voyager_front;
	int		voyager_back;
	t_nlist	*voyager;

	voyager = (*st_a);
	voyager_front = 0;
	voyager_back = 0;
	while (voyager->chunk % 2 == 0)
	{
		voyager_front++;
		voyager = voyager->next;
	}
	while (voyager->next != NULL)
		voyager = voyager->next;
	while (voyager->chunk % 2 == 0)
	{
		voyager = voyager->previous;
		voyager_back++;
	}
	if (voyager_front < voyager_back)
		return (1);
	return (0);
}
int	best_path_b(t_nlist **st_a, t_nlist **st_b)
{
	int		voyager_front;
	int		voyager_back;
	t_nlist	*voyager;

	voyager = (*st_b);
	voyager_front = 0;
	voyager_back = 0;
	while (voyager-> chunk != (*st_a)->chunk)
	{
		voyager_front++;
		voyager = voyager->next;
	}
	while (voyager->next != NULL)
		voyager = voyager->next;
	while (voyager-> chunk != (*st_a)->chunk)
	{
		voyager = voyager->previous;
		voyager_back++;
	}
	if (voyager_front < voyager_back)
		return (1);
	return (0);
}

void	push_impaire(t_nlist **st_a, t_nlist **st_b, struct s_data *data,
			struct s_medium *medium)
{
	(void) medium;
	/*s'il n'y a rien dans B*/
	if (!(*st_b))
		pb(st_a, st_b, data);
	/*S'il n'y a qu'un seul nb dans B*/
	if ((*st_b)->next == NULL)
		pb(st_a, st_b, data);
	/*s'il y un chunk dans B qui correspond au chunk de A*/
	if (impaire_chunk(st_a, st_b, 2) == 1)
	{
		// if (best_path_b(st_a, st_b) == 1)
		// 	while ((*st_a)->chunk != (*st_b)->chunk)
		// 		rb(st_b, data, 1);
		// else
		// 	while ((*st_a)->chunk != (*st_b)->chunk)
		// 		rrb(st_b, data, 1);
		pb(st_a, st_b, data);
	}
}

void	organize_chunk(t_nlist **st_a, t_nlist **st_b, struct s_data *data,
			struct s_medium *medium)
{
	(void) medium;
	(void) data;
	(void) (*st_b);
	 /* tant qu'il y a des chunks impaires dans A*/
	while (impaire_chunk(st_a, st_b, 1) == 1)
	{
		/*Tant le chunk de A est paire*/
		while ((*st_a)->chunk % 2 == 0)
		{
			/*le prochain avec un chunk impaire est plus proche par front*/
			if (best_path_a(st_a) == 1)
				ra(st_a, data, 1);
			else
				rra(st_a, data, 1);
		}
		printf("ICI\n");
		push_impaire(st_a, st_b, data, medium);
	}
}



void	medium_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data,
			struct s_medium *medium)
{
	(void) (*st_b);
	chunk(st_a, data, medium);
	organize_chunk(st_a, st_b, data, medium);
	ft_printf("\n");
	while ((*st_a)->next != NULL)
	{
		ft_printf("%d  -> ", (*st_a)->nb);
		ft_printf("chunk = %d\n", (*st_a)->chunk);
		(*st_a) = (*st_a)->next;
	}
	ft_printf("%d  -> ", (*st_a)->nb);
	ft_printf("chunk = %d\n\n", (*st_a)->chunk);
	while ((*st_b)->next != NULL)
	{
		ft_printf("%d  -> ", (*st_b)->nb);
		ft_printf("chunk = %d\n", (*st_b)->chunk);
		(*st_b) = (*st_b)->next;
	}
	ft_printf("%d  -> ", (*st_b)->nb);
	ft_printf("chunk = %d\n\n", (*st_b)->chunk);
}
