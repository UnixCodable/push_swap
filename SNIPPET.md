To check that the list's previous and next are working :

```c
while (nbrs->next != NULL)
{
    printf("%d\n", nbrs->nb);
    nbrs = nbrs->next;
    if (nbrs->next == NULL)
        printf("%d\n", nbrs->nb);
}
printf("\n---\n\n");
while (nbrs != NULL)
{
    printf("%d\n", nbrs->nb);
    nbrs = nbrs->previous;
}
```
