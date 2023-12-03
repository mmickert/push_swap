/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:25:02 by mickert           #+#    #+#             */
/*   Updated: 2023/12/03 18:58:02 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b, int array_len)
{
	int	middle;

	middle = square(array_len);
	if (array_len == 2)
		sort_2(stack_a);
	if (array_len == 3)
		sort_3(stack_a);
	else if (array_len > 3)
	{
		if (already_sorted(*stack_a) == 0)
		{
			stackclear(stack_a);
			exit (0);
		}
		sort_more_to_b(stack_a, stack_b, middle);
		sort_more_to_a(stack_a, stack_b, array_len);
	}
}

void	sort_2(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, 0);
}

void	sort_3(t_stack **stack_a)
{
	while (!((*stack_a)->index == 1 && (*stack_a)->next->index == 2
			&& (*stack_a)->next->next->index == 3))
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a, 0);
		if ((*stack_a)->next->index > (*stack_a)->next->next->index)
			rra(stack_a, 0);
	}
}

void	sort_more_to_b(t_stack **stack_a, t_stack **stack_b, int middle)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= middle + i)
		{
			pb(stack_a, stack_b);
			i++;
			if (((*stack_b)->next) && (*stack_b)->index <= i)
				rb(stack_b, 0);
		}
		else
			ra(stack_a, 0);
	}
}

void	sort_more_to_a(t_stack **stack_a, t_stack **stack_b, int array_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*stack_b && ((*stack_b)->next != NULL))
	{
		if ((*stack_b)->index == array_len)
		{
			pa(stack_a, stack_b);
			i++;
			array_len--;
		}
		else
		{
			j = turning_way(*stack_b, array_len);
			if (j > array_len / 2)
				rrb(stack_b, 0);
			else
				rb(stack_b, 0);
		}
	}
	pa(stack_a, stack_b);
}

	// print_stack_a(stack_a);
	// print_stack_b(stack_b);
