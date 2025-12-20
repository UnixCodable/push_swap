/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 02:25:40 by lbordana          #+#    #+#             */
/*   Updated: 2025/12/20 10:57:26 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	*error_handler(int arg_count, char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else if (ft_strcmp(arg, "--simple") == 0)
			i += ft_strlen(arg);
		else if (ft_strcmp(arg, "--medium") == 0)
			i += ft_strlen(arg);
		else if (ft_strcmp(arg, "--complex") == 0)
			i += ft_strlen(arg);
		else if (ft_strcmp(arg, "--adaptive") == 0)
			i += ft_strlen(arg);
		else if (ft_strcmp(arg, "--bench") == 0)
			i += ft_strlen(arg);
	return (0);
}

int	*create_stack_a(int arg_count, char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != (arg_count - 1))
	{
		while (args[i][j] != '\0')
		{
			if (args[i][j] >= '0' && args[i][j] <= '9')
				j++;
			else if (ft_strcmp(args[i], "--simple") == 0)
				j += 8;
			else if (args[i] == "--medium")
				j += 8;
			else if (args[i] == "--complex")
				j += 9;
			else if (args[i] == "--adaptive")
				j += 10;
		}
		i++;
		j = 0;
	}
}

int	main(int ac, char **av)
{
	printf("%d", ac);
	printf("%s", av[0]);
	return (0);
}
