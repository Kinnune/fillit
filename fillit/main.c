/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:10:52 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/28 13:10:52 by ekinnune         ###   ########.fr       */
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
	grid_size = ft_side_len(struct_tetro);
printf("(%d)", grid_size);
	grid = ft_make_grid(grid, grid_size);
	struct_tetro = ft_reset_coordinates(&struct_tetro, grid);
	ft_recursive(&struct_tetro, grid, grid_size);
	ft_print_grid_abc(struct_tetro, grid_size);
	return (0);
}
