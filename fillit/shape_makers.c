/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_makers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:30:41 by ekinnune          #+#    #+#             */
/*   Updated: 2020/09/03 00:28:54 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_single_shapes(char *f_content)
{
	char	**shape_list;
	int		shape_count;
	int		i;
	int		sub_i;

	i = 0;
	sub_i = 0;
	shape_count = ft_count_words(f_content, '\n') / 4;
	shape_list = (char **)malloc(sizeof(char *) * shape_count + 1);
	while (i < shape_count)
	{
		shape_list[i] = ft_strsub(f_content, sub_i, 20);
		i++;
		sub_i += 21;
	}
	*(shape_list + i) = 0;
	return (shape_list);
}

char	**ft_file_save(int fd, char **argv)
{
	size_t	f_size;
	char	*file;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		return (NULL);
	}
	f_size = ft_file_size(fd);
	file = ft_strnew(f_size);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		return (NULL);
	}
	read(fd, file, f_size);
	return (ft_single_shapes(file));
}
