/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 02:25:40 by lbordana          #+#    #+#             */
/*   Updated: 2026/01/14 18:26:08 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

int	strategy_checker(char *arg, struct s_d *data)
{
	if (!ft_strncmp(arg, "--simple", -1))
		data->force_simple = 1;
	else if (!ft_strncmp(arg, "--medium", -1))
		data->force_med = 1;
	else if (!ft_strncmp(arg, "--complex", -1))
		data->force_complex = 1;
	else if (!ft_strncmp(arg, "--low-disorder", -1))
		data->low_disorder = 1;
	else if (!ft_strncmp(arg, "--med-disorder", -1))
		data->med_disorder = 1;
	else if (!ft_strncmp(arg, "--adaptive", -1))
		data->force_adaptive = 1;
	else
		return (0);
	return (1);
}

int	error_handler(char **args, struct s_d *data)
{
	int		opt_off;
	char	**voyager;

	opt_off = 0;
	while (*args)
	{
		voyager = args;
		while (*voyager++)
			if (*voyager && !ft_strncmp(*voyager, *args, -1))
				return (0);
		if (strategy_checker(*args, data) && (!opt_off++))
			args++;
		else if (ft_isnumber(*args) && args++)
			opt_off += 2;
		else if (!ft_strncmp(*args, "--bench", -1) && opt_off < 2 && args++)
			data->benchmark = 1;
		else
			return (0);
	}
	return (opt_off + 2);
}

void	init_sort(t_n **st_a, t_n **st_b, struct s_d *data, struct s_m *med)
{
	if (data->force_simple)
		simple_alg(st_a, st_b, data);
	else if (data->force_med)
		med_alg(st_a, st_b, data, med);
	else if (data->force_complex || data->low_disorder || data->med_disorder)
		complex_alg(st_a, st_b, data);
	else
		adaptive_alg(st_a, st_b, data, med);
}

int	main(int ac, char **av)
{
	t_n			*st_a;
	t_n			*st_b;
	struct s_d	data;
	struct s_m	med;

	av++;
	(void)ac;
	data = (struct s_d){0};
	med = (struct s_m){0};
	if (error_handler(av, &data) < 2)
		return (write(2, "Error\n", 6), 0);
	else if (error_handler(av, &data) < 6)
		return (0);
	st_a = create_st_a(av, &data);
	st_b = NULL;
	compute_disorder(st_a, &data);
	init_sort(&st_a, &st_b, &data, &med);
	compute_benchmark(&data, &st_a);
	ft_nlstclear(&st_a);
	return (1);
}

// testing(&st_a, &st_b, &data);
