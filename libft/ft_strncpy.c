#include "includes/libft.h"

char		*ft_strncpy(char *dst, char *src, int n)
{
	int		i;

	i =-1;
	while (src[++i] && i < n)
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}
