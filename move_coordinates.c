/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:46:37 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/19 22:58:44 by ekinnune         ###   ########.fr       */
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
int ft_validate_coordinate(t_tetro *tetro, int **grid)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetro->y[i] < 0 || tetro->x[i] < 0)
			return (0);
		if (tetro->y[i] >= GRID_SIZE || tetro->x[i] >= GRID_SIZE)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (grid[tetro->y[i]][tetro->x[i]] == 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_x_and_y_count(t_tetro *tetro, int x, int y,int *x_c, int *y_c)
{
	if (x >= 0)
	{
		if (x > *tetro->x)
			*x_c = *tetro->x - x;
		else
			*x_c = x - *tetro->x;
	}
	if (y >= 0)
	{
		if (y == 0)
			*y_c = y;
		else if (*tetro->y < y)
			*y_c = *tetro->y % y;
		else
			*y_c = y - *tetro->y;
	}
}

/*
**	Some really confusing syntax here might be faster this way
**	     	   *((*tetro)->x + i)
**	 dereference|struct*|int  |i == index on structs int array
**	 to integer |deref  |array|
**
**	ALTERNATIVE: (*tetro)->x[i] 
*/

int	ft_move_coordinate(t_tetro **tetro, int x, int y, int **grid)
{
	int i;
	int x_count;
	int y_count;
	int x_save;
	int y_save;

	i = 0;
	x_count = x - *(*tetro)->x;
	y_count = y - *(*tetro)->y;
	x_save = *(*tetro)->x;
	y_save = *(*tetro)->y;
	while (i < 4)
	{
		*((*tetro)->x + i) += x_count;
		*((*tetro)->y + i) += y_count;
		i++;
	}
	if (ft_validate_coordinate(*tetro, grid))
	{
		return (1);
	}
	ft_move_coordinate(tetro, x_save, y_save, grid);
	return (0);
}
