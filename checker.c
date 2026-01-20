/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:21:13 by aeuvrard          #+#    #+#             */
/*   Updated: 2026/01/20 17:45:35 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

double	compute_disorder(t_n *st_a, struct s_d *data)
{
	double	mistakes;
	double	total_pairs;

	mistakes = 0.00;
	total_pairs = 0.00;
	while (st_a->next)
	{
		total_pairs += 1;
		if (st_a->nb > st_a->next->nb)
			mistakes += 1;
		st_a = st_a->next;
	}
	if (data->total_count == 0)
		data->disorder = mistakes / total_pairs;
	return (mistakes / total_pairs);
}

int	error_handler(char **args)
{
	char	**j;

	while (*args)
	{
		j = args;
		while (*j++)
			if (*j && !ft_strncmp(*j, *args, -1))
				return (0);
		if (ft_isnumber(*args))
			args++;
		else
			return (0);
	}
	return (1);
}

void	make_move(char *mvm, t_n **st_a, t_n **st_b, struct s_d *data)
{
	if (mvm[0] == 'p' && mvm[1] == 'a' && mvm[2] == '\n')
		pa(st_a, st_b, data);
	else if (mvm[0] == 'p' && mvm[1] == 'b' && mvm[2] == '\n')
		pb(st_a, st_b, data);
	else if (mvm[0] == 's' && mvm[1] == 'a' && mvm[2] == '\n')
		sa(st_a, data, 0);
	else if (mvm[0] == 's' && mvm[1] == 'b' && mvm[2] == '\n')
		sb(st_b, data, 0);
	else if (mvm[0] == 's' && mvm[1] == 's' && mvm[2] == '\n')
		ss(st_a, st_b, data);
	else if (mvm[0] == 'r' && mvm[1] == 'a' && mvm[2] == '\n')
		ra(st_a, data, 0);
	else if (mvm[0] == 'r' && mvm[1] == 'b' && mvm[2] == '\n')
		rb(st_b, data, 0);
	else if (mvm[0] == 'r' && mvm[1] == 'r' && mvm[2] == '\n')
		rr(st_a, st_b, data);
	else if (mvm[0] == 'r' && mvm[1] == 'r' && mvm[2] == 'a')
		rra(st_a, data, 0);
	else if (mvm[0] == 'r' && mvm[1] == 'r' && mvm[2] == 'b')
		rrb(st_b, data, 0);
	else if (mvm[0] == 'r' && mvm[1] == 'r' && mvm[2] == 'r')
		rrr(st_a, st_b, data);
	else
		return ;
}

void	reproduce_mvm(t_n **st_a, t_n **st_b, struct s_d *data)
{
	char	*mvm;

	data->checker = 1;
	mvm = get_next_line(0);
	while (mvm)
	{
		make_move(mvm, st_a, st_b, data);
		free(mvm);
		mvm = get_next_line(0);
	}
	free(mvm);
}

int	main(int ac, char **av)
{
	t_n				*st_a;
	t_n				*st_b;
	struct s_d		data;

	av++;
	data = (struct s_d){0};
	if (ac < 2)
		return (0);
	if (error_handler(av) == 0)
		return (write(2, "Error\n", 6), 0);
	st_a = create_st_a(av, &data);
	st_b = NULL;
	reproduce_mvm(&st_a, &st_b, &data);
	if ((st_a && !compute_disorder(st_a, &data) && !st_b)
		|| (st_a && !st_a->next && !st_b))
		return (write(1, "OK\n", 3));
	else
		return (write(1, "KO\n", 3));
}
