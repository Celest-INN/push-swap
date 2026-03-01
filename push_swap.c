#include "push_swap.h"

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
	// TODO: add sorting logic here
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}