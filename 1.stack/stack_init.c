// stack_init 把一个未定义的 stack 变成一个干净的空栈
#include "push_swap.h"

void	stack_init(t_stack *s)
{
	if (!s)
		return ;
	s->head = NULL;
	s->size = 0;
}

// 返回值t_node *意味着这个函数会返回一个 节点的地址
// 在堆上创建一个新的链表节点，并返回它的地址
t_node	*node_new(int v, int raw)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
// 在堆上申请一块足够放一个 t_node 的内存
// 让指针 n 指向新分配的那块 node 内存
	if (!n)
		return (NULL);
	n->v = v;
	n->raw = raw;
	n->next = NULL;
	return (n);
}
