#include "push_swap.h"

void    index_stack(t_stack *a)
{
    int rank;
    t_node  *current;
    t_node  *compare;

    current = a->head;
    while(current)
    {
        rank = 0;
        compare = a->head;
        while (compare)
        {
            if (compare->raw < current->raw)
                rank++;
            compare = compare->next;
        }
        current->v = rank;
        current=current->next;
    }
}

void    push_all_to_b(t_stack *a, t_stack *b)
{
    pb(a, b);
    pb(a, b);
    while (a->size > 3)
        pb(a, b);
    sort_3(a);
}