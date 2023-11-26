/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:23:06 by mickert           #+#    #+#             */
/*   Updated: 2023/11/26 14:19:09 by mickert          ###   ########.fr       */
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

int		main(int argc, char *argv[]);
int		parse(int argc, char **argv, t_list **stack_a, int index);
int		ft_atoi_push_swap(const char *str);
int		check(char *str, t_list **stack_a);
void	custom_del(void *content);
void	free_input_numbers(char **input_numbers);
int		has_duplicate(t_list *stack_a, int new_number);
t_list	*ft_pslstnew(void *c);
int		put_in_array_stack(char **input_numbers, t_list **stack_a, int i);
void	sa(t_list **stack_a, int i);
void	sb(t_list **stack_b, int i);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a, int i);
void	rb(t_list **stack_b, int i);
void	rr(t_list **stack_b, t_list **stack_a);
void	rrb(t_list **stack_b);

void	print_stack_a(t_list **stack_a);
void	print_stack_b(t_list **stack_b);

#endif