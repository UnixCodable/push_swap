/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 07:12:03 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/22 21:38:50 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_num_list
{
	int					nb;
	int					is_empty;
	struct s_num_list	*previous;
	struct s_num_list	*next;
}	t_num_list;

t_num_list	*ft_numlst_new(int nbr);
void		move_sa(t_num_list *stack_a);
void		move_ra(t_num_list **stack_a);

#endif
