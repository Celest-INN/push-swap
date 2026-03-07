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

int	get_min_stack(t_stack *s, int *min_i)
{
	int		min_val;
	int		i;
	t_node	*n;

	if (!s || !s->head || !min_i)
		return (0);
	min_val =s->head->v;
	*min_i = 0;
	n = s->head->next;
	i = 1;
	while (n)
	{
		if(min_val > n->v)
		{
			min_val = n->v;
			*min_i = i;
		}
		n = n->next;
		i++;
	}
	return (min_val);
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
	int	max_i;
	int	max_val;

	if (!a || a->size != 3)
		return ;
	max_val = get_max_stack(a, &max_i);
	if (max_i == 0)
		ra(a);
	else if (max_i == 1)
		rra(a);
	if (a->head->v > a->head->next->v)
		sa(a);
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	min_i;

	if (!a || a->size != 4)
		return ;
	get_min_stack(a, &min_i);
	if (min_i == 1)
		ra(a);
	else if (min_i == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_i == 3)
		rra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}
