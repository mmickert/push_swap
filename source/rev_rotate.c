/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:46:16 by mickert           #+#    #+#             */
/*   Updated: 2023/12/06 15:53:33 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, int i)
{
	t_stack	*last;
	t_stack	*second_last;

	if (stack_a && (*stack_a) && (*stack_a)->next)
	{
		second_last = *stack_a;
		while (second_last->next->next)
			second_last = second_last->next;
		last = second_last->next;
		second_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
	}
	if (i != 42)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, int i)
{
	t_stack	*last;
	t_stack	*second_last;

	if (stack_b && (*stack_b) && (*stack_b)->next)
	{
		second_last = *stack_b;
		while (second_last->next->next)
			second_last = second_last->next;
		last = second_last->next;
		second_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
	}
	if (i != 42)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_b, t_stack **stack_a)
{
	rra(stack_a, 42);
	rrb(stack_b, 42);
	ft_printf("rrr\n");
}
