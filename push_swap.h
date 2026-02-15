#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*Node arch*/
typedef struct s_stack
{
	int				value;
	int				index;
	int				push_price;
	int				median_sup;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

/*stack*/


/*command*/
void				pa(t_stack **a, t_stack **b, int bool);
void				pb(t_stack **a, t_stack **b, int bool);
void				rra(t_stack **a, int bool);
void				rrb(t_stack **b, int bool);
void				rrr(t_stack **a, t_stack **b, int bool);
void				ra(t_stack **a, int bool);
void				rb(t_stack **b, int bool);
void				rr(t_stack **a, t_stack **b, int bool);
void				sa(t_stack **a, int bool);
void				sb(t_stack **b, int bool);
void				ss(t_stack **a, t_stack **b, int bool);

#endif