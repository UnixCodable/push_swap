/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:41:52 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/26 10:35:51 by lbordanave       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_header(void)
{
	ft_printf("\e[2J\e[H\e[1;32m");
	ft_printf("\n\n\
  ██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ \n\
  ██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗\n\
  ██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝\n\
  ██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ \n\
  ██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║     \n\
  ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     \n\
  ");
	return ;
}

void	pos_framing(void)
{
	int	x;
	int	y;

	y = 1;
	x = 1;
	(void) x;
	ft_printf(POS"╔"POS"╗"POS"╚"POS"╝", 0, 1, 0, 80, 23, 1, 23, 80);
	while (++y != 80)
		ft_printf(POS"═"POS"═"POS"═"POS"═", 0, y, 9, y, 21, y, 23, y);
	while (++x != 23)
		ft_printf(POS"║"POS"║", x, 1, x, 80, 21);
	ft_printf(POS"╣"POS"╣"POS"╠"POS"╠", 9, 80, 21, 80, 9, 1, 21, 1);
	ft_printf(POS"\n", 23, 80);
}

void	compute_benchmark(struct s_data *data)
{
	//int	disorder;

	//disorder = (int)(data->disorder * 10000);
	if (data->benchmark == 0)
		return ;
	create_header();
	pos_framing();
	return ;
}
