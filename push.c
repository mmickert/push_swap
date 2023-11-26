/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:46:29 by mickert           #+#    #+#             */
/*   Updated: 2023/11/25 15:05:50 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		if (*stack_a == NULL)
		{
			*stack_a = temp;
			(*stack_a)->next = NULL;
		}
		else
		{
			temp->next = *stack_a;
			*stack_a = temp;
		}
		ft_printf("pa\n");
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		if (*stack_b == NULL)
		{
			*stack_b = temp;
			(*stack_b)->next = NULL;
		}
		else
		{
			temp->next = *stack_b;
			*stack_b = temp;
		}
		ft_printf("pb\n");
	}
}