#include "push_swap.h"

int	get_max_stack(t_stack *s, int *max_i)
{
	int		max_val;
	int		i;
	t_node	*n;

	if (!s || !s->head || !max_i)
		return (0);
	max_val =s->head->v;
	*max_i = 0;
	n = s->head->next;
	i = 1;
	while (n)
	{
		if(max_val < n->v)
		{
			max_val = n->v;
			*max_i = i;
		}
		n = n->next;
		i++;
	}
	return (max_val);
}


void	sort_2(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	if (a->head->v > a->head->next->v)
		sa(a);
}

void	sort_3(t_stack *a)
{
	int		a1;
	int		a2;
	int		a3;
	t_node	*n;

	if (!a || a->size != 3)
		return ;
	n = a->head;
	a1 = n->v;
	a2 = n->next->v;
	a3 = n->next->next->v;
	if (a1 < a2 && a2 < a3 && a1 < a3)
		sa(a);

}