/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 02:25:40 by lbordana          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/09 14:05:53 by aeuvrard         ###   ########.fr       */
=======
/*   Updated: 2026/01/08 11:51:24 by lbordana         ###   ########.fr       */
>>>>>>> algorithm_complex
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

double	compute_disorder(t_nlist *st_a, struct s_data *data)
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

t_nlist	*create_st_a(char **args, struct s_data *data)
{
	t_nlist	*nbrs;
	t_nlist	*prev;
	t_nlist	*first;
	int		i;

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

int	strategy_checker(char *arg, struct s_data *data)
{
	if (!ft_strncmp(arg, "--simple", -1))
		data->force_simple = 1;
	else if (!ft_strncmp(arg, "--medium", -1))
		data->force_medium = 1;
	else if (!ft_strncmp(arg, "--complex", -1))
		data->force_complex = 1;
	else if (!ft_strncmp(arg, "--low-disorder", -1))
		data->low_disorder = 1;
	else if (!ft_strncmp(arg, "--medium-disorder", -1))
		data->med_disorder = 1;
	else if (!ft_strncmp(arg, "--adaptive", -1))
		data->force_adaptive = 1;
	else
		return (0);
	return (1);
}

int	error_handler(char **args, struct s_data *data)
{
	static int	opt_off;
	char		**voyager;

	while (*args)
	{
		voyager = args;
		while (*voyager++)
			if (*voyager && !ft_strncmp(*voyager, *args, -1))
				return (0);
		if (strategy_checker(*args, data) && (!opt_off++))
			args++;
		else if (ft_isnumber(*args))
		{
			args++;
			opt_off += 2;
		}
		else if (!ft_strncmp(*args, "--bench", -1) && opt_off < 2)
		{
			data->benchmark = 1;
			args++;
		}
		else
			return (0);
	}
	return (opt_off);
}

int	main(int ac, char **av)
{
	t_nlist			*st_a;
	t_nlist			*st_b;
	struct s_data	data;
	struct s_medium	medium;

	av++;
	(void) ac;
	data = (struct s_data){0};
	if (error_handler(av, &data) < 4)
		return (write(2, "Error\n", 6), 0);
	st_a = create_st_a(av, &data);
	st_b = NULL;
	medium.p = 0;
	compute_disorder(st_a, &data);
	if (data.force_simple)
		simple_alg(&st_a, &st_b, &data);
	else if (data.force_medium)
		medium_alg(&st_a, &st_b, &data, &medium);
	else if (data.force_complex || data.low_disorder || data.med_disorder)
		complex_alg(&st_a, &st_b, &data);
	else
		adaptive_alg(&st_a, &st_b, &data);
	compute_benchmark(&data, &st_a);
	ft_nlstclear(&st_a);
	return (1);
}

// testing(&st_a, &st_b, &data);
