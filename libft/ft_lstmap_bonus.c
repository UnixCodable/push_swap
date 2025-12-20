/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:00:56 by lbordana          #+#    #+#             */
/*   Updated: 2025/11/14 01:59:27 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_mod;
	t_list	*saved;

	if (!f || !lst)
		return (NULL);
	lst_mod = ft_lstnew(f(lst->content));
	saved = lst_mod;
	while (lst->next != NULL)
	{
		lst = lst->next;
		lst_mod->next = ft_lstnew(f(lst->content));
		if (!lst_mod)
			ft_lstclear(&saved, del);
		lst_mod = lst_mod->next;
	}
	return (saved);
}

/*Create a new list copying a given one, and apply a function of each content
of nodes in it and delete those if it can't allocate into their content section
*/
