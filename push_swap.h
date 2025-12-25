/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 07:12:03 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/25 01:14:49 by lbordanave       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_num_list
{
	int					nb;
	int					pos;
	struct s_num_list	*previous;
	struct s_num_list	*next;
}	t_nlist;

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

t_nlist	*ft_numlst_new(int nbr);
void	sa(t_nlist **st_a, struct s_data *data);
void	sb(t_nlist **st_b, struct s_data *data);
void	ss(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	pa(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	pb(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	testing(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	ra(t_nlist **st_a, struct s_data *data);
void	rb(t_nlist **st_b, struct s_data *data);
void	rr(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	rra(t_nlist **st_a, struct s_data *data);
void	rrb(t_nlist **st_b, struct s_data *data);
void	rrr(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	simple_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	medium_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	complex_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	adaptive_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
double	compute_disorder(t_nlist *st_a, struct s_data *data);
void	exec_sort(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	compute_benchmark(struct s_data *data);

#endif
