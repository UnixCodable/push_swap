/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 04:18:07 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/14 18:24:14 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive_alg(t_n **st_a, t_n **st_b, struct s_d *data, struct s_m *med)
{
	if (compute_disorder((*st_a), data) < 0.2)
		simple_alg(st_a, st_b, data);
	if (compute_disorder((*st_a), data) >= 0.2
		&& compute_disorder((*st_a), data) < 0.5)
		med_alg(st_a, st_b, data, med);
	if (compute_disorder((*st_a), data) >= 0.5)
		complex_alg(st_a, st_b, data);
	return ;
}
