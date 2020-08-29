/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:30:12 by jraty             #+#    #+#             */
/*   Updated: 2020/08/28 21:04:56 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "../libft/libft.h"
#include <fcntl.h>

//
#include <stdio.h>
//

# define BUF_SIZE 21


typedef	struct		s_tetro
{
	char			*raw;
	int				letter;
	int				x[4];
	int				y[4];
	struct s_tetro	*next;
	struct s_tetro	*prev;
}					t_tetro;

//int		ft_safe_move(t_tetro **tetro, int x_max, int y_max, int x, int y);

void	ft_recursive(t_tetro **s_tetro, int **grid, int grid_size);

int		ft_side_len(t_tetro *tetro);

size_t	ft_tetro_count(t_tetro *struct_tetro);

size_t	ft_check_connect(size_t i, char *buf, int *hash, int *conn);

int		ft_judge_grid(int **grid);

int		**ft_flip_grid(t_tetro *tetro, int **grid);

int		**ft_make_grid(int **grid, int size);

void	ft_print_grid(int **grid);

void	ft_print_grid_abc(t_tetro *struct_tetro, int grid_size);

char	**ft_abc_grid(t_tetro *list, int grid_size);

int		**ft_generate_answer(t_tetro *s_tetro, int **grid);

int		ft_board_size(int nb);

int		ft_move_1(t_tetro **tetro, int **grid, int size);

t_tetro	*ft_reset_coordinates(t_tetro **tetro, int **grid);

int		ft_validate_coordinate(t_tetro *tetro, int **grid, int grid_size);

void	ft_move_coordinate(t_tetro **tetro, int x, int y, int **grid);

int		ft_usage(void);

int		ft_checker1(int fd);

int		ft_checker2(int fd);

char	**ft_file_save(int fd, char **argv);

char	**ft_single_shapes(char *f_content);

t_tetro	*ft_process_raw(char **raw);

t_tetro	*ft_new_tetro(char *tetro_string, t_tetro *previous, int i);


#endif
