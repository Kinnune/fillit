/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:06:20 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/17 20:04:20 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set_coordinates(t_tetro **element)
{
	char	*str;
	int		y;
	int		x;
	int		i;
	int		block_count;

	y = 0;
	x = y;
	i = x;
	block_count = i;
	str = (*element)->raw;
	while(str[i])
	{
		if (str[i] == '#')
		{
			x = (i - y) % 4;
			(*element)->x[block_count] = x;
			(*element)->y[block_count++] = y;
		}
		if (str[i] == '\n')
			y++;
		i++;
	}
}

t_tetro	*new_tetro(char *tetro, t_tetro *previous, int i)
{
	t_tetro *new;

	new = (t_tetro *)malloc(sizeof(t_tetro));
	new->letter = i;
	new->raw = tetro;
	new->next = NULL;
	new->prev = previous;
	ft_set_coordinates(&new);
	return (new);
}

t_tetro	*ft_process_raw(char **raw)
{
	t_tetro *head;
	t_tetro	*copy;
	size_t	i;

	i = 0;
	head = new_tetro(raw[i], NULL, i);
	copy = head;
	while (raw[++i])
	{
		copy->next = new_tetro(raw[i], copy, i);
		copy = copy->next;
	}
	return (head);
}