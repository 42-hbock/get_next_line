#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int			ft_strlen(char *s);
char		*ft_strcpy(char *dst, char *src);
char		*ft_strcat(char *s, char *to_add);
char		*ft_strncat(char *s, char *to_add, int n);
char		*ft_strchr(const char *s, int c);
int			ft_strlen_chr(char *s, char c);
char		*ft_strncpy(char *dst, char *src, int n);

#endif