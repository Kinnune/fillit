/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:31:13 by jraty             #+#    #+#             */
/*   Updated: 2020/09/03 00:45:24 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_fill_abc(t_tetro *tetro, char **grid, int sz, int gs)
{
	int i;

	while (tetro)
	{
		i = 0;
		while (i < 4)
		{
			grid[tetro->y[i]][tetro->x[i]] = 'A' + tetro->letter;
			i++;
		}
		tetro = tetro->next;
	}
	while (grid[sz])
	{
		i = 0;
		while (i < gs)
		{
			if (!grid[sz][i])
				grid[sz][i] = '.';
			i++;
		}
		sz++;
	}
	return (grid);
}

char	**ft_abc_grid(t_tetro *tetro, int grid_size)
{
	int		size;
	char	**grid;

	size = grid_size;
	grid = ft_memalloc(sizeof(char *) * (size + 1));
	grid[size] = NULL;
	while (size)
	{
		size--;
		grid[size] = ft_strnew(grid_size);
	}
	return (ft_fill_abc(tetro, grid, size, grid_size));
}

void	ft_print_grid_abc(t_tetro *struct_tetro, int grid_size)
{
	int		y;
	int		x;
	char	**grid_abc;

	y = 0;
	grid_abc = ft_abc_grid(struct_tetro, grid_size);
	while (grid_abc[y])
	{
		x = 0;
		while (x < grid_size)
		{
			ft_putchar(grid_abc[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
