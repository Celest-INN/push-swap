/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erzhuo <erzhuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 22:41:47 by erzhuo            #+#    #+#             */
/*   Updated: 2026/03/07 22:41:47 by erzhuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack *a)
{
    if(rotate(a))
        write (1, "ra\n", 3);
}

void    rb(t_stack *b)
{
    if(rotate(b))
        write (1, "rb\n", 3);
}

void    rr(t_stack *a, t_stack *b)
{
    int did;
    
    did = 0;
    did |= rotate(a);
    did |= rotate(b);
    if (did)
        write (1, "rr\n", 3);
}
