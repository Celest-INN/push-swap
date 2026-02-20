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



#endif