/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:18:01 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/29 09:17:51 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	chunk_disorder(t_nlist *st_a, struct s_data *data, int chunk)
{
	double	mistakes;
	double	total_pairs;

	mistakes = 0.00;
	total_pairs = 0.00;
	while (st_a->next)
	{
		if (st_a->chunk == chunk && st_a->next->chunk == chunk)
		{
			total_pairs += 1;
			if (st_a->nb > st_a->next->nb)
				mistakes += 1;
		}
		st_a = st_a->next;
	}
	return (mistakes / total_pairs);
}

void	complex_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	static int	pivot;
	int			chunk;
	int			front;
	t_nlist		*voyager;
	t_nlist		*checker;

	voyager = *st_a;
	checker = *st_a;
	front = 0;
	while (voyager->next != NULL)
	{
		while (checker != NULL)
		{
			if (!front)
				if (checker->nb > voyager->nb)
					break ;
			else if (front)
				if (checker->nb < voyager->nb)
					break ;
			else if (checker->nb == voyager->nb)
				front = 1;
			checker = checker->next;
		}
		if (checker == NULL)
			break ;
		voyager = voyager->next;
		checker = *st_a;
		front = 0;
	}
}
