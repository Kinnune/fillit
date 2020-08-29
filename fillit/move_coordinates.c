/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:46:37 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/28 22:34:36 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**				*((*tetro)->x + i)
**	ALTERNATIVE: (*tetro)->x[i] 
*/

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
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (grid[*(tetro->y + i)][*(tetro->x + i)] == 1)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_move_coordinate(t_tetro **tetro, int x, int y, int **grid)
{
	int i;
	int x_count;
	int y_count;

	i = 0;
	x_count = x - *(*tetro)->x;
	y_count = y - *(*tetro)->y;
	while (i < 4)
	{
		*((*tetro)->x + i) += x_count;
		*((*tetro)->y + i) += y_count;
		i++;
	}
}

t_tetro	*ft_reset_coordinates(t_tetro **tetro, int **grid)
{
	t_tetro *head;

	while ((*tetro)->prev)
	{
		(*tetro) = (*tetro)->prev;
	}
	head = *tetro;
	while((*tetro))
	{
		ft_move_coordinate(tetro,  -1, 0, grid);
		(*tetro) = (*tetro)->next;
	}
	return (head);
}

int	ft_move_1(t_tetro **tetro, int **grid, int size)
{
	while (*(*tetro)->y <= size)
	{
		ft_move_coordinate(tetro, *(*tetro)->x + 1, *(*tetro)->y, grid);
		if (ft_validate_coordinate(*tetro, grid, size))
		{
			return (1);
		}
		if (*(*tetro)->x >= size)
		{
			ft_move_coordinate(tetro, 0, *(*tetro)->y + 1, grid);
			if (ft_validate_coordinate(*tetro, grid, size))
			{
				return (1);
			}
		}
	}
	return (0);
}

int i = 0;


void	ft_recursive(t_tetro **tetro, int **grid, int grid_size)
{
//printf("(%c)", 'A' + (*tetro)->letter);
	ft_move_1(tetro, grid, grid_size);
	if (ft_validate_coordinate(*tetro, grid, grid_size))
	{
ft_putstr("flip current\n");
		ft_flip_grid(*tetro, grid);
		if ((*tetro)->next)
			ft_recursive(&(*tetro)->next, grid, grid_size);
	}
	else if (!(*tetro)->prev)
	{
		grid = ft_make_grid(grid, ++grid_size);
		ft_move_coordinate(tetro, -1, 0, grid);
		ft_recursive(tetro, grid, grid_size);
	}
	else
	{

		ft_move_coordinate(tetro, -1, 0, grid);
ft_putstr("flip prev\n");
		ft_flip_grid((*tetro)->prev, grid);
		ft_recursive(&(*tetro)->prev, grid, grid_size);

	}
}
