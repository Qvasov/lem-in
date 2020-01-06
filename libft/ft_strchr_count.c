#include "libft.h"

int ft_strchr_count(const char *s, int c)
{
	int i;

	i = 0;
	while (*s)
	{
		(*s == c) ? i++ : 1;
		s++;
	}
	return (i);
}
