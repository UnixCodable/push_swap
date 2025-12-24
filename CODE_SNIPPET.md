To test moves :

```c
while (st_a->next != NULL)
{
	printf("%d | ", st_a->nb);
	printf("%d\n", st_b->nb);
	st_a = st_a->next;
	st_b = st_b->next;
	if (st_a->next == NULL)
	{
		printf("%d | ", st_a->nb);
		printf("%d\n", st_b->nb);
	}
}
while (st_a->previous != NULL)
{
	st_a = st_a->previous;
	st_b = st_b->previous;
}
printf("\n-------\n\n");
sa(&st_a);
while (st_a->next != NULL)
{
	printf("%d | ", st_a->nb);
	printf("%d\n", st_b->nb);
	st_a = st_a->next;
	st_b = st_b->next;
	if (st_a->next == NULL)
	{
		printf("%d | ", st_a->nb);
		printf("%d\n", st_b->nb);
	}
}
while (st_a->previous != NULL)
{
	st_a = st_a->previous;
	st_b = st_b->previous;
}
```
