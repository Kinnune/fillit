/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:31:53 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/20 19:31:53 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//	11 lines to shave
char **ft_abc_grid(t_tetro *tetro, int grid_size)
{
	int	size;
	char **grid;
	int	i;

	i = 0;
	size = grid_size;
	grid = ft_memalloc(sizeof(char *)* (size + 1));
	grid[size] = NULL;
	while (size)
	{
		size--;
		grid[size] = ft_strnew(grid_size);
	}
	while (tetro)
	{
		while (i < 4)
		{
			grid[tetro->y[i]][tetro->x[i]] = 'A' + tetro->letter;
			i++;
		}
		i = 0;
		tetro = tetro->next;
	}
	size = 0;
	while (grid[size])
	{
		i = 0;
		while (i < grid_size)
		{
			if (!grid[size][i])
				grid[size][i] = '.';
			i++;
		}
		size++;
	}
	return (grid);
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
