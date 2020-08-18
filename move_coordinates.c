/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:46:37 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/18 16:59:09 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
t_tetro	*ft_change_coordinates(t_tetro **tetro, char **board, int x_max,int y_max)
{
	int i;
	int j;

	i = 0;
	j = 0;
//	im moving coordiantes to somewhere
	if (ft_validate_coordinate())
		return ();
	else
	{
		tetro->x[0] + 1;
		if (i > x_max)
		{
			x = 0;
			j++;
		}
		if (j > y_max)
			return (make grid bigger)
		ft_change_coordinates()

	}
}
*/


int ft_validate_coordinate(t_tetro *tetro)
{
	if (tetro->x[0] < 0)
		return (0);
	if (tetro->x[1] < 0)
		return (0);
	if (tetro->x[2] < 0)
		return (0);
	if (tetro->x[3] < 0)
		return (0);

	if (tetro->y[0] < 0)
		return (0);
	if (tetro->y[1] < 0)
		return (0);
	if (tetro->y[2] < 0)
		return (0);
	if (tetro->y[3] < 0)
		return (0);
	else
		return (1);
}

int	ft_move_coordinate(t_tetro **tetro, int x, int y)
{
	if (x != 0)
	{
		(*tetro)->x[0] += x;
		(*tetro)->x[1] += x;
		(*tetro)->x[2] += x;
		(*tetro)->x[3] += x;
	}
	if (y != 0)
	{
		(*tetro)->y[0] += y;
		(*tetro)->y[1] += y;
		(*tetro)->y[2] += y;
		(*tetro)->y[3] += y;
	}
//	maybe broken
	if (ft_validate_coordinate(*tetro))
	{
		return (1);
	}
	ft_move_coordinate(tetro, -x, -y);
	return (0);
}