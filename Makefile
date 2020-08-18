# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 16:20:49 by jraty             #+#    #+#              #
#    Updated: 2020/08/18 12:51:12 by jraty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.exe

SRCS = tetri_validator.c shape_makers.c struct_processing.c

OBJS = $(SRCS:.c=.o)

LIB = libft

HDRS = $(LIB)libft.h $(LIB)get_next_line.h

GCH = $(HDRS:.h=.h.gch)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIB) re
	@make -C $(LIB) clean
	@gcc -o $(NAME) $(SRCS) -I $(LIB) -L $(LIB) -lft

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -f $(GCH)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(GCH)

re: fclean all
