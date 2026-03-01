#include "push_swap.h"

void	*free_split(char **result)
{
	int	i;

	if (!result)
		return (NULL);
	i = 0;
	while (result[i])
	{
		free (result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		if (len)
		{
			result[i] = ft_substr(s, 0, len);
			if (!result[i++])
				return (free_split(result));
		}
		s = s + len;
	}
	result[i] = NULL;
	return (result);
}