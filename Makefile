CC = cc
CFLAGS = -Wall -Wextra -Werror -g
# CFLAGS = -fsanitize=address -Wunreachable-code

SRC = source/main.c source/parse.c source/parse_list.c source/swap.c source/push.c source/rotate.c \
      source/rev_rotate.c source/sort_index.c source/stack.c source/sort.c

ODIR = objectives
OBJ = $(SRC:source/%.c=$(ODIR)/%.o)

HEADER = ./includes/push_swap.h
NAME = ./push_swap

LIBFTDIR = ./source/ft_libft
LIBFT = $(LIBFTDIR)/libft.a
LIBFT_OBJDIR = $(LIBFTDIR)/objectives
INC = -I ./includes -I $(LIBFTDIR)/includes
VPATH = source source/ft_libft

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INC) -o $(NAME)

$(ODIR)/%.o: source/%.c $(HEADER) | $(ODIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(ODIR):
	@mkdir -p $@

$(LIBFT): | $(LIBFT_OBJDIR)
	$(MAKE) -C $(LIBFTDIR)

$(LIBFT_OBJDIR):
	@mkdir -p $@

clean:
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
