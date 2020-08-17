/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:30:12 by jraty             #+#    #+#             */
/*   Updated: 2020/08/17 20:07:38 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"
#include <fcntl.h>

//
#include <stdio.h>
//

# define BUF_SIZE 21

typedef	struct		s_tetro
{
	char			*raw;
	int				letter;
	int				x_top;
	int				y_top;
	int				x[4];
	int				y[4];
	struct s_tetro	*next;
	struct s_tetro	*prev;
}					t_tetro;

int		ft_error(int n);

int		ft_checker1(int fd);

int		ft_checker2(int fd);

char	**ft_file_save(int fd, char **argv);

char	**ft_single_shapes(char *f_content);

size_t	ft_file_size(int fd);

t_tetro	*ft_process_raw(char **raw);


#endif
