/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:57:44 by lbordanave        #+#    #+#             */
/*   Updated: 2025/11/13 15:59:02 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_temp;

	if (!lst || !del)
		return ;
	while ((*lst) != NULL)
	{
		del((*lst)->content);
		next_temp = (*lst)->next;
		free(*lst);
		(*lst) = next_temp;
	}
}

/*Clear and frees an entire list*/
