To test moves :

```c
while (stack_a->next != NULL)
{
	printf("%d | ", stack_a->nb);
	printf("%d\n", stack_b->nb);
	stack_a = stack_a->next;
	stack_b = stack_b->next;
	if (stack_a->next == NULL)
	{
		printf("%d | ", stack_a->nb);
		printf("%d\n", stack_b->nb);
	}
}
while (stack_a->previous != NULL)
{
	stack_a = stack_a->previous;
	stack_b = stack_b->previous;
}
printf("\n-------\n\n");
move_sa(&stack_a);
while (stack_a->next != NULL)
{
	printf("%d | ", stack_a->nb);
	printf("%d\n", stack_b->nb);
	stack_a = stack_a->next;
	stack_b = stack_b->next;
	if (stack_a->next == NULL)
	{
		printf("%d | ", stack_a->nb);
		printf("%d\n", stack_b->nb);
	}
}
while (stack_a->previous != NULL)
{
	stack_a = stack_a->previous;
	stack_b = stack_b->previous;
}
```
