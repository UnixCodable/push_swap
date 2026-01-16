/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 07:12:03 by lbordanave        #+#    #+#             */
/*   Updated: 2026/01/16 18:29:05 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdarg.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

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
	int		checker;
	double	disorder;
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
double	compute_disorder(t_n *st_a, struct s_d *data);
void	ft_nlstclear(t_n **lst);
t_n		*create_st_a(char **args, struct s_d *data);

#endif
