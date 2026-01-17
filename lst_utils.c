/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 02:35:23 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/17 17:57:30 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_n	*ft_numlst_new(int nbr)
{
	t_n	*lst;

	lst = malloc(sizeof(t_n));
	if (!lst)
		return (NULL);
	lst->nb = nbr;
	lst->next = NULL;
	lst->previous = NULL;
	return (lst);
}

void	ft_lst_print(t_n *lst)
{
	while (lst)
	{
		ft_printf("%d ", (lst)->nb);
		lst = (lst)->next;
	}
}

void	ft_nlstclear(t_n **lst)
{
	t_n	*next_temp;

	if (!lst)
		return ;
	while ((*lst) != NULL)
	{
		next_temp = (*lst)->next;
		free(*lst);
		(*lst) = next_temp;
	}
}

t_n	*create_st_a(char **args, struct s_d *data)
{
	t_n	*nbrs;
	t_n	*prev;
	t_n	*first;
	int	i;

	i = 1;
	while (!ft_isnumber(*args))
		args++;
	nbrs = ft_numlst_new((int)ft_atoi(*args));
	first = nbrs;
	prev = nbrs;
	data->number_count++;
	while (*++args)
	{
		nbrs->next = ft_numlst_new((int)ft_atoi(*args));
		nbrs = nbrs->next;
		nbrs->pos = i++;
		nbrs->chunk = 0;
		nbrs->previous = prev;
		prev = nbrs;
		data->number_count++;
	}
	return (first);
}
