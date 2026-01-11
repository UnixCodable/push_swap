/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:44:01 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/11 20:39:17 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

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

int	impaire_chunk(t_nlist **st_a, t_nlist **st_b, int i)
{
	t_nlist	*voyager;

	if (i == 1)
	{
		voyager = (*st_a);
		while (voyager->next != NULL)
		{
			if (voyager->chunk % 2 != 0)
				return (1);
			voyager = voyager->next;
		}
	}
	if (i == 2)
	{
		voyager = (*st_b);
		while (voyager)
		{
			if (voyager->chunk == (*st_a)->chunk)
				return (1);
			voyager = voyager->next;
		}
	}
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

void	push_impaire(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	/*s'il n'y a rien dans B ou qu'il n'y a qu'un seul nb dans b*/
	if (!(*st_b) || ((*st_b)->next == NULL && (*st_a)->chunk % 2 != 0))
		pb(st_a, st_b, data);
	/*chunk de A est impaire */
	while ((*st_a)->chunk % 2 != 0)
	{
		/*s'il y un chunk dans B qui correspond au chunk de A*/
		if (impaire_chunk(st_a, st_b, 2) == 1)
		{
			if (best_path_b(st_a, st_b) == 1)
				while ((*st_a)->chunk != (*st_b)->chunk)
					rb(st_b, data, 1);
			else
				while ((*st_a)->chunk != (*st_b)->chunk)
					rrb(st_b, data, 1);
		}
		pb(st_a, st_b, data);
	}
}

void	place_chunk(t_nlist **st_b)
{
	
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
		push_impaire(st_a, st_b, data);
		place_chunk(st_b);
	}
}

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

void	medium_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data,
			struct s_medium *medium)
{
	t_nlist	*voyager;


	(void) (*st_b);
	chunk(st_a, data, medium);
	voyager = (*st_a);
	ft_printf("Stack A\n");
	while (voyager != NULL)
	{
		ft_printf("%d  -> ", voyager->nb);
		ft_printf("chunk = %d\n", voyager->chunk);
		voyager = voyager->next;
	}
	organize_chunk(st_a, st_b, data, medium);
	ft_printf("\n");
	ft_printf("Stack A\n");
	while ((*st_a)->next != NULL)
	{
		ft_printf("%d  -> ", (*st_a)->nb);
		ft_printf("chunk = %d\n", (*st_a)->chunk);
		(*st_a) = (*st_a)->next;
	}
	ft_printf("%d  -> ", (*st_a)->nb);
	ft_printf("chunk = %d\n\n", (*st_a)->chunk);
	ft_printf("\nStack B\n");
	while ((*st_b)->next != NULL)
	{
		ft_printf("%d  -> ", (*st_b)->nb);
		ft_printf("chunk = %d\n", (*st_b)->chunk);
		(*st_b) = (*st_b)->next;
	}
	ft_printf("%d  -> ", (*st_b)->nb);
	ft_printf("chunk = %d\n\n", (*st_b)->chunk);
}
