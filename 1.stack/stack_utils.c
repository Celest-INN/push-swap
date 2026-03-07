/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erzhuo <erzhuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 22:41:47 by erzhuo            #+#    #+#             */
/*   Updated: 2026/03/07 22:41:47 by erzhuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
