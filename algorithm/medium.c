/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:17:40 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/07 10:02:58 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	chunk(int *L_min, int *L_max, int *L, int *i, int *max, int *min, int *p)
{
	if (*p == 0)
	{
		*L = (*max - *min + 1) / *i;
		*L_max = *min + *L;
		*L_min = *L_max - *L;
		ft_printf("L_min = %d\n", *L_min);
		ft_printf("L_max = %d\n\n", *L_max);
		while (*L_max <= *max)
		{
			*L_min = *L_max + 1;
			*L_max = *L_min + *L;
			ft_printf("L_min = %d\n", *L_min);
			ft_printf("L_max = %d\n\n", *L_max);
		}
		*p = 1;
	}
	else
	{
		*L_max = *L_min - 1;
		*L_min = *L_max - *L;
		ft_printf("L_min = %d\n", *L_min);
		ft_printf("L_max = %d\n\n", *L_max);
	}
	return ;
}

void	number_chunk(struct s_data *data, int *i)
{
	while (*i * *i <= data->number_count)
	{
		if (*i * *i == data->number_count)
			break ;
		*i += 1;
	}
}

void	calcul_min_max(t_nlist *st_a, int *min, int *max)
{
	*min = st_a->nb;
	*max = st_a->nb;
	while (st_a)
	{
		if (st_a->nb < *min)
			*min = st_a->nb;
		if (st_a->nb > *max)
			*max = st_a->nb;
		st_a = st_a->next;
	}
}

void	medium_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	static int	min;
	static int	max;
	static int	i;
	static int	L_min;
	static int	L_max;
	static int	L;
	static int	p;

	if (p == 0)
	{
		calcul_min_max(*st_a, &min, &max);
		number_chunk(data, &i);
		ft_printf("L = %d\n", L);
		ft_printf("i = %d\n", i);
		ft_printf("min = %d\n", min);
		ft_printf("max = %d\n", max);
	}
	chunk(&L_min, &L_max, &L, &i, &max, &min, &p);
	if (L_min < min)
		return ;
	i = data->number_count;
	while (i != 0)
	{
		if ((*st_a)->nb >= L_min && (*st_a)->nb <= L_max)
			pb(st_a, st_b, data);
		else
		{
			ra(st_a, data, 1);
		}
		i--;
	}
	while (compute_disorder((*st_b), data) != 1)
	{
		if ((*st_b)->nb > (*st_b)->next->nb)
			rrb(st_b, data, 1);
		else
		{
			sb(st_b, data, 1);
			if (compute_disorder((*st_b), data) != 1)
				rrb(st_b, data, 1);
		}
	}
	while ((*st_b))
	{
		pa(st_a, st_b, data);
		// ra(st_a, data, 1);
	}
	ft_printf("P = %d\n", p);
	if (compute_disorder((*st_a), data) != 0)
		medium_alg(st_a, st_b, data);
	while ((*st_a))
	{
		ft_printf("%d-", (*st_a)->nb);
		(*st_a) = (*st_a)->next;
	}
	ft_printf("\n");
	ft_printf("Nombre de couts : %d\n", data->total_count);
	return ;
}
