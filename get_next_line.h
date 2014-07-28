#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF 4096

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

int			get_next_line(int const fd, char ** line);

#endif