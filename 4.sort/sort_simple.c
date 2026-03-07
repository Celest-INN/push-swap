/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erzhuo <erzhuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 22:41:47 by erzhuo            #+#    #+#             */
/*   Updated: 2026/03/07 22:41:47 by erzhuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (!a || a->size != 3)
		return ;
	get_max_stack(a, &max_i);
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

