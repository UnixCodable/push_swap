/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 07:12:03 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/13 13:26:01 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include "libft/libft.h"

# define POS "\e[%d;%dH"

typedef struct s_num_list
{
	int					nb;
	int					pos;
	int					chunk;
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
	int		low_disorder;
	int		med_disorder;
	int		number_count;
	int		benchmark;
	double	disorder;
};

struct s_medium
{
	int			min;
	int			max;
	int			n_chunk;
	int			l_min;
	int			l_max;
	int			l;
	int			p;
	int			chunk;
};


t_nlist	*ft_numlst_new(int nbr);
void	sa(t_nlist **st_a, struct s_data *data, int to_print);
void	sb(t_nlist **st_b, struct s_data *data, int to_print);
void	ss(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	pa(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	pb(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	ra(t_nlist **st_a, struct s_data *data, int to_print);
void	rb(t_nlist **st_b, struct s_data *data, int to_print);
void	rr(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	rra(t_nlist **st_a, struct s_data *data, int to_print);
void	rrb(t_nlist **st_b, struct s_data *data, int to_print);
void	rrr(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	simple_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
void	medium_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data, struct s_medium *medium);
void	chunk(t_nlist **st_a, struct s_data *data, struct s_medium *medium);
void	create_chunk(t_nlist **st_a, struct s_medium *medium);
void	give_chunk(t_nlist **st_a, struct s_medium *medium);
int		chunk_present(t_nlist **st_a, int i);
int		chunk_checker_max_strict(t_nlist **st_b, int actual_chunk, int max_value);
int		chunk_checker_min_strict(t_nlist **st_a, int actual_chunk, int min_value);
void	complex_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
int		min_finder(t_nlist **st_a);
int		chunk_checker_min(t_nlist **st_a, int actual_chunk, int min_value);
int		check_other_chunk(t_nlist **stack);
t_nlist	*best_pivot(t_nlist **st_b, int chunk);
int		chunk_checker_max(t_nlist **st_b, int max_value);
void	ft_lst_print(t_nlist *lst);
void	adaptive_alg(t_nlist **st_a, t_nlist **st_b, struct s_data *data);
double	compute_disorder(t_nlist *st_a, struct s_data *data);
void	compute_benchmark(struct s_data *data, t_nlist **sorted);
t_nlist	*find_nearest(t_nlist **st_b, int nbr, int chunk);
void	ft_nlstclear(t_nlist **lst);

#endif
