#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h> // malloc, NUll
# include <unistd.h> // write

/*Node arch*/
typedef struct s_node
{
	int				v;
	int				raw;
	struct s_node	*next;
} 	t_node;

/*stack*/
typedef struct s_stack
{
	t_node	*head;
	int		size;	
}	t_stack;

/* stack_init.c */
void	stack_init(t_stack *s);
t_node	*node_new(int v, int raw);

/* stack_push_pop.c */
void	stack_push_top(t_stack *s, t_node *n);
t_node	*stack_pop_top(t_stack *s);

/* stack_free.c */
void	stack_clear(t_stack *s);

/* stack_utils.c */
int	stack_is_sorted(t_stack *s);
t_node	*stack_last(t_stack *s);

/* stack_debug.c */

/* ops_base.c */
int	swap_top(t_stack *s);
int	push(t_stack *dst, t_stack *src);
int	rotate(t_stack *s);
int	rev_rotate(t_stack *s);

/* cmd x 4 */
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);

void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);

void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);

void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

#endif