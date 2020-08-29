/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:47:05 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/28 21:24:29 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_side_len(t_tetro *tetro)
{
	return(ft_board_size(ft_tetro_count(tetro)));
}

int	**ft_flip_grid(t_tetro *tetro, int **grid)
{
	int	i;

	i = 0;
//-------------------------------------------------------------
	while (i < 4)
	{
		if (*(tetro->y + i) < 0 || *(tetro->x + i) < 0 || 
			*(tetro->y + i) >= ft_side_len(tetro) ||
			*(tetro->x + i) >= ft_side_len(tetro))
		{
			printf("\nWTF =! y = %d and x = %d letter = %c \n", *(tetro->y + i), *(tetro->x + i), 'A' + tetro->letter);
		}
		i++;
	}
	i = 0;
//-------------------------------------------------------------
	while (i < 4)
	{
		if (grid[tetro->y[i]][tetro->x[i]] == 0)
			grid[tetro->y[i]][tetro->x[i]] = 1;
		else
			grid[tetro->y[i]][tetro->x[i]] = 0;
		i++;
	}
	return (grid);
}

int	**ft_make_grid(int **grid, int size)
{
	int grid_size;

	grid_size = size;
	if (grid)
		free(grid);
	grid = ft_memalloc(sizeof(int *)* (grid_size + 1));
	grid[grid_size] = NULL;
	while (size)
	{
		size--;
		grid[size] = ft_memalloc(sizeof(int)* grid_size);
	}
	return (grid);
}
