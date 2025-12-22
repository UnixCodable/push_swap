/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 02:25:40 by lbordana          #+#    #+#             */
/*   Updated: 2025/12/22 03:47:16 by lbordanave       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

double	compute_disorder(t_num_list *stack_a)
{
	double	mistakes;
	double	total_pairs;

	mistakes = 0.00;
	total_pairs = 0.00;
	while (stack_a->next)
	{
		total_pairs += 1;
		if (stack_a->nb > stack_a->next->nb)
			mistakes += 1;
		stack_a = stack_a->next;
	}
	return (mistakes / total_pairs);
}

t_num_list	*list_converter(char **args)
{
	t_num_list	*nbrs;
	t_num_list	*prev;
	t_num_list	*first;

	while (ft_strncmp(ft_itoa(ft_atoi(*args)), *args, -1))
		args++;
	nbrs = ft_numlst_new(ft_atoi(*args));
	first = nbrs;
	prev = nbrs;
	while (*++args)
	{
		nbrs->next = ft_numlst_new(ft_atoi(*args));
		nbrs = nbrs->next;
		nbrs->previous = prev;
		prev = nbrs;
	}
	return (first);
}

int	error_handler(char **args)
{
	static int	opt_off;
	char		**voyager;

	while (*args)
	{
		voyager = args;
		while (*voyager++)
			if (*voyager && !ft_strncmp(*voyager, *args, -1))
				return (0);
		if (!ft_strncmp(*args, ft_itoa(ft_atoi(*args)), -1))
		{
			args++;
			opt_off += 2;
		}
		else if ((!ft_strncmp(*args, "--simple", -1)
				|| !ft_strncmp(*args, "--medium", -1)
				|| !ft_strncmp(*args, "--complex", -1)
				|| !ft_strncmp(*args, "--adaptive", -1)) && (!opt_off++))
			args++;
		else if (!ft_strncmp(*args, "--bench", -1) && opt_off < 2)
			args++;
		else
			return (0);
	}
	return (1);
}

int	create_stack_a(int args_count, char **args)
{
	t_num_list	*stack_a;
	double		score;

	args++;
	(void) args_count;
	if (error_handler(args) == 0)
		return (0);
	stack_a = list_converter(args);
	score = compute_disorder(stack_a);
	printf("%.2f", score);
	return (1);
}

int	main(int ac, char **av)
{
	int	status;

	status = create_stack_a(ac, av);
	if (!status)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
