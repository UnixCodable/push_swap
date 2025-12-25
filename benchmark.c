/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:41:52 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/25 03:50:13 by lbordanave       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_header(void)
{
	ft_printf("\033[2J\033[H\033[1;32m");
	ft_printf("╔═══════════════════════════════════════");
	ft_printf("═══════════════════════════════════════╗\n");
	ft_printf("║\t\t\t\t\t\t\t\t\t       ║\n");
	ft_printf("║ ██████╗ ██╗   ██╗███████╗██╗  ██╗");
	ft_printf("        ███████╗██╗    ██╗ █████╗ ██████╗   ║\n");
	ft_printf("║ ██╔══██╗██║   ██║██╔════╝██║  ██║        ");
	ft_printf("██╔════╝██║    ██║██╔══██╗██╔══██╗  ║\n");
	ft_printf("║ ██████╔╝██║   ██║███████╗███████║        ");
	ft_printf("███████╗██║ █╗ ██║███████║██████╔╝  ║\n");
	ft_printf("║ ██╔═══╝ ██║   ██║╚════██║██╔══██║        ");
	ft_printf("╚════██║██║███╗██║██╔══██║██╔═══╝   ║\n");
	ft_printf("║ ██║     ╚██████╔╝███████║██║  ██║███████╗");
	ft_printf("███████║╚███╔███╔╝██║  ██║██║       ║\n");
	ft_printf("║ ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝");
	ft_printf("╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝       ║\n");
	ft_printf("╠═══════════════════╦═══════════════════");
	ft_printf("═══════════════════╦═══════════════════╣\n");
	return ;
}

void	space_bound(int size, int dyn_space)
{
	while (size++ != dyn_space)
		ft_printf(" ");
}

void	compute_benchmark(struct s_data *data)
{
	int	disorder;

	disorder = (int)(data->disorder * 10000);
	if (data->benchmark == 0)
		return ;
	create_header();
	ft_printf("║ Disorder : %d.%d%%", disorder / 100, disorder % 100);
	space_bound(ft_numlen(disorder % 100) + ft_numlen(disorder / 100), 5);
	ft_printf("║\t\t  BENCHMARKING\t\t   ║       MOVES       ║\n");
	ft_printf("╠═══════════════════╣\t\t\t\t\t   ╠═══════════════════╣");
	ft_printf("║ Total operations  ║\t\t\t\t\t   ║ SA : %d\n", data->sa_count);
	ft_printf("║        %d  ", data->total_count);
	space_bound(ft_numlen(data->total_count), 9);
	printf("║\t\t\t\t\t   ║ RA : %d", data->ra_count);
	return ;
}
