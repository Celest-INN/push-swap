#include "push_swap.h"

int	parse_args(int argc, char **argv, t_stack *a)
{
	int		total;
	int		*arr;
	int		i;
	t_node	*node;

	if (argc < 2)
		return (0);
	total = count_all_args(argc, argv);
	if (total <= 0)
		return (0);
	arr = (int *)malloc(sizeof(int) * total);
	if (!arr)
		return (0);
	if (!fill_array(argc, argv, arr))
		return (free(arr), 0);
	if (has_duplicate(arr, total))
		return (free(arr), 0);
	i = total - 1;
	while (i >= 0)
	{
		node = node_new(arr[i], arr[i]);
		if (!node)
			return (free(arr), stack_clear(a), 0);
		stack_push_top(a, node);
		i--;
	}
	return (free(arr), 1);
}
