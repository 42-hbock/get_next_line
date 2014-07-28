#include "includes/libft.h"

char		*ft_strncat(char *s, char *to_add, int n)
{
	int		start;
	int		i;

	start = ft_strlen(s);
	i = -1;
	while (to_add[++i] && i < n)
		s[start + i] = to_add[i];
	s[start + i] = 0;
	return (s);
}
