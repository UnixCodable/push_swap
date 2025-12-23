#include "push_swap.h"

void	testing(t_num_list **stack_a, t_num_list **stack_b, struct s_data *data)
{
	while ((*stack_a)->next || (*stack_b)->next)
	{
		if ((*stack_a))
			(*stack_a) = (*stack_a)->next;
		if ((*stack_b))
			(*stack_b) = (*stack_b)->next;
		if ((*stack_a))
			printf("%d", (*stack_a)->nb);
		else
			printf("-");
		if ((*stack_b))
			printf("%d", (*stack_b)->nb);
		else
			printf("-");
	}
}
