#include "push_swap.h"

void sa(t_stack *a)
{
    if (swap_top(a))
        write (1, "sa\n", 3);
}

void sb(t_stack *b)
{
    if (swap_top(b))
        write (1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b)
{
    int did;
    did = 0;
    did |= swap_top(a);//bitwise OR assign
    did |= swap_top(b);
    if (did)
        write (1, "ss\n", 3);
}