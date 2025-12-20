/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:11:04 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/13 16:26:44 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*voyager;

	if (!new || !lst)
		return ;
	voyager = *lst;
	if (*lst == NULL)
	{
		(*lst) = new;
		return ;
	}
	if (new != NULL)
	{
		while (voyager->next != NULL)
			voyager = voyager->next;
		voyager->next = new;
	}
}

/*Add a new node at the last position of a list*/
