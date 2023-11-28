/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:22:10 by mickert           #+#    #+#             */
/*   Updated: 2023/11/28 15:13:09 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (parse(argc, argv, &stack_a, i) == 1)
	{
		system("leaks push_swap");
		return (1);
	}
	system("leaks push_swap");
	print_stack_a(&stack_a);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	int		index;

// 	index = 1;
// 	stack_a = NULL;
// 	stack_b = NULL;
// 	if (parse(argc, argv, &stack_a, index) == 1)
// 	{
// 		system("leaks push_swap");
// 		return (1);
// 	}
// 	// print_stack_a(&stack_a);
// 	// print_stack_b(&stack_b);
// 	// ra(&stack_a, 0);
// 	print_stack_a(&stack_a);
// 	print_stack_b(&stack_b);
// 	pb(&stack_a, &stack_b);
// 	pb(&stack_a, &stack_b);
// 	pb(&stack_a, &stack_b);
// 	pb(&stack_a, &stack_b);
// 	print_stack_a(&stack_a);
// 	print_stack_b(&stack_b);
// 	// sa(&stack_a, 0);
// 	// print_stack_a(&stack_a);
// 	// print_stack_b(&stack_b);
// 	// ss(&stack_a, &stack_b);
// 	// print_stack_a(&stack_a);
// 	// print_stack_b(&stack_b);
// 	rrb(&stack_b, 0);
// 	print_stack_a(&stack_a);
// 	print_stack_b(&stack_b);
// 	rrr(&stack_b, &stack_a);
// 	print_stack_a(&stack_a);
// 	print_stack_b(&stack_b);
// 	rra(&stack_a, 0);
// 	print_stack_a(&stack_a);
// 	print_stack_b(&stack_b);
// 	return (0);
// }

void	print_stack_a(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp)
	{
		ft_printf("stack a: %d\n", temp->content);
		temp = temp->next;
	}
}

void	print_stack_b(t_stack **stack_b)
{
	t_stack	*temp;

	temp = *stack_b;
	while (temp)
	{
		ft_printf("stack_b: %d\n", temp->content);
		temp = temp->next;
	}
}
