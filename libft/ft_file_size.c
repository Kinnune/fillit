/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 18:01:29 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/28 18:01:29 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_file_size(int fd)
{
	size_t	read_ret;
	size_t	size;
	char	buffer[BUFF_SIZE];

	size = 0;
	read_ret = 0;
	while ((read_ret = read(fd, buffer, BUFF_SIZE)) > 0)
			size += read_ret;
	return (size);
}