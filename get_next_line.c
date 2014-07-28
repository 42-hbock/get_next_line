#include "get_next_line.h"
int					add_buff(char **dst, char *to_add)
{
	int				len_dst;
	int				len_to_add;
	char			*tmp;

	len_dst = ft_strlen(*dst);
	len_to_add = ft_strlen_chr(to_add, '\n');
	if (!(tmp = (char *)malloc(sizeof(char) * (len_dst + 1))))
		return (-1);
	tmp = ft_strcpy(tmp, *dst);
	if (!(*dst = (char *)malloc(sizeof(char) * (len_dst + len_to_add + 1))))
	{
		free (tmp);
		return (-1);
	}
	*dst = ft_strcpy(*dst, tmp);
	free (tmp);
	*dst = ft_strncat(*dst, to_add, len_to_add);
	if (to_add[len_to_add])
		return (to_add[len_to_add + 1]) ? len_to_add + 1: 0;
	return (0);
}

int					fill_rest_line(char **rest, char *buff, int start)
{
	int				len_rest;

	len_rest = ft_strlen(buff + start);
	if (!(*rest = (char *)malloc(sizeof(char) * (len_rest + 1))))
		return (-1);
	*rest = ft_strcpy(*rest, buff + start);
	return (0);
}

int					isend_file(char **rest, int len_to_add)
{
	if (!((*rest)[len_to_add]))
	{
		free(*rest);
		return (1);
	}
	else
	{
		if (!((*rest)[len_to_add + 1]))
		{
			free(*rest);
			return (1);
		}
	}
	return (0);
}

int					manage_rest_line(char **rest, char **line)
{
	int				len_to_add;
	int				i;
	int				j;

	len_to_add = ft_strlen_chr(*rest, '\n');
	if (!(*line = (char *)malloc(sizeof(char) * (len_to_add + 1))))
		return (-1);
	*line = ft_strncpy(*line, *rest, len_to_add);
	if (isend_file(rest, len_to_add))
		return (0);
	i = -1;
	while (++i < (len_to_add + 1))
	{
		j = -1;
		while ((*rest)[++j])
			(*rest)[j] = (*rest)[j + 1];
	}
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static	char	*rest_line;
	char			*buff;
	int				nread;
	int				next_start;
	int				ret_man;

	if (rest_line)
		if ((ret_man = manage_rest_line(&rest_line, line)))
			return (ret_man);
	buff = (char *)malloc(sizeof(char) * (BUFF + 1));
	if (!(*line))
	{

		*line = (char *)malloc(sizeof(char));
		(*line)[0] = 0;
	}
	next_start = 0;
	while ((nread = read(fd, buff, BUFF)) && nread != -1 && !next_start)
	{
		buff[nread] = 0;
		if ((next_start = add_buff(line, buff)) == -1)
		{
			free (buff);
			return (-1);
		}
	}
	if (next_start > 0)
		return (fill_rest_line(&rest_line, buff, next_start) == -1) ? -1 : 1;
	return (0);
}
