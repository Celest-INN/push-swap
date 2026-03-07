/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erzhuo <erzhuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 22:41:47 by erzhuo            #+#    #+#             */
/*   Updated: 2026/03/07 22:41:47 by erzhuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push_swap: 主排序调度函数
** 根据元素数量选择最优的排序策略:
** - 2个元素: 简单比较交换
** - 3个元素: 最多2步操作
** - 4个元素: push最小到b，排序3个，push回来
** - 5个以上: Turkish算法
*/
void	push_swap(t_stack *a, t_stack *b)
{
	if (!a || a->size < 2 || stack_is_sorted(a))
		return ;
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else
		turkish_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	stack_init(&a);
	stack_init(&b);
	if (!parse_args(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	push_swap(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
