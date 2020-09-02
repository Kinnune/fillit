/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_shorteners.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:38:33 by jraty             #+#    #+#             */
/*   Updated: 2020/09/03 00:41:05 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tetro_next(t_tetro **tetro, int *x, int *y)
{
	*tetro = (*tetro)->next;
	*x = 0;
	*y = 0;
}

void	ft_grid_bigger(int *grid_size, int *x, int *y)
{
	*x = 0;
	*y = 0;
	*grid_size += 1;
}

void	ft_tetro_prev(t_tetro **tetro, int *x, int *y)
{
	*tetro = (*tetro)->prev;
	*x = *(*tetro)->x + 1;
	*y = *(*tetro)->y;
}

void	ft_start_new_line(int *x, int *y)
{
	*y += 1;
	*x = 0;
}
