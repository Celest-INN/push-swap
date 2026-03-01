#include "push_swap.h"

int	is_number(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atol_safe(const char *s, long *result)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && -num < INT_MIN))
			return (0);
		i++;
	}
	*result = num * sign;
	return (1);
}

int	has_duplicate(int *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	count_all_args(int argc, char **argv)
{
	int		count;
	int		i;
	char	**split;
	int		j;

	count = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		free_split(split);
		i++;
	}
	return (count);
}

int	fill_array(int argc, char **argv, int *arr)
{
	int		idx;
	int		i;
	char	**split;
	int		j;
	long	num;

	idx = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			if (!is_number(split[j]) || !ft_atol_safe(split[j], &num))
				return (free_split(split), 0);
			arr[idx++] = (int)num;
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}