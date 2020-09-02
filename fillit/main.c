/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 15:53:15 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/29 15:53:19 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <time.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		**grid;
	int		grid_size;
	t_tetro	*struct_tetro;
	t_tetro *head;

	grid = NULL;
	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if (ft_checker1(fd) == 0)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if (ft_checker2(fd) == 0)
		return (0);
	struct_tetro = ft_process_raw(ft_file_save(fd, argv));
	head = struct_tetro;
	grid_size = ft_board_size(ft_tetro_count(struct_tetro));
	grid = ft_bool_2d(grid, 64);
	grid_size = ft_iterative_solve(&struct_tetro, grid, grid_size);
	ft_print_grid_abc(head, grid_size);
	return (0);
}
