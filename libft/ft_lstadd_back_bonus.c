/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:11:04 by lbordana          #+#    #+#             */
/*   Updated: 2026/01/14 19:03:32 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*j;

	if (!new || !lst)
		return ;
	j = *lst;
	if (*lst == NULL)
	{
		(*lst) = new;
		return ;
	}
	if (new != NULL)
	{
		while (j->next != NULL)
			j = j->next;
		j->next = new;
	}
}

/*Add a new node at the last position of a list*/
