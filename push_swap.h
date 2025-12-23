/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agathe <agathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 07:12:03 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/23 20:33:23 by agathe           ###   ########.fr       */
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

struct s_data
{
	int		pa_count;
	int		pb_count;
	int		ra_count;
	int		rb_count;
	int		rr_count;
	int		rra_count;
	int		rrb_count;
	int		rrr_count;
	int		sa_count;
	int		sb_count;
	int		ss_count;
	int		total_count;
	int		force_simple;
	int		force_medium;
	int		force_complex;
	int		force_adaptive;
	int		benchmark;
	double	disorder;
};

t_num_list	*ft_numlst_new(int nbr);
void		move_sa(t_num_list **stack_a, struct s_data *data);
void		move_sb(t_num_list **stack_b, struct s_data *data);
void		move_ss(t_num_list **stack_a, t_num_list **stack_b, struct s_data *data);
void		move_pa(t_num_list **stack_a, t_num_list **stack_b, struct s_data *data);
void		move_ra(t_num_list **stack_a);

#endif
