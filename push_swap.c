/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 02:25:40 by lbordana          #+#    #+#             */
/*   Updated: 2025/12/21 22:17:31 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	error_handler(char **args)
{
	static int	opt_off;
	char		**voyager;

	while (*args)
	{
		voyager = args;
		while (*voyager++)
			if (*voyager && !ft_strncmp(*voyager, *args, -1))
				return (write(2, "Error\n", 6), 0);
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
			return (write(2, "Error\n", 6), 0);
	}
	return (1);
}

int	create_stack_a(int args_count, char **args)
{
	int i;

	args++;
	if (error_handler(args) == 0)
		return (0);
	while (i != args_count)
	{
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	create_stack_a(ac, av);
	return (0);
}
