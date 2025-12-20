/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeuvrard <aeuvrard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 02:25:40 by lbordana          #+#    #+#             */
/*   Updated: 2025/12/20 15:22:30 by aeuvrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	error_handler(char *arg)
{
	int	i;

	i = 1;
	while (arg[i] != '\0')
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else if (ft_strncmp(arg, "--simple", 8) == 0)
			i += ft_strlen(arg) + 1;
		else if (ft_strncmp(arg, "--medium", 8) == 0)
			i += ft_strlen(arg) + 1;
		else if (ft_strncmp(arg, "--complex", 9) == 0)
			i += ft_strlen(arg) + 1;
		else if (ft_strncmp(arg, "--adaptive", 10) == 0)
			i += ft_strlen(arg) + 1;
		else if (ft_strncmp(arg, "--bench", 7) == 0)
			i += ft_strlen(arg) + 1;
		else
			return (write(2, "Error", 5), 0);
	}
	printf("%s\n", arg);
	return (1);
}

int	create_stack_a(int arg_count, char **args)
{
	int	i;

	i = 1;
	while (i != arg_count)
	{
		if (error_handler(args[i]) == 0)
			return (0);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	create_stack_a(ac, av);
	return (0);
}
