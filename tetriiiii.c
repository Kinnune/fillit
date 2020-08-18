/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriiiii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:32:56 by jraty             #+#    #+#             */
/*   Updated: 2020/08/18 17:01:55 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(int n)
{
	printf("\033[01;31m\n=====================NOT=VALID======================\033[0m\n");
	if (n == 0)
		printf("\033[31musage: ./fillit target_file\033[0m\n");
	if (n == 1)
		printf("\033[31mopen() failed.\033[0m\n");
	if (n == 2)
		printf("\033[31mline lentgh 'x' not 4\033[0m\n");
	if (n == 3)
		printf("\033[31mline count 'y' not 4\033[0m\n");
	if (n == 4)
		printf("\033[31mwrong characters\033[0m\n");
	if (n == 6)
		printf("\033[31mwrong amount of hashes\033[0m\n");
	if (n == 7)
		printf("\033[31mhashes don't join\033[0m\n");
	if (n == 8)
		printf("\033[31mdoesn't end with a single newline.\033[0m\n");
	if (n == 9)
		printf("\033[31mclose() failed.\033[0m\n");
	return (0);
}

// GET BOARD SIZE (sq x sq)
int		ft_board_size(int nb)
{
	int		sq;

	nb *= 4;
	if (nb == 0 || nb == 1)
		return (nb);
	sq = 1;
	while ((sq * sq) <= nb)
	{
		if ((sq * sq) == nb)
			return (sq);
		sq += 1;
	}
	return (sq);
}

// CHECKER 1

int		ft_checker1(int fd)
{
	char	*line;
	size_t	i;
	size_t	l;
	
	l = 0;
	while (get_next_line(fd, &line) == 1)
	{
		l++;
		printf("%s\tline [%zu]", line, l);
		if (!(*line))
		{
			if (l % 5 != 0)
				return (ft_error(3));
		}
		else
		{
			if (ft_strlen(line) == 4)
				printf("\t\033[32mlength OK\033[0m");
			else
				return (ft_error(2));
			i = 0;
			while (line[i])
			{
				if (line[i] != '.' && line[i] != '#')
					return (ft_error(4));
				i++;
			}
			if (i == ft_strlen(line))
				printf("\t\033[32mdotorhash OK\033[0m");
		}
		free(line);
		printf("\n");
	}
	if ((l + 1) % 5 != 0)
		return (ft_error(8));
	return (1);
}

// CHECKER 2 (READ IT AGAIN && BUF_SIZE NEEDS TO BE 21!)
//#undef BUF_SIZE
//#define BUF_SIZE 21

int		ft_checker2(int fd)
{
	char	buf[BUF_SIZE + 1];
	int		ret;
	int		hash;
	int		conn;
	size_t	i;

	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		i = 0;
		hash = 0;
		conn = 0;
		while (buf[i])
		{
			if (buf[i] == '#')
			{
				if (buf[i - 5] == '#')
					conn++;
				if (buf[i + 5] == '#')
					conn++;
				if (buf[i + 1] == '#')
					conn++;
				if (buf[i - 1] == '#')
					conn++;
				hash++;
			}
			i++;
		}
		if (hash != 4)
			return (ft_error(6));
	}
	if (!(buf[i - 1] == 10 && buf[i] == 0))
		return (ft_error(8));
	if (conn != 6 && conn != 8)
		return (ft_error(7));
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**raw_2d;
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
//------------> BOARD STARTING SIZE
// x_top = ft_board_size(i)
// y_top = ft_board_size(i)
	printf("board starting size is: %dx%d\n", ft_board_size(i), ft_board_size(i));
	printf("tetri nr.1 (x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", struct_tetro->x[0], struct_tetro->y[0], struct_tetro->x[1], struct_tetro->y[1], struct_tetro->x[2], struct_tetro->y[2], struct_tetro->x[3], struct_tetro->y[3]);
	printf("(%d)", ft_move_coordinate(&struct_tetro, -2, 0));
	printf("tetri after move (x,y):\n%d,%d\t%d,%d\t%d,%d\t%d,%d\n", struct_tetro->x[0], struct_tetro->y[0], struct_tetro->x[1], struct_tetro->y[1], struct_tetro->x[2], struct_tetro->y[2], struct_tetro->x[3], struct_tetro->y[3]);

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
