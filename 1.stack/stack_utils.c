#include "push_swap.h"

int	stack_is_sorted(t_stack *s)
{
	t_node	*cur;

	if(!s || !s->head || !s->head->next)
		return (1);
	cur = s->head;
	while (cur->next)
	{
		if (cur->v > cur->next->v)	
			return (0);
		cur = cur->next;
	}
	return (1);
}

// 返回栈里最后一个节点
// 如果栈是空的 → 返回 NULL
t_node	*stack_last(t_stack *s)
{
	t_node	*cur;
	
	if (!s || !s->head)
		return (NULL);
	cur = s->head;
	while (cur->next)
	{
		cur = cur->next;
	}
	return (cur);
}
