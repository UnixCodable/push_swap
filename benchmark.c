/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:41:52 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/27 00:45:08 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_numbers(t_nlist **sorted)
{
	t_nlist	*voyager;
	int		x;
	int		y;

	x = 11;
	voyager = *sorted;
	while (x != 20)
	{
		y = 28;
		ft_printf(POS, x, y);
		while (y < 52 && voyager)
		{
			y += ft_numlen(voyager->nb) + 1;
			if (y < 55)
			{
				ft_printf("%d-", voyager->nb);
				voyager = voyager->next;
			}
		}
		x++;
	}
}

void	pos_framing(void)
{
	int	x;
	int	y;

	y = 1;
	x = 1;
	ft_printf("\e[2J\e[H\e[1;32m\n\n\
   ██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ \n\
   ██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗\n\
   ██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝\n\
   ██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ \n\
   ██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║     \n\
   ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     \n\
  ");
	ft_printf(POS"╔"POS"╗"POS"╚"POS"╝", 0, 1, 0, 80, 23, 1, 23, 80);
	while (++y != 80)
		ft_printf(POS"═"POS"═"POS"═"POS"═", 0, y, 9, y, 21, y, 23, y);
	while (++x != 23)
		ft_printf(POS"║"POS"║", x, 1, x, 80);
	x = 9;
	ft_printf(POS"╦"POS"╦"POS"╩"POS"╩", 9, 25, 9, 56, 21, 25, 21, 56);
	while (++x != 21)
		ft_printf(POS"║"POS"║", x, 25, x, 56);
	ft_printf(POS"╣"POS"╣"POS"╠"POS"╠", 9, 80, 21, 80, 9, 1, 21, 1);
	ft_printf(POS" BENCHMARK "POS" GLOBAL ", 0, 35, 9, 9);
	ft_printf(POS" DETAIL "POS" FIRST SORTED ", 9, 65, 9, 34);
}

void	strategy_definition(struct s_data *data)
{
	if (data->force_simple == 1)
		ft_printf(POS"[Strategy] :"POS"Simple / O(n²)", 17, 3, 18, 3);
	else if (data->force_medium == 1)
		ft_printf(POS"[Strategy] :"POS"Medium / O(n√n)", 17, 3, 18, 3);
	else if (data->force_complex == 1)
		ft_printf(POS"[Strategy] :"POS"Complex / O(n log n)", 17, 3, 18, 3);
	else if (data->disorder < 0.2)
		ft_printf(POS"[Strategy] :"POS"Adaptive / O(n)", 17, 3, 18, 3);
	else if (data->disorder >= 0.2 && data->disorder < 0.5)
		ft_printf(POS"[Strategy] :"POS"Adaptive / O(n√n)", 17, 3, 18, 3);
	else
		ft_printf(POS"[Strategy] :"POS"Adaptive / O(n log n)", 17, 3, 18, 3);
}

void	data_place(struct s_data *data)
{
	int	disorder;

	disorder = (int)(data->disorder * 10000);
	ft_printf(POS"[PA]  : %d", 10, 58, data->pa_count);
	ft_printf(POS"[PB]  : %d", 11, 58, data->pb_count);
	ft_printf(POS"[SA]  : %d", 12, 58, data->sa_count);
	ft_printf(POS"[SB]  : %d", 13, 58, data->sb_count);
	ft_printf(POS"[SS]  : %d", 14, 58, data->ss_count);
	ft_printf(POS"[RA]  : %d", 15, 58, data->ra_count);
	ft_printf(POS"[RB]  : %d", 16, 58, data->rb_count);
	ft_printf(POS"[RR]  : %d", 17, 58, data->rr_count);
	ft_printf(POS"[RRA] : %d", 18, 58, data->rra_count);
	ft_printf(POS"[RRB] : %d", 19, 58, data->rrb_count);
	ft_printf(POS"[RRR] : %d", 20, 58, data->rrr_count);
	ft_printf(POS"Made with ♥ by aeuvrard \
and lbordana, from 42 Mulhouse.", 22, 12);
	ft_printf(POS"[Disorder] : %d.%d%%", 11, 3, disorder / 100, disorder % 100);
	ft_printf(POS"[Total OPS] : %d", 13, 3, data->total_count);
	ft_printf(POS"[Total NB] : %d", 15, 3, data->number_count);
	strategy_definition(data);
	ft_printf(POS"\n", 23, 80);
}

void	compute_benchmark(struct s_data *data, t_nlist **sorted)
{
	if (data->benchmark == 0)
		return ;
	pos_framing();
	first_numbers(sorted);
	data_place(data);
	return ;
}
