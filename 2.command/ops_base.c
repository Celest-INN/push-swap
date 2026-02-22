#include "push_swap.h"

int swap_top(t_stack *s)
{
    t_node  *first;
    t_node  *second;
    if (!s || !s->head || !s->head->next)
        return (0);
    first = s->head;
    second = first->next;
    first->next = second->next;
    second->next = first;//结构关系
    s->head = second; //入口更新
    return (1);
}

int push(t_stack *dst, t_stack *src)
{
    t_node  *moved;

    moved = stack_pop_top(src);
    if (!moved)
        return (0) ;
    stack_push_top(dst, moved);
    return (1);
}

int rotate(t_stack *s)
{
    t_node  *first;
    t_node  *last;

    if (!s || !s->head || !s->head->next) 
        return (0);
    first = s->head;
    s->head = first->next;
    last = stack_last(s);
    last->next = first;
    first->next = NULL; 
    return (1);
}

int rev_rotate(t_stack *s)
{
    t_node  *prev;
    t_node  *last;

    if (!s || !s->head || !s->head->next) 
        return (0);
    prev = s->head;
    while (prev->next->next)
    {
        prev = prev->next;
    }
    last = prev->next;
    prev->next = NULL;
    last->next = s->head;//让最后一个节点 Z 的 next 指向原来的头节点 A”//改节点连接
    s->head = last;//改链表入口
    return (1);
}