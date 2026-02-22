#include "push_swap.h"

void    rra(t_stack *a)
{
    if(rev_rotate(a))
        write (1, "rra\n", 4);
}


void    rrb(t_stack *b)
{
    if(rev_rotate(b))
        write (1, "rrb\n", 4);
}

void    rrr(t_stack *a, t_stack *b)
{
    int did;
    
    did = 0;
    did |= rev_rotate(a);
    did |= rev_rotate(b);
    if (did)
        write (1, "rrr\n", 4);
}