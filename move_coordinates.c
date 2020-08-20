/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:46:37 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/20 19:28:50 by ekinnune         ###   ########.fr       */
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
	if (!(ft_validate_coordinate(*tetro, grid)))
	{
//		ft_move_coordinate(tetro, x_save, y_save, grid);
		return (0);
	}
	return (1);
}

int	**ft_place_block(t_tetro *s_tetro, int **grid)
{
	int x = 0;
	int y = 0;
	int i = 0;
	t_tetro *head;

	head = s_tetro;
	while (s_tetro != NULL)
	{
		printf("loop#%d x = %d y = %d\n", i, x , y);
		if (ft_move_coordinate(&s_tetro, x, y, grid))
		{
			ft_flip_grid(s_tetro, grid);
			s_tetro = s_tetro->next;
			x = 0;
			y = 0;
		}
		else
		{
					ft_puterr(1);

			x++;
		}
		
		ft_puterr(2);
		if (x == GRID_SIZE)
		{
			x = 0;
			y++;
		}
		
		ft_puterr(3);
		if (y == GRID_SIZE)
		{
			
		ft_puterr(4);
			GRID_SIZE++;
			grid = ft_make_grid(grid);
			s_tetro = head;
			y = 0;
		}
		
		ft_puterr(5);
		i++;
	}
	return (grid);
}