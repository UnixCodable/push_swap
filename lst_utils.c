/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 02:35:23 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/22 02:38:33 by lbordanave       ###   ########.fr       */
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
