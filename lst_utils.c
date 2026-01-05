/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 02:35:23 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/05 18:56:31 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nlist	*ft_numlst_new(int nbr)
{
	t_nlist	*lst;

	lst = malloc(sizeof(t_nlist));
	if (!lst)
		return (NULL);
	lst->nb = nbr;
	lst->next = NULL;
	lst->previous = NULL;
	return (lst);
}

void	ft_lst_print(t_nlist *lst)
{
	while (lst)
	{
		ft_printf("%d ", (lst)->nb);
		lst = (lst)->next;
	}
}
