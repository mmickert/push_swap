# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mickert <mickert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 11:22:16 by mickert           #+#    #+#              #
#    Updated: 2023/12/03 18:42:40 by mickert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
# -fsanitize=address
SRC = main.c parse.c parse_list.c swap.c push.c rotate.c rev_rotate.c sort_index.c stack.c sort.c
OBJ = $(SRC:.c=.o)
NAME = ./push_swap 
LIBFTDIR = ft_libft
LIBFT	= $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME):  $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -L$(LIBFTDIR) -lft $(OBJ) -o $@ 

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)
	make fclean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
