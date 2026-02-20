#include "push_swap.h"

//目标：把新节点 n 插到栈顶
void	stack_push_top(t_stack *s, t_node *n)
{
	if (!n || !s)
		return ;
	n->next = s->head; //让新节点 n 指向当前栈顶 //① 接上旧链
	//如果栈是空的，s->head == NULL，这行也完全 OK。
	s->head = n; //更新栈顶：现在 n 成为新的 head（top）。// ② 更新头
	s->size++;
}
//从栈顶取出一个节点, 返回该节点的地址, 如果取不出来返回 NULL
t_node	*stack_pop_top(t_stack *s)
{
	t_node	*n;

	if (!s || !s->head)
		return (NULL);
	n = s->head;//n 指向原来的栈顶节点。
	s->head = s->head->next;//栈顶后移一位（原第二个变成新的 top）
	//s->head 是一个 node 指针 
	//每个 node 里有：struct s_node *next;
	//所以s->head->next意思是：栈顶节点的下一个节点的地址
	n->next = NULL;
	s->size--;
	return (n);
}
