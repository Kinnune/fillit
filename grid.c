/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:47:05 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/20 18:57:32 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	**ft_flip_grid(t_tetro *tetro, int **grid)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		grid[tetro->y[i]][tetro->x[i]] = 1;
		i++;
	}
	return (grid);
}

int	**ft_reset_grid(int **grid)
{
	int x;
	int y;

	y = 0;
	while (y < GRID_SIZE)
	{
		x = 0;
		while (x < GRID_SIZE)
		{
			grid[y][x] = 0;
			x++;
		}
		y++;
	}
	return (grid);
}

int	**ft_make_grid(int **grid)
{
	int	size;

	size = GRID_SIZE;
	if (grid)
		free(grid);
	grid = ft_memalloc(sizeof(int *)* (size + 1));
	grid[size] = NULL;
	while (size)
	{
		size--;
		grid[size] = ft_memalloc(sizeof(int)* GRID_SIZE);
//		grid[size] = (int *)malloc(sizeof(int)* (GRID_SIZE));
	}
	return (grid);
}