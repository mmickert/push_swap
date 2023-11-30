/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:47:06 by mickert           #+#    #+#             */
/*   Updated: 2023/11/30 15:55:43 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, int i)
{
	t_stack	*last;
	t_stack	*temp;
	t_stack	*first;

	if (stack_a && (*stack_a) && (*stack_a)->next)
	{
		first = *stack_a;
		last = *stack_a;
		while (last->next)
			last = last->next;
		temp = first;
		*stack_a = first->next;
		last->next = temp;
		first->next = NULL;
	}
	if (i != 42)
		ft_printf("ra\n");
}

void	rb(t_stack **stack_b, int i)
{
	t_stack	*last;
	t_stack	*temp;
	t_stack	*first;

	if (stack_b && (*stack_b) && (*stack_b)->next)
	{
		first = *stack_b;
		last = *stack_b;
		while (last->next)
			last = last->next;
		temp = first;
		*stack_b = first->next;
		last->next = temp;
		first->next = NULL;
	}
	if (i != 42)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_b, t_stack **stack_a)
{
	ra(stack_a, 42);
	rb(stack_b, 42);
	ft_printf("rr\n");
}
