/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 02:25:40 by lbordana          #+#    #+#             */
/*   Updated: 2025/12/21 04:28:18 by lbordanave       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	error_handler(char **args)
{
	static int	opt_off = 0;
	int			*i;

	while (*args != NULL)
	{
		i = 0;
		while (args[] != NULL)
			if (*args == saved)
				return (write(2, "Error\n", 6), 0);
		*args = saved;
		if (!ft_strncmp(*args, ft_itoa(ft_atoi(*args)), ft_strlen(*args)))
			args++;
		else if (!ft_strncmp(*args, "--simple", 8) && (!opt_off++))
			args++;
		else if (!ft_strncmp(*args, "--medium", 8) && (!opt_off++))
			args++;
		else if (!ft_strncmp(*args, "--complex", 9) && (!opt_off++))
			args++;
		else if (!ft_strncmp(*args, "--adaptive", 10) && (!opt_off++))
			args++;
		else if (!ft_strncmp(*args, "--bench", 7))
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
