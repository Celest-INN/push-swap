#include "push_swap.h"
//从头开始 保存 next
//free 当前
//跳到 next 重复直到 NULL
void	stack_clear(t_stack *s)
{
	t_node	*cur;
	t_node	*next;

	if (!s || !s->head)
		return ;
	cur = s->head;
	while (cur)
	{
		next = cur->next;
		free(cur);//一旦 free 掉当前节点： 你就再也访问不了 cur->next
		//所以在上一步先保存
		cur = next;
	}
	s->head = NULL;
	s->size = 0;
}