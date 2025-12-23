/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 02:25:40 by lbordana          #+#    #+#             */
/*   Updated: 2025/12/23 20:00:20 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	compute_disorder(t_num_list *stack_a, struct s_data *data)
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
	data->disorder = mistakes / total_pairs;
}

t_num_list	*create_stack_a(char **args, struct s_data *data)
{
	t_num_list	*nbrs;
	t_num_list	*prev;
	t_num_list	*first;

	data->pa_count += 1;
	while (ft_strncmp(ft_itoa(ft_atoi(*args)), *args, -1))
		args++;
	nbrs = ft_numlst_new((int)ft_atoi(*args));
	first = nbrs;
	prev = nbrs;
	while (*++args)
	{
		nbrs->next = ft_numlst_new((int)ft_atoi(*args));
		nbrs = nbrs->next;
		nbrs->is_empty = 0;
		nbrs->previous = prev;
		prev = nbrs;
	}
	return (first);
}

int	algorythm_checker(char *arg, struct s_data *data)
{
	if (!ft_strncmp(arg, "--simple", -1))
		data->force_simple = 1;
	else if (!ft_strncmp(arg, "--medium", -1))
		data->force_medium = 1;
	else if (!ft_strncmp(arg, "--complex", -1))
		data->force_complex = 1;
	else if (!ft_strncmp(arg, "--adaptive", -1))
		data->force_adaptive = 1;
	else
	{
		data->force_adaptive = 1;
		return (0);
	}
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
		if (algorythm_checker(*args, data) && (!opt_off++))
			args++;
		else if (!ft_strncmp(*args, ft_itoa(ft_atoi(*args)), -1))
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
	return (1);
}

int	main(int ac, char **av)
{
	t_num_list		*stack_a;
	t_num_list		*stack_b;
	struct s_data	data;

	(void) ac;
	av++;
	data = (struct s_data){0};
	if (error_handler(av, &data) == 0)
		return (write(2, "Error\n", 6), 0);
	stack_a = create_stack_a(av, &data);
	stack_b = NULL;
	compute_disorder(stack_a, &data);
	printf("Bench = %d\n", data.benchmark);
	printf("Simple = %d\n", data.force_simple);
	printf("Medium = %d\n", data.force_medium);
	printf("Complex = %d\n", data.force_complex);
	printf("Adaptive = %d\n", data.force_adaptive);
	printf("Disorder = %.2f\n", data.disorder);
	(void) stack_b;
	return (1);
}

// t_num_list	*create_stack_b(t_num_list *stack_a)
// {
// 	t_num_list	*nbrs;
// 	t_num_list	*prev;
// 	t_num_list	*first;

// 	if (!stack_a)
// 	{
// 		nbrs = NULL;
// 		return (nbrs);
// 	}
// 	nbrs = ft_numlst_new(0);
// 	first = nbrs;
// 	prev = nbrs;
// 	stack_a = stack_a->next;
// 	while (stack_a)
// 	{
// 		nbrs->next = ft_numlst_new(0);
// 		nbrs->is_empty = 1;
// 		nbrs = nbrs->next;
// 		nbrs->previous = prev;
// 		prev = nbrs;
// 		stack_a = stack_a->next;
// 	}
// 	return (first);
// }