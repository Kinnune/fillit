/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:46:37 by ekinnune          #+#    #+#             */
/*   Updated: 2020/09/02 20:46:19 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**				*((*tetro)->x + i)
**	ALTERNATIVE:  (*tetro)->x[i] 
*/

 

/*
int ft_validate_coordinate(t_tetro *tetro, int **grid, int grid_size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (*(tetro->y + i) < 0 || *(tetro->x + i) < 0
			|| *(tetro->y + i) >= grid_size || *(tetro->x + i) >= grid_size)
		{
			return (0);
		}
		if (*(*(grid + *(tetro->y + i)) + *(tetro->x + i)) == 1)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
*/

int ft_validate_coordinate(t_tetro *tetro, int **grid, int grid_size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetro->y[i] < 0 || tetro->x[i] < 0
			|| tetro->y[i] >= grid_size || tetro->x[i] >= grid_size)
		{
			return (0);
		}
		if (grid[tetro->y[i]][tetro->x[i]] == 1)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
**	int i = 0;
**	while (i < 4)
**	{
**		*((*tetro)->x + i) += x_count;
**		*((*tetro)->y + i) += y_count;
**		i++;
**	}
*/

void	ft_move_coordinate(t_tetro **tetro, int x, int y)
{
	int x_count;
	int y_count;

	x_count = x - *(*tetro)->x;
	y_count = y - *(*tetro)->y;
	*(*tetro)->x += x_count;
	*((*tetro)->x + 1) += x_count;
	*((*tetro)->x + 2) += x_count;
	*((*tetro)->x + 3) += x_count;
	*(*tetro)->y += y_count;
	*((*tetro)->y + 1) += y_count;
	*((*tetro)->y + 2) += y_count;
	*((*tetro)->y + 3) += y_count;
}

//30

int		ft_iterative_solve(t_tetro **tetro, int **grid, int grid_size)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (*tetro)
	{
		ft_move_coordinate(tetro, x, y);
		if (ft_validate_coordinate(*tetro, grid, grid_size) != 0)
		{
			ft_flip_grid(*tetro, grid);
			ft_tetro_next(tetro, &x, &y);
		}
		else if (++x >= grid_size)
			ft_start_new_line(&x, &y);
		if (y >= grid_size && (*tetro)->prev == NULL)
		{
			ft_grid_bigger(&grid_size, &x, &y);
}
		else if (y >= grid_size)
		{
			ft_tetro_prev(tetro, &x, &y);
			ft_flip_grid(*tetro, grid);
		}
	}
	return (grid_size);
}
