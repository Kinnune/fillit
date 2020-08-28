/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:46:37 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/28 12:49:01 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		return (0);
	}
	return (1);
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

int	ft_move_1(t_tetro **tetro, int **grid)
{
	int x_origin;
	int y_origin;
	int	line;
	int x_place;

	x_place = x_origin;
	x_origin = *(*tetro)->x;
	y_origin = *(*tetro)->y;
	while (*(*tetro)->y <= GRID_SIZE)
	{
		ft_move_coordinate(tetro, *(*tetro)->x + 1, (*tetro)->y[0], grid);
		if (ft_validate_coordinate(*tetro, grid))
		{
			return (1);
		}
		if (*(*tetro)->x >= GRID_SIZE)
		{
			ft_move_coordinate(tetro, 0, (*tetro)->y[0] + 1, grid);
			if (ft_validate_coordinate(*tetro, grid))
			{
				return (1);
			}
		}
	}
	return (0);
}

int i = 0;

void	ft_recursive(t_tetro **tetro, int **grid)
{
//printf("(%c)", 'A' + (*tetro)->letter);
	if (!(*tetro)->next && ft_validate_coordinate(*tetro, grid))
		return ;
	ft_move_1(tetro, grid);
	if (ft_validate_coordinate(*tetro, grid))
	{
		ft_flip_grid(*tetro, grid);
		if ((*tetro)->next)
			ft_recursive(&(*tetro)->next, grid);
	}
	else if ((*tetro)->prev)
	{
		ft_move_coordinate(tetro, -1, 0, grid);
		ft_flip_grid((*tetro)->prev, grid);
		ft_recursive(&(*tetro)->prev, grid);
	}
	else if (*(*tetro)->y >= GRID_SIZE)
	{
//ft_putstr("BIGGER!\n");
		grid = ft_make_grid(grid, ++GRID_SIZE);
		ft_move_coordinate(tetro, -1, 0, grid);
		ft_recursive(tetro, grid);

	}
	
	

}
/*
void	ft_recursive(t_tetro **tetro, int **grid)
{
printf("%c (%d)\n", 'A' + (*tetro)->letter, i++);
	while (!ft_validate_coordinate(*tetro, grid) && *(*tetro)->y < GRID_SIZE)
	{
		ft_move_1(tetro, grid);
	}
	if (!(*tetro)->prev && *(*tetro)->y >= GRID_SIZE)
	{
ft_print_grid(grid);
ft_putstr("bigger!\n");
		ft_move_coordinate(tetro, 0, 0, grid);
		grid = ft_make_grid(grid, ++GRID_SIZE);
		ft_recursive(tetro, grid);
	}
	else if (ft_validate_coordinate(*tetro, grid))
	{
//ft_putstr("forward\n");
		ft_flip_grid(*tetro, grid);
		if ((*tetro)->next)
			ft_recursive(&(*tetro)->next, grid);
	}
	else if ((*tetro)->prev)
	{
//ft_putstr("back\n");
		ft_move_coordinate(tetro, 0, 0, grid);
		tetro = &(*tetro)->prev;
		ft_flip_grid(*tetro, grid);
		if (ft_move_1(tetro, grid))
		{
			ft_flip_grid(*tetro, grid);

			ft_recursive(&(*tetro)->next, grid);
		}
		else
		{
			ft_flip_grid((*tetro)->prev, grid);
			ft_recursive(&(*tetro)->prev, grid);
		}
	}

}


void	ft_recursive(t_tetro **tetro, int **grid)
{
	if (ft_validate_coordinate(*tetro, grid))
	{
		ft_flip_grid(*tetro, grid);
		if ((*tetro)->next)
		{
			ft_recursive(&(*tetro)->next, grid);
			return ;
		}
	}
	else if (*(*tetro)->y < GRID_SIZE || (*tetro)->prev)
	{
		if (ft_move_1(tetro, grid))
		{
			ft_recursive(tetro, grid);
			return ;
		}
		else
		{
			ft_move_coordinate(tetro, 0, 0, grid);
			ft_flip_grid((*tetro)->prev, grid);
			ft_move_1(&(*tetro)->prev, grid);
			ft_recursive(&(*tetro)->prev, grid);
			return ;
		}
	}
	else 
	{
ft_putstr("bigger!\n");
		grid = ft_make_grid(grid, ++GRID_SIZE);
		ft_move_coordinate(tetro, 0, 0, grid);
		ft_recursive(tetro, grid);
		return ;
	}	

}


int	ft_recursive(t_tetro **s_tetro, int **grid)
{
	static int n = 0;
	static int	loop = 1;
	static int	palikka = 1;

	printf("\033[33mrundi %d ---------------------------------------------- \033[0m\n", loop++);
	n++;
	if (!ft_validate_coordinate(*s_tetro, grid) && *(*s_tetro)->y < GRID_SIZE)
	{
		printf("\033[01;36mpalikkaa %d liikutellaan gridin sisalla, kunnes validi\033[0m\n", palikka);
		ft_move_1(s_tetro, grid);
	}
	printf("GRID_SIZE on: %dx%d\n", GRID_SIZE, GRID_SIZE);
	if (*(*s_tetro)->y >= GRID_SIZE && !(*s_tetro)->prev)
	{
		GRID_SIZE++;
		printf("\033[01;35mgrid made bigger (now %dx%d)\033[0m\n", GRID_SIZE, GRID_SIZE);
		grid = ft_make_grid(grid, GRID_SIZE);
		*s_tetro = ft_reset_coordinates(s_tetro, grid);
		palikka = 1;
		ft_recursive(s_tetro, grid);
	}
	else if (*(*s_tetro)->y >= GRID_SIZE)
	{
		printf("\033[01;31mpalikka %d meni yli [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
		ft_flip_grid((*s_tetro)->prev, grid);
		if (ft_move_1(&(*s_tetro)->prev, grid))
		{
			printf("\033[01;32mpalikan %d liikuttaminen onnistui [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka -1, (*s_tetro)->prev->x[0], (*s_tetro)->prev->y[0], (*s_tetro)->prev->x[1], (*s_tetro)->prev->y[1], (*s_tetro)->prev->x[2], (*s_tetro)->prev->y[2], (*s_tetro)->prev->x[3], (*s_tetro)->prev->y[3]);
			ft_flip_grid((*s_tetro)->prev, grid);
			ft_move_coordinate(s_tetro, 0, 0, grid);
			ft_recursive(s_tetro, grid);
		}
		else
		{
			printf("\033[01;31mpalikkaa %d ei voi liikuttaa... [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka -1, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
			ft_move_coordinate(s_tetro, 0, 0, grid);
			palikka--;
			ft_recursive(&(*s_tetro)->prev, grid);
		}
	}
	else if ((*s_tetro)->next)
	{
		printf("\033[01;32mpalikka %d osui kohdalleen [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka++, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
		if ((*s_tetro)->next)
		{
			printf("seuraava palikka on olemassa\n");
		}
		ft_flip_grid((*s_tetro), grid);
		ft_recursive(&(*s_tetro)->next, grid);
	}
	else
//	if (!(*s_tetro)->next)
//	{
//		ft_puterr(6);
//		printf("\033[01;32mvika palikka %d osui kohdalleen\033[0m\n", palikka);
//		printf("taa oli vika palikka\n");
//		return (n);
//	}
//	ft_puterr(8);
	printf("\033[01;32mvika palikka %d osui kohtaan [%d,%d] [%d,%d] [%d,%d] [%d,%d]\033[0m\n", palikka++, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
//	write(1, "ei mee mihkaan looppiin\n", 24);
//	exit (0);
	return (n);
}

void	ft_recursive(t_tetro **s_tetro, int **grid)
{
printf("Tetri nr.%d (x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", (*s_tetro)->letter, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
ft_print_grid(grid);
	if (*(*s_tetro)->y < GRID_SIZE)
	{
		if (ft_validate_coordinate(*s_tetro, grid))
		{
			ft_flip_grid(*s_tetro, grid);
			if (!(*s_tetro)->next)
				return ;
			ft_recursive(&(*s_tetro)->next, grid);
		}
		else
		{
			ft_move_1(s_tetro, grid);
			ft_recursive(s_tetro, grid);
		}
	}
	else
	{
		if ((*s_tetro)->letter != 0)
		{
			ft_flip_grid((*s_tetro)->prev, grid);
			ft_move_coordinate(s_tetro, 0, 0, grid);
			ft_recursive(&(*s_tetro)->prev, grid);
		}
		else
		{
			ft_reset_coordinates(s_tetro, grid);
			grid = ft_make_grid(grid, ++GRID_SIZE);
			ft_recursive(s_tetro, grid);
		}
	}
}

void	ft_recursive(t_tetro **s_tetro, int **grid)
{
printf("Tetri nr.%d (x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", (*s_tetro)->letter, (*s_tetro)->x[0], (*s_tetro)->y[0], (*s_tetro)->x[1], (*s_tetro)->y[1], (*s_tetro)->x[2], (*s_tetro)->y[2], (*s_tetro)->x[3], (*s_tetro)->y[3]);
ft_print_grid(grid);
	if (ft_validate_coordinate(*s_tetro, grid))
	{
		ft_flip_grid(*s_tetro, grid);
		if (!(*s_tetro)->next)
			return ;
		ft_recursive(&(*s_tetro)->next, grid);
	}
	else if (*(*s_tetro)->y < GRID_SIZE)
	{
		ft_move_1(s_tetro, grid);
		ft_recursive(s_tetro, grid);
	}
	else if ((*s_tetro)->prev)
	{
		ft_flip_grid((*s_tetro)->prev, grid);
		ft_move_coordinate(s_tetro, 0, 0, grid);
		ft_recursive(&(*s_tetro)->prev, grid);
	}
	else
	{
		ft_reset_coordinates(s_tetro, grid);
		grid = ft_make_grid(grid, ++GRID_SIZE);
		ft_recursive(s_tetro, grid);
	}
}


void	ft_recursive(t_tetro **s_tetro, int **grid)
{
	
//ft_putstr((*s_tetro)->raw);
	while (!ft_validate_coordinate(*s_tetro, grid) && *(*s_tetro)->y < GRID_SIZE)
	{
		ft_move_1(s_tetro, grid);
	}
	if (*(*s_tetro)->y >= GRID_SIZE)
	{
		if ((*s_tetro)->prev)
			ft_flip_grid((*s_tetro)->prev, grid);
		if((*s_tetro)->letter == 0)
		{
			grid = ft_make_grid(grid, ++ GRID_SIZE);
			ft_reset_coordinates(s_tetro, grid);
			ft_recursive(s_tetro, grid);
		}
		else if (ft_move_1(&(*s_tetro)->prev, grid))
		{
			ft_flip_grid((*s_tetro)->prev, grid);
			ft_move_coordinate(s_tetro, 0, 0, grid);
			ft_recursive(s_tetro, grid);
		}
		else
		{
			ft_move_coordinate(s_tetro, 0, 0, grid);
			ft_recursive(&(*s_tetro)->prev, grid);
		}
	}
	else if ((*s_tetro)->next)
	{
		ft_flip_grid((*s_tetro), grid);
		ft_recursive(&(*s_tetro)->next, grid);
	}

}

*/