#include "push_swap.h"

void	testing(t_num_list **stack_a, t_num_list **stack_b, struct s_data *data)
{
	(void) data;
	/*PREMIERE IMPRESSION*/
	while (((*stack_a) && (*stack_a)->next != NULL)|| ((*stack_b) && (*stack_b)->next != NULL))
	{
		if ((*stack_a))
			printf("%d | ", (*stack_a)->nb);
		else
			printf("-");
		if ((*stack_b))
			printf(" %d\n", (*stack_b)->nb);
		else
			printf("-\n");
		if ((*stack_a) && (*stack_a)->next)
		{
			(*stack_a) = (*stack_a)->next;
			if ((*stack_a)->next == NULL)
			{
				printf("%d | ", (*stack_a)->nb);
				if (!(*stack_b))
					printf("-\n");
			}
		}
		if ((*stack_b) && (*stack_b)->next)
		{
			(*stack_b) = (*stack_b)->next;
			if ((*stack_b)->next == NULL)
			{
				if (!(*stack_a))
					printf("-");
				printf("%d\n", (*stack_a)->nb);
			}
		}
	}
	/*REMONTAGE*/
	while (((*stack_a) && (*stack_a)->previous != NULL) || ((*stack_b) && (*stack_b)->previous != NULL))
	{
		if (*stack_a)
			*stack_a = (*stack_a)->previous;
		if (*stack_b)
			*stack_b = (*stack_b)->previous;
	}
	printf("\n--------\n\n");
	move_pb(stack_a, stack_b, data);
	move_pb(stack_a, stack_b, data);
	move_pb(stack_a, stack_b, data);
	move_rrb(stack_b, data);
	while (((*stack_a) && (*stack_a)->next != NULL)|| ((*stack_b) && (*stack_b)->next != NULL))
	{
		if ((*stack_a))
			printf("%d | ", (*stack_a)->nb);
		else
			printf("-");
		if ((*stack_b))
			printf(" | %d\n", (*stack_b)->nb);
		else
			printf("-\n");
		if ((*stack_a) && (*stack_a)->next)
		{
			(*stack_a) = (*stack_a)->next;
			if ((*stack_a)->next == NULL)
			{
				printf("%d | ", (*stack_a)->nb);
				if (!(*stack_b))
					printf("-\n");
			}
		}
		if ((*stack_b) && (*stack_b)->next)
		{
			(*stack_b) = (*stack_b)->next;
			if ((*stack_b)->next == NULL)
			{
				if (!(*stack_a))
					printf("-");
				printf(" | %d\n", (*stack_b)->nb);
			}
		}
	}
	/*REMONTAGE*/
	while (((*stack_a) && (*stack_a)->previous != NULL) || ((*stack_b) && (*stack_b)->previous != NULL))
	{
		if (*stack_a)
			*stack_a = (*stack_a)->previous;
		if (*stack_b)
			*stack_b = (*stack_b)->previous;
	}
}
