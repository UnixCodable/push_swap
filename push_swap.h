/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordana <lbordana@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 07:12:03 by lbordanave        #+#    #+#             */
/*   Updated: 2025/12/20 14:58:26 by lbordana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_num_list
{
	int				nb;
	struct s_list	*previous;
	struct s_list	*next;
}	t_num_list;

#endif
