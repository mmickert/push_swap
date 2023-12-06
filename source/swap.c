/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:29:01 by mickert           #+#    #+#             */
/*   Updated: 2023/12/06 15:53:56 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int i)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		first = *stack_a;
		second = (*stack_a)->next;
		first->next = second->next;
		second->next = first;
		*stack_a = second;
	}
	if (i != 42)
		ft_printf("sa\n");
}

void	sb(t_stack **stack_b, int i)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		first = *stack_b;
		second = (*stack_b)->next;
		first->next = second->next;
		second->next = first;
		*stack_b = second;
	}
	if (i != 42)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 42);
	sb(stack_b, 42);
	ft_printf("ss\n");
}
