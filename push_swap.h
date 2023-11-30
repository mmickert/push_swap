/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:23:06 by mickert           #+#    #+#             */
/*   Updated: 2023/11/30 15:52:25 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}				t_stack;

int		main(int argc, char *argv[]);
int		parse(int argc, char **argv, t_stack **stack_a, int i);
t_stack	*stacknew(int c);
void	stackadd_back(t_stack **lst, t_stack *new);
t_stack	*stacklast(t_stack *lst);
void	stackclear(t_stack **lst);
int		ft_atoi_push_swap(const char *str);
int		check(char *str, t_stack **stack_a);
void	free_input_numbers(char **input_numbers);
int		has_duplicate(t_stack **stack_a);
int		put_in_array_stack(char **input_numbers, t_stack **stack_a, int i);
void	sa(t_stack **stack_a, int i);
void	sb(t_stack **stack_b, int i);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a, int i);
void	rb(t_stack **stack_b, int i);
void	rr(t_stack **stack_b, t_stack **stack_a);
void	rra(t_stack **stack_a, int i);
void	rrb(t_stack **stack_b, int i);
void	rrr(t_stack **stack_b, t_stack **stack_a);
int		*sort_index(int *array_numbers, int array_len);

void	print_stack_a(t_stack **stack_a);
void	print_stack_b(t_stack **stack_b);

#endif