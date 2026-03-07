/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erzhuo <erzhuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 22:41:47 by erzhuo            #+#    #+#             */
/*   Updated: 2026/03/07 22:41:47 by erzhuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    index_stack(t_stack *a)
{
	int		rank;
	t_node	*current;
	t_node	*compare;

    current = a->head;
    while(current)
    {
        rank = 0;
        compare = a->head;
        while (compare)
        {
            if (compare->raw < current->raw)
                rank++;
            compare = compare->next;
        }
        current->v = rank;
        current=current->next;
    }
}

/*
** push_all_to_b: 将除了3个元素外的所有元素push到b
** 保留3个在a中用sort_3排序
*/
void	push_all_to_b(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		pb(a, b);
	sort_3(a);
}

/*
** find_target_pos: 找到b中元素应该插入到a中的目标位置
** 规则: 找到a中比b_val大的最小值的位置
** 如果找不到，就放在a中最小值的上面
*/
static int	find_target_pos(t_stack *a, int b_val)
{
	int		pos;
	int		best_pos;
	int		best_val;
	t_node	*n;

	best_pos = 0;
	best_val = INT_MAX;
	pos = 0;
	n = a->head;
	while (n)
	{
		if (n->v > b_val && n->v < best_val)
		{
			best_val = n->v;
			best_pos = pos;
		}
		n = n->next;
		pos++;
	}
	if (best_val == INT_MAX)
		get_min_stack(a, &best_pos); //revoir
	return (best_pos);
}

/*
** calc_cost: 计算将b中某个元素移到a的代价
** cost_a: 旋转a让目标位置到顶的操作数
** cost_b: 旋转b让当前元素到顶的操作数
** 负数表示用reverse rotate，正数表示用rotate
*/
static void	calc_cost(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	int		pos_b;
	int		pos_a;
	t_node	*n;

	pos_b = 0;
	n = b->head;
	while (n)
	{
		pos_a = find_target_pos(a, n->v);
		if (pos_b <= b->size / 2)
			cost_b[pos_b] = pos_b;
		else
			cost_b[pos_b] = pos_b - b->size;
		if (pos_a <= a->size / 2)
			cost_a[pos_b] = pos_a;
		else
			cost_a[pos_b] = pos_a - a->size;
		n = n->next;
		pos_b++;
	}
}

/*
** abs_val: 返回绝对值
*/
static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/*
** find_cheapest: 找到总代价最小的元素索引
** 总代价 = |cost_a| + |cost_b|，但同向旋转可以合并
*/
static int	find_cheapest(int *cost_a, int *cost_b, int size)
{
	int	i;
	int	total;
	int	min_cost;
	int	min_idx;

	min_cost = INT_MAX;
	min_idx = 0;
	i = 0;
	while (i < size)
	{
		if ((cost_a[i] >= 0 && cost_b[i] >= 0)
			|| (cost_a[i] < 0 && cost_b[i] < 0))
		{
			if (abs_val(cost_a[i]) > abs_val(cost_b[i]))
				total = abs_val(cost_a[i]);
			else
				total = abs_val(cost_b[i]);
		}
		else
			total = abs_val(cost_a[i]) + abs_val(cost_b[i]);
		if (total < min_cost)
		{
			min_cost = total;
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

/*
** do_rotations: 执行旋转操作将元素移动到正确位置
*/
static void	do_rotations(t_stack *a, t_stack *b, int ca, int cb)
{
	while (ca > 0 && cb > 0)
	{
		rr(a, b);
		ca--;
		cb--;
	}
	while (ca < 0 && cb < 0)
	{
		rrr(a, b);
		ca++;
		cb++;
	}
	while (ca > 0)
	{
		ra(a);
		ca--;
	}
	while (ca < 0)
	{
		rra(a);
		ca++;
	}
	while (cb > 0)
	{
		rb(b);
		cb--;
	}
	while (cb < 0)
	{
		rrb(b);
		cb++;
	}
}

/*
** push_back_to_a: 将b中元素按最优顺序push回a
** 每次找代价最小的元素，执行旋转后push
*/
static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	*cost_a;
	int	*cost_b;
	int	cheapest;

	cost_a = malloc(sizeof(int) * b->size);
	cost_b = malloc(sizeof(int) * b->size);
	if (!cost_a || !cost_b)
	{
		free(cost_a);
		free(cost_b);
		return ;
	}
	while (b->size > 0)
	{
		calc_cost(a, b, cost_a, cost_b);//int * c'est un tableau
		cheapest = find_cheapest(cost_a, cost_b, b->size);
		do_rotations(a, b, cost_a[cheapest], cost_b[cheapest]);
		pa(a, b);
	}
	free(cost_a);
	free(cost_b);
}

/*
** final_rotate: 最终旋转让最小值在栈顶
*/
static void	final_rotate(t_stack *a)
{
	int	min_pos;

	get_min_stack(a, &min_pos);
	if (min_pos <= a->size / 2)
	{
		while (min_pos-- > 0)//-- apres min_pos ==> condition while() d'abord
			ra(a);
	}
	else
	{
		min_pos = a->size - min_pos;
		while (min_pos-- > 0)
			rra(a);
	}
}

/*
** turkish_sort: Turkish算法主函数
** 步骤:
** 1. index_stack: 标准化数值为0~n-1
** 2. push_all_to_b: 把元素push到b，保留3个在a排序
** 3. push_back_to_a: 按最优代价把b元素push回a
** 4. final_rotate: 旋转让最小值在顶
*/
void	turkish_sort(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 3)
		return ;
	index_stack(a);
	push_all_to_b(a, b);
	push_back_to_a(a, b);
	final_rotate(a);
}
