/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordanave <lbordanave@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:41:52 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/26 03:38:08 by lbordanave       ###   ########.fr       */
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
	x = 0;
	ft_printf("\e[%d;%dH╔", x, y++);
	while (y != 80)
		ft_printf("\e[%d;%dH═", x, y++);
	ft_printf("\e[%d;%dH╗", x++, y);
	while (++x != 29)
		ft_printf("\e[%d;%dH║\e[%d;%dH║", x, y, x, 1);
	y = 1;
	ft_printf("\e[%d;%dH╠\e[%d;%dH╠\e[%d;%dH╚", 9, y, 26, y, 29, y);
	while (++y != 80)
		ft_printf("\e[%d;%dH═\e[%d;%dH═\e[%d;%dH═", 9, y, 26, y, 29, y);
	ft_printf("\e[%d;%dH╣\e[%d;%dH╣\e[%d;%dH╝", 9, y, 26, y, 29, y);
	y = 1;
	x = 9;
	while (++x != 26)
		ft_printf("\e[%d;%dH║\e[%d;%dH║\e[%d;%dH\n", x, 25, x, 56, 29 ,80);
	return ;
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
