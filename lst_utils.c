/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 02:35:23 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/22 19:15:47 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num_list	*ft_numlst_new(int nbr)
{
	t_num_list	*lst;

	lst = malloc(sizeof(t_num_list));
	if (!lst)
		return (NULL);
	lst->nb = nbr;
	lst->next = NULL;
	lst->previous = NULL;
	return (lst);
}
