/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 19:03:58 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/21 21:44:53 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	**raw_2d;
	int		**grid;
	t_tetro	*struct_tetro;
	int		i;
	if (argc != 2)
		return (ft_error(0));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error(1));
//		printf("%d", fd);
	if (ft_checker1(fd) == 0)
		return (0);
// NO NEED TO CLOSE IT "MANUALLY" ??
// Side comment on this /\ seems like closing the file manually caused some problems
// and just opening the file again resetted the file offset which is what I tought close
// and reopen would do
//	if (close(fd) == -1)
//		return (ft_error(9));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error(1));
//	printf("%d", fd);
	if (ft_checker2(fd) == 0)
		return (0);
	printf("\033[01;33m=====================VALID=FILE=====================\033[0m\n");
//------------> SAVE THE SHAPES
	raw_2d = ft_file_save(fd, argv);
	struct_tetro = ft_process_raw(raw_2d);
	i = 0;
	while (raw_2d[i])
		i++;
	printf("nbr of tetros: %d\n", i);
	GRID_SIZE = ft_board_size(i);
//	testing of grid and move seems ok \/
	grid = ft_make_grid(grid);
	int x, y = 0;
	while (grid[y])
	{
		x = 0;
		while (x < GRID_SIZE)
		{
			ft_putnbr(grid[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_putchar('\n');
//	printf("(%d)", ft_move_coordinate(&struct_tetro, 4, 3, grid));
//	printf("tetri nr.1 (x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", struct_tetro->x[0], struct_tetro->y[0], struct_tetro->x[1], struct_tetro->y[1], struct_tetro->x[2], struct_tetro->y[2], struct_tetro->x[3], struct_tetro->y[3]);
//	grid = ft_flip_grid(struct_tetro, rid);
//	grid = ft_generate_answer(struct_tetro, grid);
//	while (struct_tetro->next)
//	{
//		ft_flip_grid(struct_tetro, grid);
//		struct_tetro = struct_tetro->next;
//	}
	printf("\nscore = %d\n", ft_judge_grid(grid));
	char **grid_abc;
//	ft_move_1(&struct_tetro->prev, grid);
	struct_tetro = ft_reset_coordinates(&struct_tetro, grid);
	printf("(%s)", struct_tetro->prev);
	while (struct_tetro)
	{
		ft_flip_grid(struct_tetro, grid);
		struct_tetro = struct_tetro->next;
	}
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (x < GRID_SIZE)
		{
			ft_putnbr(grid[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
//	grid_abc = ft_abc_grid(struct_tetro);
	y = 0;
/*	while (grid_abc[y])
	{
		x = 0;
		while (x < GRID_SIZE)
		{
			ft_putchar(grid_abc[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}*/
//------------> BOARD STARTING SIZE
// x_top = ft_board_size(i)
// y_top = ft_board_size(i)
//	printf("board starting size is: %dx%d\n", ft_board_size(i), ft_board_size(i));
//	printf("tetri nr.1 (x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", struct_tetro->x[0], struct_tetro->y[0], struct_tetro->x[1], struct_tetro->y[1], struct_tetro->x[2], struct_tetro->y[2], struct_tetro->x[3], struct_tetro->y[3]);
//	printf("(%d)", ft_move_coordinate(&struct_tetro, -2, 0));
//	printf("tetri after move (x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", struct_tetro->x[0], struct_tetro->y[0], struct_tetro->x[1], struct_tetro->y[1], struct_tetro->x[2], struct_tetro->y[2], struct_tetro->x[3], struct_tetro->y[3]);

//	ft_putnbr(struct_tetro->x[0]);
/*	while (struct_tetro)
	{
		ft_putchar('[');
		printf("tetri nr.1 (x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", struct_tetro->x[0], struct_tetro->y[0], struct_tetro->x[1], struct_tetro->y[1], struct_tetro->x[2], struct_tetro->y[2], struct_tetro->x[3], struct_tetro->y[3]);
		ft_putchar(']');
		struct_tetro = struct_tetro->next;
	}*/
//	ft_putnbr(struct_tetro->y[0]);
// -----------> NOW GO FOR SOLVER...
// board starting size = sqrt(# of tetrominoes * 4 characters per tetromino)
// TEST FOR LEAKS
//	while (1);
	return (0);
}
