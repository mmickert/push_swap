# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mickert <mickert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 11:22:16 by mickert           #+#    #+#              #
#    Updated: 2023/11/13 13:26:12 by mickert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
SRC = main.c 
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
