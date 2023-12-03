/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:22:10 by mickert           #+#    #+#             */
/*   Updated: 2023/12/03 14:04:16 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		array_len;

	stack_a = NULL;
	stack_b = NULL;
	array_len = 0;
	array_len = parse(argc, argv, &stack_a, array_len);
	has_duplicate(&stack_a);
	sort(&stack_a, &stack_b, array_len);
	return (0);
}

int	square(int array_len)
{
	int	i;

	i = 0;
	while (i * i < array_len)
		i++;
	return (i - 1);
}

int	turning_way(t_stack *stack_b, int array_len)
{
	int	j;

	j = 0;
	while (stack_b)
	{
		if (stack_b->index == array_len)
			return (j);
		stack_b = stack_b->next;
		j++;
	}
	return (-1);
}

//system("leaks push_swap");

// void	print_stack_a(t_stack **stack_a)
// {
// 	t_stack	*temp;

// 	temp = *stack_a;
// 	while (temp)
// 	{
// 		ft_printf("stack a index %d, value %d\n", temp->index, temp->content);
// 		temp = temp->next;
// 	}
// }

// void	print_stack_b(t_stack **stack_b)
// {
// 	t_stack	*temp;

// 	temp = *stack_b;
// 	while (temp)
// 	{
// 		ft_printf("stack b index %d, value %d\n", temp->index, temp->content);
// 		temp = temp->next;
// 	}
// }