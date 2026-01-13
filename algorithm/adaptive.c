/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:18:07 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/13 13:53:44 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	if (compute_disorder((*st_a), data) < 0.2)
		simple_alg(st_a, st_b, data);
	if (compute_disorder((*st_a), data) >= 0.2
		&& compute_disorder((*st_a), data) < 0.5)
		medium_alg(st_a, st_b, data);
	if (compute_disorder((*st_a), data) >= 0.5)
		complex_alg(st_a, st_b, data);
	return ;
}
