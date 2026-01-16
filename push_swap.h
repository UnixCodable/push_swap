/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 07:12:03 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/14 19:19:47 by lbordana         ###   ########.fr       */
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
}	t_n;

struct s_d
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
	int		force_med;
	int		force_complex;
	int		force_adaptive;
	int		low_disorder;
	int		med_disorder;
	int		number_count;
	int		benchmark;
	double	disorder;
};

struct s_m
{
	long int		min;
	long int		max;
	long int		n_chunk;
	long int		l_min;
	long int		l_max;
	int				l;
	int				p;
	int				chunk;
};


t_n		*ft_numlst_new(int nbr);
void	sa(t_n **st_a, struct s_d *data, int to_print);
void	sb(t_n **st_b, struct s_d *data, int to_print);
void	ss(t_n **st_a, t_n **st_b, struct s_d *data);
void	pa(t_n **st_a, t_n **st_b, struct s_d *data);
void	pb(t_n **st_a, t_n **st_b, struct s_d *data);
void	ra(t_n **st_a, struct s_d *data, int to_print);
void	rb(t_n **st_b, struct s_d *data, int to_print);
void	rr(t_n **st_a, t_n **st_b, struct s_d *data);
void	rra(t_n **st_a, struct s_d *data, int to_print);
void	rrb(t_n **st_b, struct s_d *data, int to_print);
void	rrr(t_n **st_a, t_n **st_b, struct s_d *data);
void	simple_alg(t_n **st_a, t_n **st_b, struct s_d *data);
void	med_alg(t_n **st_a, t_n **st_b, struct s_d *data, struct s_m *med);
void	chunk(t_n **st_a, struct s_d *data, struct s_m *med);
void	create_chunk(t_n **st_a, struct s_m *med);
void	give_chunk(t_n **st_a, struct s_m *med);
int		chunk_present(t_n **st_a, long int i);
int		chunk_checker_max_strict(t_n **st_b, int actual_chunk, int max_value);
int		chunk_checker_min_strict(t_n **st_a, int actual_chunk, int min_value);
void	complex_alg(t_n **st_a, t_n **st_b, struct s_d *data);
int		min_finder(t_n **st_a);
int		chunk_checker_min(t_n **st_a, int actual_chunk, int min_value);
int		check_other_chunk(t_n **stack);
t_n		*best_pivot(t_n **st_b, int chunk);
int		chunk_checker_max(t_n **st_b, int max_value);
void	ft_lst_print(t_n *lst);
void	adaptive_alg(t_n **st_a, t_n **st_b, struct s_d *data, struct s_m *med);
double	compute_disorder(t_n *st_a, struct s_d *data);
void	compute_benchmark(struct s_d *data, t_n **sorted);
t_n		*find_nearest(t_n **st_b, int nbr, int chunk);
void	ft_nlstclear(t_n **lst);
t_n		*create_st_a(char **args, struct s_d *data);

#endif
