/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:21:02 by jraty             #+#    #+#             */
/*   Updated: 2020/09/03 06:04:24 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_reading(int fd, int *i, int *l, char *line)
{
	while (get_next_line(fd, &line) == 1)
	{
		*l += 1;
		if (!(*line))
		{
			if (*l % 5 != 0)
				return (0);
		}
		else
		{
			if (ft_strlen(line) != 4)
				return (0);
			*i = 0;
			while (line[*i])
			{
				if (line[*i] != '.' && line[*i] != '#')
					return (0);
				*i += 1;
			}
		}
		free(line);
	}
	return (1);
}

int	ft_checker1(int fd)
{
	char	*line;
	int		i;
	int		l;

	line = NULL;
	l = 0;
	if (!ft_reading(fd, &i, &l, line))
		return (0);
	if ((l + 1) % 5 != 0)
		return (0);
	return (1);
}

int	ft_checker2(int fd)
{
	char	*buf;
	int		ret;
	int		hash;
	int		conn;
	int		i;

	if (!(buf = ft_strnew(21)))
	{
		return (0);
	}
	while ((ret = read(fd, buf, 21)) > 0)
	{
		i = 0;
		hash = 0;
		conn = 0;
		i = ft_check_connect(i, buf, &hash, &conn);
		if (hash != 4)
			return (0);
	}
	if (!(buf[i - 1] == 10 && buf[i] == 0))
		return (0);
	if (conn != 6 && conn != 8)
		return (0);
	free(buf);
	return (1);
}

int	ft_check_connect(int i, char *buf, int *hash, int *conn)
{
	while (buf[i])
	{
		if (buf[i] == '#')
		{
			if (buf[i - 5] == '#')
				(*conn)++;
			if (buf[i + 5] == '#')
				(*conn)++;
			if (buf[i + 1] == '#')
				(*conn)++;
			if (buf[i - 1] == '#')
				(*conn)++;
			(*hash)++;
		}
		i++;
	}
	return (i);
}
