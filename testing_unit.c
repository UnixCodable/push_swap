#include "push_swap.h"

void	testing(t_nlist **st_a, t_nlist **st_b, struct s_data *data)
{
	(void) data;
	/*PREMIERE IMPRESSION*/
	while (((*st_a) && (*st_a)->next != NULL)|| ((*st_b) && (*st_b)->next != NULL))
	{
		if ((*st_a))
			printf("%d | ", (*st_a)->nb);
		else
			printf("-");
		if ((*st_b))
			printf(" %d\n", (*st_b)->nb);
		else
			printf("-\n");
		if ((*st_a) && (*st_a)->next)
		{
			(*st_a) = (*st_a)->next;
			if ((*st_a)->next == NULL)
			{
				printf("%d | ", (*st_a)->nb);
				if (!(*st_b))
					printf("-\n");
			}
		}
		if ((*st_b) && (*st_b)->next)
		{
			(*st_b) = (*st_b)->next;
			if ((*st_b)->next == NULL)
			{
				if (!(*st_a))
					printf("-");
				printf("%d\n", (*st_a)->nb);
			}
		}
	}
	/*REMONTAGE*/
	while (((*st_a) && (*st_a)->previous != NULL) || ((*st_b) && (*st_b)->previous != NULL))
	{
		if (*st_a)
			*st_a = (*st_a)->previous;
		if (*st_b)
			*st_b = (*st_b)->previous;
	}
	printf("\n--------\n\n");
	exec_sort(st_a, st_b, data);
	while (((*st_a) && (*st_a)->next != NULL)|| ((*st_b) && (*st_b)->next != NULL))
	{
		if ((*st_a))
			printf("%d | ", (*st_a)->nb);
		else
			printf("-");
		if ((*st_b))
			printf(" | %d\n", (*st_b)->nb);
		else
			printf("-\n");
		if ((*st_a) && (*st_a)->next)
		{
			(*st_a) = (*st_a)->next;
			if ((*st_a)->next == NULL)
			{
				printf("%d | ", (*st_a)->nb);
				if (!(*st_b))
					printf("-\n");
			}
		}
		if ((*st_b) && (*st_b)->next)
		{
			(*st_b) = (*st_b)->next;
			if ((*st_b)->next == NULL)
			{
				if (!(*st_a))
					printf("-");
				printf(" | %d\n", (*st_b)->nb);
			}
		}
	}
	/*REMONTAGE*/
	while (((*st_a) && (*st_a)->previous != NULL) || ((*st_b) && (*st_b)->previous != NULL))
	{
		if (*st_a)
			*st_a = (*st_a)->previous;
		if (*st_b)
			*st_b = (*st_b)->previous;
	}
}
